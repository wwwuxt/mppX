#include <iostream>
using namespace std;

int main()
{
    cout <<"=============每月收支统计程序==============="<<endl;
    cout<<"请输入你本月的收入（正数）和支出（负数），0表示结束" <<endl;
    int nInput = 0;
    int nTotal = 0;

    do
    {
        cin >>nInput;
        nTotal += nInput;
    }while(0 != nInput);

    cout <<"你本月的结余是：" <<nTotal<<endl;
    return 0;
}
