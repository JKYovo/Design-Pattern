#include <iostream>
using namespace std;

// 船体
class ShipBody
{
public:
    virtual string getShipBody() = 0;
    virtual ~ShipBody() {cout<<"销毁船体"<<endl;}
};

class WoodBody : public ShipBody
{
public:
    string getShipBody() override
    {
        return string("用<木材>制作轮船船体...");
    }
};

class IronBody : public ShipBody
{
public:
    string getShipBody() override
    {
        return string("用<钢铁>制作轮船船体...");
    }
};

class MetalBody : public ShipBody
{
public:
    string getShipBody() override
    {
        return string("用<合金>制作轮船船体...");
    }
};

//动力
class Engine
{
public:
    virtual string getEngine() = 0;
    virtual ~Engine() {cout<<"销毁动力"<<endl;}
};

class Human : public Engine
{   
public:
    string getEngine() override
    {
        return string("用<人力>驱动轮船...");
    }
};

class Fire : public Engine
{
public:
    string getEngine() override
    {
        return string("使用<内燃机驱动>...");
    }
};

class Nuclear : public Engine
{
public:
    string getEngine() override
    {
        return string("使用<核能驱动>...");
    }
};

// 武器
class Weapon
{
public:
    virtual string getWeapon() = 0;
    virtual ~Weapon() {cout<<"销毁武器"<<endl;}
};

class Gun : public Weapon
{
public:
    string getWeapon() override
    {
        return string("配备的武器是<枪>...");
    }
};

class Cannon : public Weapon
{
public:
    string getWeapon() override
    {
        return string("配备的武器是<自动机关炮>...");
    }
};

class Ray : public Weapon
{
public:
    string getWeapon() override
    {
        return string("配备的武器是<激光>...");
    }
};

// 轮船类
class Ship
{
public:
    Ship(ShipBody* body, Weapon* weapon, Engine* engine) : m_body(body), m_weapon(weapon), m_engine(engine) {}
    string getProperty()
    {
        string info = m_body->getShipBody() + m_weapon->getWeapon() + m_engine->getEngine();
        return info;
    }
    ~Ship() 
    {
        delete m_body;
        delete m_engine;
        delete m_weapon;
        cout<<"销毁轮船"<<endl;
    }
private:
    ShipBody* m_body = nullptr;
    Weapon* m_weapon = nullptr;
    Engine* m_engine = nullptr;
};

//造船厂要生产三种型号的船，那么也就是至少需要三条生产线，所以对应的工厂类也就不止一个，处理思路还是一样的，提供一个抽象的基类，然后在它的子类中完成各种型号的船的组装，每个子类对应的就是一条生产线。

//抽象工厂类中定义了一个纯虚函数createShip()，用于创建船只对象，然后在具体的工厂类中实现这个函数，完成船只的组装工作。
class AbstractFactory
{
public:
    virtual Ship* createShip() = 0;
    virtual ~AbstractFactory() {cout<<"销毁工厂"<<endl;}
};

class BasicFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new WoodBody, new Gun, new Human);
        cout << "<基础型>战船生产完毕, 可以下水啦..." << endl;
        return ship;
    }
};

class StandardFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new IronBody, new Cannon, new Fire);
        cout << "<标准型>战船生产完毕, 可以下水啦..." << endl;
        return ship;
    }
};

class UltimateFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new MetalBody, new Ray, new Nuclear);
        cout << "<旗舰型>战船生产完毕, 可以下水啦..." << endl;
        return ship;
    }
};

int main()
{
    AbstractFactory *factory = new BasicFactory;
    Ship *Ship = factory->createShip();
    delete Ship;
    delete factory;
}
