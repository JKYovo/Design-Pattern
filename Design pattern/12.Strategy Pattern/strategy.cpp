#include <iostream>
#include <string>
#include <list>
using namespace std;

// 抽象的策略类
class AbstractStrategy
{
public:
    virtual void fight(bool isfar = false) = 0;
    virtual ~AbstractStrategy() {}
};

// 一档
class YiDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** 现在使用的是一档: ";
        if (isfar)
        {
            cout << "橡胶机关枪" << endl;
        }
        else
        {
            cout << "橡胶·攻城炮" <<endl;
        }
    }
};

// 二挡
class ErDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** 切换成二挡: ";
        if (isfar)
        {
            cout << "橡胶Jet火箭" << endl;
        }
        else
        {
            cout << "橡胶Jet·铳乱打" << endl;
        }
    }
};

// 三挡
class SanDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** 切换成三挡: ";
        if (isfar)
        {
            cout << "橡胶巨人回旋弹" << endl;
        }
        else
        {
            cout << "橡胶巨人战斧" << endl;
        }
    }
};

// 四挡
class SiDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** 切换成四挡: ";
        if (isfar)
        {
            cout << "橡胶狮子火箭炮" << endl;
        }
        else
        {
            cout << "橡胶犀牛榴弹炮" << endl;
        }
    }
};

// 五档
class WuDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** 切换成五挡: 变成尼卡形态可以把物体变成橡胶, 并任意改变物体的形态对其进行攻击!!!" << endl;
    }
};

// 难度级别
enum class Level:char {Easy, Normal, Hard, Experts, Professional};

// 路飞
class Luffy
{
public:
    void fight(Level level, bool isfar = false)
    {
        if (m_strategy)
        {
            delete m_strategy;
            m_strategy = nullptr;
        }
        switch (level)
        {
        case Level::Easy:
            m_strategy = new YiDang;
            break;
        case Level::Normal:
            m_strategy = new ErDang;
            break;
        case Level::Hard:
            m_strategy = new SanDang;
            break;
        case Level::Experts:
            m_strategy = new SiDang;
            break;
        case Level::Professional:
            m_strategy = new WuDang;
            break;
        default:
            break;
        }
        m_strategy->fight(isfar);
    }
    ~Luffy()
    {
        delete m_strategy;
    }
private:
    AbstractStrategy* m_strategy = nullptr;
};

int main()
{
    Luffy luffy;
    luffy.fight(Level::Easy);
    luffy.fight(Level::Normal);
    luffy.fight(Level::Hard);
    luffy.fight(Level::Experts);
    luffy.fight(Level::Professional);
    return 0;
}