#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    int nYear, nMonth, nDate;

    ifstream fin("Date.txt");
    if(fin.is_open()){
        fin>>nYear>>nMonth>>nDate;
        cout<<"文件中记录的日期是"
            <<nYear<<"-"<<nMonth<<"-"<<nDate<<endl;
        fin.close();
    }
    else
    {
        cout<<"无法打开文件并进行读取"<<endl;
    }
    cout<<"请输入新日期 1999 9 9"<<endl;
    cin>>nYear>>nMonth>>nDate;

    ofstream fout("Date.txt");
    if(fout.is_open())
    {
        fout<<nYear<<" "<<nMonth<<" "<<nDate;
        fout.close();
    }
    else
    {
        cout<<"无法打开文件并进行写入"<<endl;
    }
    return 0;
}

