#include<iostream>
using namespace std;

// 计算数组所有元素之和

void SumArray(int* pArray, int nCount, int* pSum)
{
    int nRes = 0;
    for(int i=0; i<nCount; ++i)
    {
        nRes += *pArray;
        pArray++;
    }
    *pSum = nRes;
}

int main()
{
    int nArraySum = 0;
    int nArray[5] = {1,2,3,4,5};

    SumArray(nArray, 5, &nArraySum);
    cout<<"数组的所有数据之和是："<<nArraySum<<endl;
    return 0;
}
