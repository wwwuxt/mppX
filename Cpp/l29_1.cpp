#include<assert.h>
#include<iostream>
using namespace std;

double Divide(int nDividend, int nDivisor)
{
    static_assert(sizeof(long)>=8, "编译需要64位平台"); // 静态（编译期）断言，不能依赖于运行时变量
    assert( 0!= nDivisor);                 // 运行时断言
    return (double)nDividend/nDivisor;
}

int main()
{
    int a,b;
    cout<<"输入a/b的a b:";
    cin>>a>>b;
    double fRes = Divide(a, b);
    cout<<fRes<<endl;
    return 0;
}
