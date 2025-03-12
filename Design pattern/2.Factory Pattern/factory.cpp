// 使用工厂模式可以很完美的解决上述的问题，简单工厂模式是只有一个工厂类，而工厂模式是有很多的工厂类：

// 一个基类，包含一个虚工厂函数，用于实现多态。
// 多个子类，重写父类的工厂函数。每个子工厂类负责生产一种恶魔果实，这相当于再次解耦，将工厂类的职责再次拆分、细化，如果要生产新品种的恶魔果实，那么只需要添加对应的工厂类，无需修改原有的代码。
// 恶魔果实工厂类

#include <iostream>
using namespace std;

// 基类：抽象恶魔果实
class AbstractSmile
{
public:
    virtual void transform() = 0; // 纯虚函数：变身
    virtual void ability() = 0;   // 纯虚函数：能力
    virtual ~AbstractSmile() { cout<<"释放 AbstractSmile 类相关的内存资源"<<endl;}  // 虚析构函数，确保正确释放派生类对象
};

// 绵羊形态恶魔果实
class SheepSmile : public AbstractSmile
{
public:
    void transform() override
    {
        cout << "变成人兽 -- 山羊人形态..." << endl;
    }
    void ability() override
    {
        cout << "将手臂变成绵羊角的招式 -- 巨羊角" << endl;
    }
};

// 狮子形态恶魔果实
class LionSmile : public AbstractSmile
{
public:
    void transform() override
    {
        cout << "变成人兽 -- 狮子人形态..." << endl;
    }
    void ability() override
    {
        cout << "火遁· 豪火球之术..." << endl;
    }
};

// 蝙蝠形态恶魔果实
class BatSmile : public AbstractSmile
{
public:
    void transform() override
    {
        cout << "变成人兽 -- 蝙蝠人形态..." << endl;
    }
    void ability() override
    {
        cout << "声纳引箭之万剑归宗..." << endl;
    }
};

class AbstractFactory
{
public:
    virtual AbstractSmile *createSmile() = 0;// 纯虚函数是一种特殊的虚函数，它在基类中没有定义，要求派生类必须定义。
    virtual ~AbstractFactory() {cout << "释放 AbstractFactory 类相关的内存资源" << endl;}
};

class SheepFactory : public AbstractFactory
{
public:
    AbstractSmile *createSmile() override //override关键字，用于显式地指示一个函数是覆盖基类中的虚函数,在 C++11 之前，派生类重写基类虚函数时，如果函数签名不匹配（例如参数类型或数量错误），编译器不会报错，而是将其视为一个新的函数。这可能导致意外的行为。
    {
        return new SheepSmile;
    }
    ~SheepFactory()
    {
        cout << "释放 SheepFactory 类相关的内存资源" << endl;
    }
};

class LionFactory : public AbstractFactory
{
public:
    AbstractSmile *createSmile() override
    {
        return new LionSmile;
    }
    ~LionFactory()
    {
        cout << "释放 LionFactory 类相关的内存资源" << endl;
    }
};

class BatFactory : public AbstractFactory
{
public:
    AbstractSmile *createSmile() override
    {
        return new BatSmile;
    }
    ~BatFactory()
    {
        cout << "释放 BatFactory 类相关的内存资源" << endl;
    }
};

int main(){
    AbstractFactory *factory = new SheepFactory;
    AbstractSmile *obj = factory->createSmile();
    if (obj)
    {
        obj->transform();
        obj->ability();
        delete obj;
    }
    delete factory;
}