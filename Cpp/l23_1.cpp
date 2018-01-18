// 工资程序V1.0
#include <iostream>
#include <climits> // 使用整数最值宏INT_MAX, INT_MIN

using namespace std;

int main()
{
    const int MAX = 100000;
    int arrSalary[MAX] = {0};

    int nTotal = 0;
    int min = INT_MAX;
    int max = INT_MIN;
    
    int nCount = 0;
    for(int i=0; i<MAX; ++i)
    {
        cout<<"请输入"<<i<<"号员工的工资（-1表示输入结束）："<<endl;
        cin>>arrSalary[i];

        if(-1==arrSalary[i])
        {
            cout<<"工资输入结束，一共输入了"<<nCount<<"个工资数据。"<<endl;
            if(0 != nCount)
            {
                cout<<"其中，"<<endl;
                cout<<"最大值是"<<max<<endl;
                cout<<"最小值是"<<min<<endl;

                float fAver = (float)nTotal/nCount;
                cout<<"平均工资是"<<fAver<<endl;
            }
            break;
        }
        ++nCount;

        nTotal += arrSalary[i];

        if(arrSalary[i] < min) min = arrSalary[i];
        if(arrSalary[i] > max) max = arrSalary[i];
    }

    if(0 == nCount)
    {
        cout<<"没有工资数据，无法进行查询，感谢使用"<<endl;
        return 0;
    }

    while(true)
    {
        int n = 0;
        cout<<"请输入要查询的员工序号（0-"<<nCount-1<<",-1表示结束查询："<<endl;

        cin >> n;
        if(-1==n)
        {
            cout<<"查询完毕，感谢使用"<<endl;
            break;
        }
        else if(n <0 || n >= nCount)
        {
            cout<<"输入的序号"<<n<<"超出了序号范围0-"<<nCount-1<<"，请重新输入。"<<endl;
            continue;
        }
        cout<<"员工序号："<<n<<endl;
        cout<<"员工工资："<<arrSalary[n]<<endl;

    }
    
    return 0;
}
