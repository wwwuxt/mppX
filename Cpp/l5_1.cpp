#include<iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout<<"请输入两个整数："<<endl;
    int n1,n2;
    cin>>n1>>n2;
    int nRes = n1+n2;
    cout <<n1<<" + "<<n2
        << " = "<<nRes <<endl;
    
    cout <<fixed<<setprecision(2)<<1.23456<<endl;

    return 0;

}
