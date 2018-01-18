#include<iostream>
using namespace std;

int max(int a, int b)
{
    return a>b?a:b;
}
int max(int a, int b, int c)
// int max(int a, int b, int c=5) // ERROR ambiguous
{
    return a>c?a:c;
}
int main()
{
    int a = 1;
    int b = 2;
    cout<<max(a,b)<<endl;
    return 0;
}
