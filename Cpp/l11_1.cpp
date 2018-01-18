#include<iostream>
#include<string>
using namespace std;

int main()
{
    string strEn = "Good Morning";
    wstring strChs = L"京A-00000";

    cout<<strEn<<endl;
    
    wcout.imbue( locale( "chs" ) ); //设置区域
    wcout<<strChs<<endl;
    return 0;
}
