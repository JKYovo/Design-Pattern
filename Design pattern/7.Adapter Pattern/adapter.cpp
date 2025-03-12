#include <iostream>
#include <vector>
#include <map>
using namespace std;

//适配器就是两者之间的桥梁，它将一个类的接口转换成客户希望的另外一个接口。
//适配器模式让那些本来由于接口不兼容而不能一起工作的类可以一起工作。
class Foreigner
{
public:
    virtual string confession() = 0; //发
    void setResult(string msg)  // 收
    {
        cout << "Panda Say: " << msg << endl;
    }
    virtual ~Foreigner() {}
};

// 美国人
class American : public Foreigner
{
public:
    string confession() override
    {
        return string("我是畜生, 我有罪!!!");
    }
};

// 法国人
class French : public Foreigner
{
public:
    string confession()
    {
        return string("我是强盗, 我该死!!!");
    }
};

// 大熊猫
class Panda
{
public:
    void recvMessage(string msg) //收
    {
        cout << msg << endl;
    }
    string sendMessage() //发
    {
        return string("强盗、凶手、罪人是不可能被宽恕和原谅的！");
    }
};

// 抽象乔巴适配器类
class AbstractChopper
{
public:
    AbstractChopper(Foreigner* foreigner) : m_foreigner(foreigner) {}
    virtual void translateToPanda() = 0;
    virtual void translateToHuman() = 0;
    virtual ~AbstractChopper() {}
protected:
    Panda m_panda;
    Foreigner* m_foreigner = nullptr;
};

// 英语乔巴适配器
class EnglishChopper : public AbstractChopper
{
public:
    // 继承构造函数
    using AbstractChopper::AbstractChopper;
    void translateToPanda() override
    {
        string msg = m_foreigner->confession();
        // 翻译并将信息传递给熊猫对象
        m_panda.recvMessage("美国人说: " + msg);
    }
    void translateToHuman() override
    {
        // 接收熊猫的信息
        string msg = m_panda.sendMessage();
        // 翻译并将熊猫的话转发给美国人
        m_foreigner->setResult("美国佬, " + msg);
    }
};

// 法语乔巴适配器
class FrenchChopper : public AbstractChopper
{
public:
    using AbstractChopper::AbstractChopper;
    void translateToPanda() override
    {
        string msg = m_foreigner->confession();
        // 翻译并将信息传递给熊猫对象
        m_panda.recvMessage("法国人说: " + msg);
    }
    void translateToHuman() override
    {
        // 接收熊猫的信息
        string msg = m_panda.sendMessage();
        // 翻译并将熊猫的话转发给法国人
        m_foreigner->setResult("法国佬, " + msg);
    }
};

int main()
{
    Foreigner* human = new American;
    EnglishChopper* american = new EnglishChopper(human);
    american->translateToPanda();
    american->translateToHuman();
    delete human;
    delete american;

    human = new French;
    FrenchChopper* french = new FrenchChopper(human);
    french->translateToPanda();
    french->translateToHuman();
    delete human;
    delete french;

    return 0;
}
