#include<iostream>
using namespace std;

int main()
{
    // 指针数组，保存的是各个字符串常量的首地址指针，其类型是const char*
    const char* arrMonth[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    // 定义一个指向指针的指针
    // 因为要指向的指针是const char*， 所以类型是const char**
    // 数组的首地址arrMonth就是数组的第一个元素
    // 即指向第一个字符串"Jan"的指针
    const char** pMonth = arrMonth;

    int nIndex = 0;
    cout<<"请输入月份对应的数组："<<endl;
    cin>>nIndex;

    const char* pCurMonth = *(pMonth + (nIndex -1));
    cout<<"对应的月份是："<<pCurMonth<<endl;

    return 0;
}

