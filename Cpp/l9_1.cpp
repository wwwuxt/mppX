#include <cstring> // 引入memset()

#include<iostream>
//#pragma pack(1) //告诉编译器,所有的对齐都按照1的整数倍对齐,换句话说就是没有对齐规则.
//Vc,Vs等编译器默认是#pragma pack(8)，所以测试我们的规则会正常；注意gcc默认是#pragma pack(4)，并且gcc只支持1,2,4对齐。套用三原则里计算的对齐值是不能大于#pragma pack指定的n值。
using namespace std;

struct Human
{
 char mName[3];
 int nAge;
};
struct Human2
{
 char mName[3];
 char c; //字节对齐补全
 int nAge;
};

typedef struct bb
{
int id;             //[0]....[3]
double weight;      //[8].....[15]　　　　　　原则１
float height;      //[16]..[19],总长要为８的整数倍,补齐[20]...[23]　　　　　原则３
}BB;

typedef struct aa
{
char name[2];     //[0],[1]
int  id;         //[4]...[7]　　　　　　　　　　原则１
double score;     //[8]....[15]　　　　
short grade;    //[16],[17]　　　　　　　　
BB b;             //[24]......[47]　　　　　　　　　　原则２
}AA;
int main()
{
    int int_size;
    long long_size;
    long long llong_size;
    signed int sint_size;
    unsigned int usint_size;
    short int shortint_size;
    cout<<"sizeof(int)"<<sizeof(int_size)<<endl;
    cout<<"sizeof(long)"<<sizeof(long_size)<<endl;
    cout<<"sizeof(long long)"<<sizeof(llong_size)<<endl;
    cout<<"sizeof(signed int)"<<sizeof(sint_size)<<endl;
    cout<<"sizeof(unsigned int)"<<sizeof(usint_size)<<endl;
    cout<<"sizeof(short int)"<<sizeof(shortint_size)<<endl;
    int res[1024];
    cout<<"sizeof(res): "<<sizeof(res)<<endl;
    memset(res,0,sizeof(res));
    
    Human huTest;
    cout<<"Human结构体的字节数，包含因字节对齐而添加的一个字节，即3+1+4=::::"<<sizeof(Human)<<endl;
    cout<<"huTest:"<<sizeof(huTest)<<endl;
    cout<<"Human2结构体的字节数，字节完整：："<<sizeof(Human2)<<endl;
    
    AA a;
    cout<<sizeof(a)<<" "<<sizeof(BB)<<endl;
    
    return 0;
}

