// SalarySys.cpp
#include<ctime>
#include<string>
#include<iostream>
#include<fstream>
#include<climits>

using namespace std;

// 枚举员工的级别
enum EmpLevel
{
    enumOfficer = 1,    // 高级员工
    enumStaff = 2       // 一般员工
};

// 员工类
class Employee
{
public:
    // 构造函数，根据员工的姓名和入职年份构造对象
    Employee(string strName, int nY)
        : m_strName(strName), m_nYear(nY)   // 设定员工的姓名和入职年份
    {}

// Employee类的行为，这些行为都是供外界调用的接口
// 所以将其访问级别设定为public
public:
    // 获得员工姓名
    string GetName() const
    {
        return m_strName;
    }
    // 获得员工入职年份
    int GetYear() const
    {
        return m_nYear;
    }
    // 获得员工级别
    EmpLevel GetLevel() const
    {
        return m_nLevel;
    }
    // 获得员工工资，因为这个行为同员工类相关，
    // 不同的派生类有不同的行为，所以在基类Employee中只是
    // 用纯虚函数表示接口，具体行为由其派生类实现
    virtual int GetSalary() = 0; // =0 纯虚函数

// GetWorkTime()只是供自身和自己的派生类调用，所以将其
// 访问级别设定为protected
protected:
    // 获得在职时间，即现在年份减去入职年份
    int GetWorkTime() const
    {
        // 获得现在的年份
        time_t t = time(0);
        struct tm* now = localtime(&t);
        // time()函数获得的时间是以1900年为起点，所以这里需要
        // 加上1900。同时，不满一年按一年计算，所以最好要加1
        return now->tm_year + 1900 - m_nYear + 1;
    }
// Employee类的属性
// 因为这些属性也同样应当是其派生类具有的，需要由基类遗传给
// 它的派生类，所以这里使用protected访问级别
protected:
    string m_strName;   // 姓名
    int m_nYear;        // 入职年份
    EmpLevel m_nLevel;  // 级别
};

// 高级员工类
class Officer : public Employee
{
public:
    // 构造函数
    // 直接调用基类构造函数，完成相同部分属性的构建
    Officer(string strName, int nY)
        : Employee(strName, nY)
    {
        // 派生类独有构建工作，设定员工的特定级别
        m_nLevel = enumOfficer;
    }
public:
    // 对基类的纯虚函数进行重写，具体实现员工计算工资行为
    virtual int GetSalary() override
    {
        // 对于高级员工，每年涨5000元工资
        return GetWorkTime()*5000;
    }
};

// 普通员工类
class Staff : public Employee
{
public:
    Staff(string strName, int nY)
        : Employee(strName, nY)
    {
        m_nLevel = enumStaff;
    }
public:
    virtual int GetSalary() override
    {
        return GetWorkTime()*1000;
    }
};

// 定义SalarySys中数组的最大处理量
const int MAX = 100000;

// 工资管理类SalarySys
class SalarySys
{
public:
    SalarySys()
        :m_nCount(0), // 设定当前数据量为0
         m_strFileName("SalaryData.txt") // 设定员工数据文件名
    {
        // 对数组进行初始化，使得数组中都是nullptr
        for(long i = 0; i < MAX; i++)
        {
            m_arrEmp[i] = nullptr;
        }

        // 读取员工数据文件
        Read();
    }

    ~SalarySys()
    {
        // 将员工数据写入文件，以备下次读取
        Write();
        // 释放数组中已经创建的员工对象
        for(long i=0; i<m_nCount; i++)
        {
            delete m_arrEmp[i];
            m_arrEmp[i] = nullptr;
        }
    }
// SalarySys的公有行为
public:
    // 从员工数据文件读取已经输入的数据
    int Read()
    {
        // 用于文件读取的中间临时变量
        string strName = "";
        int nLevel = 0;
        int nYear = 0;

        // 读取的数据个数
        int i = 0;
        // 打开数据文件
        ifstream in(m_strFileName);
        if(in.is_open())
        {
            while(true)
            {
                in>>strName>>nLevel>>nYear;

                if(!in)
                    break;

                // 根据读取内容创建不同员工对象，并保存到m_arrEmp数组进行管理
                if(enumOfficer == nLevel)
                {
                    m_arrEmp[i] = new Officer(strName, nYear);
                    ++i;
                }
                else if(enumStaff == nLevel)
                {
                    m_arrEmp[i] = new Staff(strName, nYear);
                    ++i;
                }

                if(i >= MAX)
                    break;
            }
            in.close();
        }
        cout<<"已读取"<<i<<"个员工数据"<<endl;
        m_nCount = i;

        return i;
    }

    void Write()
    {
        // 打开数据文件作为输出
        ofstream o(m_strFileName);
        if(o.is_open())
        {
            for(int i =0; i<m_nCount; i++)
            {
                Employee* p = m_arrEmp[i];
                o<<p->GetName()<<"\t"
                    <<p->GetLevel()<<"\t"
                    <<p->GetYear()<<endl;
            }
            o.close();
        }
    }

    int Input()
    {
        cout<<"请输入员工信息（名字 级别（1-一般员工，2-高级员工） 入职年份），例如 zhangsan 1 2000"<<endl;
        cout<<"-1表示输入结束"<<endl;

        int i = m_nCount;
        for(;i<MAX;i++)
        {
            cout<<"请输入"<<i<<"号员工的信息："<<endl;
            string strName = "";
            int nL = 0;
            int nY = 0;

            cin>>strName>>nL>>nY;

            if(!cin)
            {
                cout<<"输入错误，请重新输入"<<endl;
                cin.clear();    // 清理输入标志位
                cin.sync();     // 清空键盘缓冲区
                --i;            // 本次输入作废，不计算在内
                continue;
            }
            else
            {
                if("-1" == strName)
                {
                    break;
                }
                if(enumOfficer == nL)
                    m_arrEmp[i] = new Officer(strName, nY);
                else if(enumStaff == nL)
                    m_arrEmp[i] = new Staff(strName, nY);
                else
                {
                    cout<<"错误的员工级别，请重新输入"<<endl;
                    --i;
                    cin.clear();
                    cin.sync();
                    continue;
                }
            }
        }
        m_nCount = i;
        return m_nCount;
    }

    // 获得最高工资的员工对象
    Employee* GetMax()
    {
        Employee* pMax = nullptr;

        int nMax = INT_MIN;
        for(int i=0; i<m_nCount;++i)
        {
            if(m_arrEmp[i]->GetSalary() >nMax)
            {
                pMax = m_arrEmp[i];
                nMax = pMax->GetSalary();
            }
        }
        return pMax;
    }

    // 查询员工工资
    void Find()
    {
        while(true)
        {
            string strName = "";
            cout<<"请输入要查询的员工名字（-1表示结束查询）："<<endl;
            cin>>strName;

            if(!cin)
            {
                cout<<"输入错误，请重新输入"<<endl;
                cin.clear();
                cin.sync();
                continue;
            }
            else if("-1" == strName)
            {
                cout<<"查询完毕，感谢使用！"<<endl;
                break;
            }
            bool bFind = false;
            for(int i=0;i<m_nCount;++i)
            {
                Employee* p = m_arrEmp[i];
                if(strName == p->GetName())
                {
                    cout<<"员工姓名："<<p->GetName()<<endl;
                    cout<<"员工工资："<<p->GetSalary()<<endl;
                    bFind=true;
                    break;
                }
            }
            if(!bFind)
            {
            cout<<"无法找到名字为"<<strName<<"的员工"<<endl;
            cout<<"请核对姓名，重新输入"<<endl;
            }
        }
    }
private:
    const string m_strFileName;
    Employee* m_arrEmp[MAX];
    int m_nCount;
};


int main()
{
    SalarySys sys;

    sys.Input();

    Employee* pMax = sys.GetMax();
    if(nullptr != pMax)
    {
        cout<<"工资最高的员工是："<<endl;
        cout<<"名字："<<pMax->GetName()<<endl;
        cout<<"工资："<<pMax->GetSalary()<<endl;
    }

    sys.Find();

    return 0;
}
