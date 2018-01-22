#include<iostream>
using namespace std;

class Base
{
public:
    void foo1(void){};
    void foo2(void){};
public:
    double m_fMember1;
    int m_nMember2;
};

// 定义类成员函数指针类型
// 用于得到类的成员函数指针
typedef void (Base::*CLASS_FUNC)(void);

int main()
{
    Base base;
    
    cout<<"类对象的地址是："<<&base<<endl;

    cout<<"类对象中成员变量m_fMember1的地址是："<<&(base.m_fMember1)<<endl;

    cout<<"类对象中成员变量m_fMember1占用的内存字节数是："<<sizeof(base.m_fMember1)<<endl;

    cout<<"类对象中成员变量m_fMember2的地址是："<<&(base.m_nMember2)<<endl;

    CLASS_FUNC pFunc = &Base::foo1;
    unsigned int* tmp = (unsigned int*)&pFunc;
    cout<<"Base类第一个成员函数的地址是："<<hex<<*tmp<<endl;

    pFunc = &Base::foo2;
    tmp = (unsigned int*)&pFunc;
    cout<<"Base类第二个成员函数的地址是："<<hex<<*tmp<<endl;

    return 0;
}
