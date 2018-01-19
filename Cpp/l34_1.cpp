#include"l34_1.h"
#include<assert.h>
#include<iostream>
using namespace std;

int main()
{
    Computer oldcom;
    Keyboard keyboard;

    keyboard.m_strModel = "Microsoft-101";

    oldcom.SetKeyboard(&keyboard);
    
    // 以oldcom为蓝本，利用Computer类的拷贝构造函数创建新对象newcom
    // 新的newcom对象是oldcom对象的一个副本
    Computer newcom(oldcom);

    //assert(newcom.GetModel() == oldcom.GetModel());
    
    // 不同的Computer对象应该拥有不同的Keyboard对象
    assert(newcom.GetKeyboard() != oldcom.GetKeyboard());
    // 因为是复制，不同的Keyboard对象应该是相同的型号
    assert(newcom.GetKeyboard()->m_strModel == oldcom.GetKeyboard()->m_strModel);
    
    
    Computer newcom1;
    newcom1 = oldcom;
    assert(newcom1.GetKeyboard() != oldcom.GetKeyboard());
    assert(newcom1.GetKeyboard()->m_strModel == oldcom.GetKeyboard()->m_strModel);
    return 0;
}
