#include<iostream>
#include <string>
using namespace std;

class Human
{
public:
    // 声明为虚函数，派生类才能调用到对应函数
    virtual void BuyTicket()
    {
        cout<<"人买票"<<endl;
    }
    void Walk()
    {
        cout<<"人走路"<<endl;
    }
    virtual void Talk()
    {
        cout<<"人讲话"<<endl;
    }
    virtual void Talk(string msg)
    { // 属于同层的重载
        cout<<"人讲话，内容是"<<msg<<endl;
    }
};

class Teacher : public Human
{
public:
    virtual void BuyTicket() // virtual关键字，可加可不加，建议加上
    {// 对基类函数的重写
        cout<<"老师投币买票"<<endl;
    }
    void Walk()
    {
        cout<<"老师走路"<<endl;
    }
    void Talk() override // override仅能对派生类重写的虚函数进行修饰，建议增加，表明意图
    {
        cout<<"老师讲话"<<endl;
    }
};

class Student : public Human
{
public:
    virtual void BuyTicket() override
    {
        cout<<"学生刷卡买票"<<endl;
    }
    void Walk()
    {
        cout<<"学生走路"<<endl;
    }
    void Talk() final // 虚函数的最终实现，后续派生类不能再重写
    {
        cout<<"学生讲话"<<endl;
    }
};

int main()
{
    Human *p1 = new Teacher(); // 通过基类指针调用，可以实现对被隐藏函数的调用
    Human *p2 = new Student();

    p1->BuyTicket(); // 调用派生类
    p2->BuyTicket(); // 调用派生类
    
    p1->Walk(); // 调用基类
    p2->Walk(); // 调用基类

    p1->Talk();
    p2->Talk();
    p1->Talk("通过基类指针调用，实现对隐藏函数的调用");  // 对基类被隐藏函数的调用
    delete p1;
    delete p2;
    p1 =  p2 = nullptr;
    
    Teacher t;
   // t.Talk("你好啊"); 错误。重载与重写结合，造成函数的隐藏
    ((Human)t).Talk("通过类型转换，实现对隐藏函数的调用");
    return 0;
}
