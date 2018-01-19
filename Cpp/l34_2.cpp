#include<iostream>
#include<vector>
#include<initializer_list>

using namespace std;

class Salary
{
public:
    // 初始化列表构造函数
    // 工资数据为int类型，所以其参数类型为initializer_list<int>
    Salary(initializer_list<int> s)
    {
        // 以容器的形式访问初始化列表
        // 获取其中的工资项目保存到工资类的vector容器
        for(int i : s)
            m_vecSalary.push_back(i);
    }

    
    // 获取工资总数
    int GetTotal()
    {
        int nTotal = 0;
        for(int i : m_vecSalary)
            nTotal += i;
        return nTotal;
    }
private:
    vector<int> m_vecSalary;
};

int main()
{   
    // {} 表示初始化列表
    Salary sChen{2200};
    Salary sWang{5000, 9500, 1003};

    cout<<"sChen's Salary: "<< sChen.GetTotal()<<endl;
    cout<<"sWang's Salary: "<< sWang.GetTotal()<<endl;

    return 0;
}
