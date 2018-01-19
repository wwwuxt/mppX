#include<iostream>

using namespace std;

class Arm
{
public:
    void Hug()
    {
        cout<<"用手拥抱"<<endl;
    }
};

class Leg
{
public:
    void Walk()
    {
        cout<<"用脚走路"<<endl;
    }
};

class Body
{
public:
    void Hug()
    {
        arm.Hug();
    }
    void Walk()
    {
        leg.Walk();
    }
private:
    // 手脚是人的一部分，作为类的成员变量
    Arm arm;
    Leg leg;
};

int main()
{
    Body body;

    body.Hug();
    body.Walk();

    return 0;
}
