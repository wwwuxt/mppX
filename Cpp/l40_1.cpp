#include<iostream>
using namespace std;

int main()
{
    int nArray[3] = {1, 2, 3};
    int* pIndex = nArray; // 将数组的起始地址赋值给指针pIndex
    cout<<"指针指向的地址是："<<pIndex<<endl;
    cout<<"指针指向的数据的值是："<<*pIndex<<endl;
    int* pEnd = nArray + 3; // 数组结束地址
    while(pIndex != pEnd)
    {
        cout<<*pIndex<<endl;
        ++pIndex;
    }
    /* 
    pIndex++; // 对指针进行加运算，使其指向数组中的下一个值
    cout<<"指针指向的地址是："<<pIndex<<endl;
    cout<<"指针指向的数据的值是："<<*pIndex<<endl;
    pIndex++; // 对指针进行加运算，使其指向数组中的下一个值
    cout<<"指针指向的地址是："<<pIndex<<endl;
    cout<<"指针指向的数据的值是："<<*pIndex<<endl;
    pIndex++; // 对指针进行加运算，使其指向数组中的下一个值
    cout<<"指针指向的地址是："<<pIndex<<endl;
    cout<<"指针指向的数据的值是："<<*pIndex<<endl;
    */
    return 0;

}
