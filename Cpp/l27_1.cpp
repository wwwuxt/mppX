#include<iostream>
#include<cstring> // strchr()

using namespace std;

int CountChar(const char* str, const char c)
{
    char* pos = strchr(str, c);
    if(nullptr == pos)
    {
        return 0;
    }
    return 1 + CountChar(pos + 1, c);
}
int main()
{
    char str[] = "Thought is a seed";
    char c = 'h';
    int nCount = CountChar(str, c);
    cout<<"字符\'"<<c<<"\'在\""<<str<<"\"种出现了"<<nCount<<"次"<<endl;
    return 0;
}
