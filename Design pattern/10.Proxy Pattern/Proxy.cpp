#include <iostream>
#include <string>
using namespace std;

// 代理模式是为其他对象提供一种代理以控制对这个对象的访问。
// 代理模式就是多一个代理类出来，替原对象进行一些操作，比如我们在租房的时候会通过中介。

// 抽象通信类
class Communication
{
public:
    virtual void communicate() = 0; // 通话
    virtual ~Communication() {}
};

// 讲话的人
class Speaker : public Communication
{
public:
    void communicate() override
    {
        cout << "开始说话..." << endl;
        cout << "通话时发生了一些列的表情变化..." << endl;
    }
};

// 电话虫
class DenDenMushi : public Communication
{
public:
    DenDenMushi()
    {
        m_isStart = true;
        m_speaker = new Speaker;
    }
    ~DenDenMushi()
    {
        if (m_speaker != nullptr)
        {
            delete m_speaker;
        }
    }
    // 判断是否已经开始通话了
    bool isStart()
    {
        return m_isStart;
    }
    void communicate() override
    {
        if (isStart())
        {
            // 得到通话者语言和表情信息, 并加以模仿
            cout << "电话虫开始实时模仿通话者的语言和表情..." << endl;
            m_speaker->communicate();
       }
    }
private:
    bool m_isStart = false;
    Speaker* m_speaker = nullptr;
};

int main()
{
    // 直接交流
    Communication* comm = new Speaker;
    comm->communicate();
    delete comm;
    cout << "===================================" << endl;
    // 使用电话虫
    comm = new DenDenMushi;
    comm->communicate();
    delete comm;

    return 0;
}
//通过测试程序我们可以得到如下结论：如果使用代理模式，不能改变所代理的类的接口，使用代理模式的目的是为了加强控制。