#include<random>
#include<iostream>

using namespace std;

int main()
{
    // 定义一个默认的随机数引擎
    default_random_engine reng;
    // 构建一个从0到25之间的平均分布
    uniform_int_distribution<int> uni_dist(0,25);

    // 使用random_device设置随机数引擎的种子，
    // 以防止每次运行都产生相同的伪随机数序列
    random_device rnd_device;
    reng.seed(rnd_device());
    
    // 4位随机数
    const int n = 4;
    char code[n];
    
    cout <<"请输入下面的验证码："<<endl;
    for(int i=0; i<n; i++)
    {
        code[i] = 'A' + uni_dist(reng);
        cout<<code[i];
    }
    cout<<"\n";
    return 0;
}
