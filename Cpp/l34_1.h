#include<string>
using namespace std;
struct Keyboard
{
    string m_strModel;
};

class Computer
{
public:
    // 默认构造函数
    Computer()
        : m_pKeyboard(nullptr),m_strModel("")
    {}
    // 拷贝构造函数，参数时const修饰的Computer类的引用
    Computer(const Computer& com)
        : m_strModel(com.m_strModel)    // 直接使用初始化属性列表完成对象类型成员变量m_strModel的复制
    {
        // 创建新对象，完成指针类型成员变量m_pKeyboard的复制
        // 获得已有对象com的指针类型成员变量m_pKeyboard
        Keyboard* pOldKeyboard = com.GetKeyboard();
        // 以pOldKeyboard所指向的Keyboard对象为蓝本，
        // 创建一个新的Keyboard对象，并让m_Keyboard指向这个对象
        if( nullptr != pOldKeyboard)
        {
            // 这里Keyboard对象的复制使用的是Keyboard类的默认拷贝构造函数
            m_pKeyboard = new Keyboard(*(pOldKeyboard));
        }
        else
        {
            m_pKeyboard = nullptr;
        }
    }
    // 析构函数
    // 对于对象类型的成员变量m_strModel, 会被自动销毁，无需在析构函数中进行处理
    // 对于指针类型的成员变量m_pKeyboard,需在析构函数中主动销毁
    ~Computer()
    {
        //delete m_pKeyboard;
        //m_pKeyboard = nullptr;
    }

    // 成员函数，设置或获得键盘对象指针
    void SetKeyboard(Keyboard* pKeyboard)
    {
        m_pKeyboard = pKeyboard;
    }

    Keyboard* GetKeyboard() const
    {
        return m_pKeyboard;
    }

private:
    Keyboard* m_pKeyboard;
    
    string m_strModel;
};
