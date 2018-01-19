#include<iostream>
using namespace std;
// 拥有友元的Teacher类
class Teacher
{
    friend class TaxationDep;

    friend int AdjustSalary(Teacher* teacher);

protected:
    int m_nSalary=0;
};

int AdjustSalary(Teacher* teacher)
{
    if (teacher != nullptr && teacher->m_nSalary < 100000)
    {
        teacher->m_nSalary += 500;
        return teacher->m_nSalary;
    }
    return 0;
}

class TaxationDep
{
public:
    void CheckSalary(Teacher* teacher)
    {
        if(teacher!=nullptr && teacher->m_nSalary >1000)
        {
            cout<<"这位老师应该交税"<<endl;
        }
        else
        {
            cout<<"不需交税或者没有这个老师"<<endl;
        }
    }
};

int main()
{
    Teacher t;
    cout<<AdjustSalary(&t)<<endl;
    TaxationDep td;
    td.CheckSalary(&t);
    cout<<AdjustSalary(&t)<<endl;
    td.CheckSalary(&t);
    cout<<AdjustSalary(&t)<<endl;
    td.CheckSalary(&t);
    return 0;
}
