#include<iostream>
using namespace std;

void Increase(int& nVal)
{
    nVal += 1;
}

int main()
{
    int nInt = 1;
    Increase(nInt);
    cout<<nInt<<endl;
    return 0;
}
