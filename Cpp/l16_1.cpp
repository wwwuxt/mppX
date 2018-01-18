#include<iostream>
using namespace std;

int main()
{

    int a =1;
    int b = a++ + 1;
    a = 1;
    int c = ++a + 1;
    cout<<"a: "<<a<<"  b: "<<b<< "  a: "<<a<<"  c: "<<c<<endl;
    return 0;
}
