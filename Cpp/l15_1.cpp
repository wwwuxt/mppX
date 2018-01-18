#include<iostream>
using namespace std;

int main()
{
 int a = 1990;
 int* pa = &a;
 cout <<"pa: "<< pa <<" *pa: "<< *pa<<endl;
 int* pb = pa;

 *pb = 2000;
 cout<<*pa<<endl;
 return 0;
}
