#include<iostream>
using namespace std;

class Keyboard
{
public:
    void Input()
    {
        cout<<"键盘输入"<<endl;
    }
};

class Monitor
{
public:
    void Display()
    {
        cout<<"显示器输出"<<endl;
    }
};

class Computer
{
public:
    Computer(Keyboard* pKeyboard, Monitor* pMonitor)
    {
        m_pKeyboard = pKeyboard;
        m_pMonitor = pMonitor;
    }

    void Input()
    {
        m_pKeyboard->Input();
    }

    void Display()
    {
        m_pMonitor->Display();
    }
private:
    // 电脑的各个组成部分
    Keyboard* m_pKeyboard = nullptr;
    Monitor* m_pMonitor = nullptr;
};


int main()
{
    Keyboard keyboard;
    Monitor monitor;

    Computer com(&keyboard, &monitor);

    com.Input();
    com.Display();
    
    return 0;
}
