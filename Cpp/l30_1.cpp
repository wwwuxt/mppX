#include <iostream>
// 为了读写文件，引入文件流对象头文件
#include <fstream>
#include <string>
#include <climits> // 为了使用int类型的最大值和最小值

using namespace std; 

// 全局的工资数据文件名，使用一个不可修改的常量字符串表示
const string strFileName = "SalaryData.txt";

// 从数据文件读取工资数据到arrSalary数组
int Read(int* arrSalary, int nCount)
{
    int i = 0;   // 当前工资序号

    // 打开工资数据文件SalaryData.txt用于读入数据
    // 这个文件应该在exe文件所在的相同目录下
    ifstream in(strFileName);

    if(in.is_open()) // 如果成功打开数据文件
    {
         // 构造一个while循环读取文件中的工资数据
         // 如果读取的数据个数i小于数组的容量nCount，则继续读取
        while(i < nCount)
        {
             // 将读取的数据保存到arrSalary[i]
             in>>arrSalary[i];
             // 对读取结果进行判断，看是否读取到了文件结束
             // 如果到达文件结尾，则用break关键字结束读取循环
             if(!(in))
             {
                 break;
              }

             ++i;  // 尚未读取完毕，开始下一次读取
        }

        // 读取完毕，关闭文件
         in.close();
    }
    // 输出读取结果，返回读取的数据个数
    cout<<"读取"<<i<<"个工资数据"<<endl;
    return i;
}

// 将arrSalary数组中的工资数据写入数据文件
void Write(int* arrSalary, int nCount)
{
    // 创建或打开工资数据文件SalaryData.txt用于输出
    // 输出完成后，这个文件将出现在exe文件所在的目录
    ofstream o(strFileName);
    if(o.is_open()) // 如果成功打开数据文件
    {
        // 利用for循环，将数组中的数据输出到文件
         for(int i = 0;i < nCount;++i)
        {
             o<<arrSalary[i]<<endl; // 每一行一个数据
        }

        // 输出完毕，关闭文件
        o.close();
    }
}

// 获取工资数组中的最大值
int GetMax(int* arrSalary, int nCount)
{
    int nMax = INT_MIN; // 初始值为int类型的最小值
    // 利用for循环遍历数组中所有数据元素，逐个进行比较
    for(int i = 0;i < nCount; ++i)
    {
        if(arrSalary[i] > nMax)
             nMax = arrSalary[i];
    }
    // 返回找到的最大值
    return nMax;
}

// 获取数组中的最小值（请依最大值函数的葫芦自行画出最小值函数的瓢）…
int GetMin(int* arrSalary, int nCount)
{
    int nMin = INT_MAX;
    for(int i=0; i< nCount; i++)
    {
        if(arrSalary[i] < nMin) nMin = arrSalary[i];
    }
    return nMin;
}
// 计算数组中所有数据的平均值
float GetAver(int* arrSalary, int nCount)
{
    // 计算总和
    int nTotal = 0;
    for(int i = 0;i < nCount; ++i)
    {
        nTotal += arrSalary[i];
    }
 
    // 计算平均值并返回
    if(0 != nCount) // 判断总数是否为0
        return (float)nTotal/nCount;
    else
        return 0.0f; // 特殊情况返回0
}

// 手工输入数据
int Input(int* arrSalary, // 工资数组首地址
       int nMax,    // 数组能够容纳的数据的个数      //    
       int nIndex)  // 数组中已有的数据的个数
{
    // 用数组中已有数据的个数作为输入的起点
    int i = nIndex;  // 在for循环之前初始化i，应为i在for循环之后还需要用到
    for(; i < nMax; ++i) // i已经初始化，初始化语句留空
    {
        // 提示输入
        cout<<"请输入"<<i<<"号员工的工资（-1表示输入结束）："<<endl;
        // 将输入的数据保存到数组的arrSalary[i]数据元素
        int n = 0;
        cin>>n;
        // 检查输入是否合法
         if(cin)
        {
             arrSalary[i] = n;
        }
        else// 如果输入不合法，例如输入了英文字符，则提示用户重新输入
        {
             cout<<"输入错误，请重新输入"<<endl;
             // 清理cin的输入标志位以重新输入
             cin.clear();
             // 清空输入缓冲区
             cin.sync();
             --i;  // 将输入序号退后一个
             continue; // 直接开始下一次循环
        }
  
        // 检查是否输入结束
        if(-1 == arrSalary[i])
        {
             break; // 结束输入循环
        }
    }
   
    // 返回当前数组中共有的数据个数
    return i;
}

// 查询工资数据
void Find(int* arrSalary,int nCount)
{
    while(true)  // 构造无限循环进行工资查询
    {
        int n = 0;
        // 提示用户输入要查询的员工序号
        cout<<"请输入要查询的员工序号（0-"<<nCount-1
             <<"，-1表示结束查询）："<<endl;
        // 获取用户输入的员工序号并保存到n
        cin>>n;
  
        // 对用户输入进行检查
        if(!cin) // 如果用户输入不合法
        {
             cout<<"输入错误，请重新输入"<<endl;
             // 清理cin的输入标志位以重新输入
             cin.clear();
             // 清空输入缓冲区
             cin.sync();
             continue; // 开始下一次查询
        }
        else if(-1 == n) // 检查查询是否结束
        {
             // 查询结束，用break结束循环
             cout<<"查询完毕，感谢使用！"<<endl;
             break;
        }
        else if(n<0||n>=nCount) // 检查输入是否超出序号范围
        {
             // 输入序号超出范围，用continue开始下一次循环
             cout<<"输入的序号"<<n<<"超出了序号范围0-"
              <<nCount-1<<"，请重新输入。"<<endl;
             // 开始下一次查询
             continue;
        }
 
        // 输入合法，输出用户查询的员工工资
        cout<<"员工序号："<<n<<endl;
        cout<<"员工工资："<<arrSalary[n]<<endl;
    }
}

int main()
{
    // 定义保存员工数据的超大数组
    const int MAX = 100000; 
    int arrSalary[MAX] = {0};
 
    // 首先从数据文件读取已经保存的数据
    int nCount = Read(arrSalary,MAX);
    // 然后用手工继续输入工资数据
    nCount = Input(arrSalary,MAX,nCount);

    // 对输入的工资数据进行统计
    cout<<"输入完毕。一共有"<<nCount<<"个工资数据"<<endl;
    cout<<"最大值："<<GetMax(arrSalary,nCount)<<endl;
    cout<<"最小值："<<GetMin(arrSalary,nCount)<<endl;
    cout<<"平均值："<<GetAver(arrSalary,nCount)<<endl;

    // 对工资数据进行查询
    Find(arrSalary,nCount);
    
    // 查询结束，将工资数据保存到数据文件，以备下次使用
    Write(arrSalary,nCount);
  
    return 0;
}
