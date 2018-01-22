#include<iostream>
using namespace std;

int FuncByValue(int x)
{
    x = x+1;
    return x;
}

int* FuncByPointer(int* p)
{
    *p = *p + 1;
    return p;
}

int& FuncByRef(int& r)
{
    r = r + 1;
    return r;
}

int main()
{
    int n = 0;
    cout<<"n的初始值，n = "<<n<<endl;

    FuncByValue(n);
    cout<<"传值，n = "<<n<<endl;

    FuncByPointer(&n);
    cout<<"传指针，n = "<<n<<endl;

    FuncByRef(n);
    cout<<"传引用，n = "<<n<<endl;

    return 0;
}
