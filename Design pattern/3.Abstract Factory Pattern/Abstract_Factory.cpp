#include <iostream>
using namespace std;

// ����
class ShipBody
{
public:
    virtual string getShipBody() = 0;
    virtual ~ShipBody() {cout<<"���ٴ���"<<endl;}
};

class WoodBody : public ShipBody
{
public:
    string getShipBody() override
    {
        return string("��<ľ��>�����ִ�����...");
    }
};

class IronBody : public ShipBody
{
public:
    string getShipBody() override
    {
        return string("��<����>�����ִ�����...");
    }
};

class MetalBody : public ShipBody
{
public:
    string getShipBody() override
    {
        return string("��<�Ͻ�>�����ִ�����...");
    }
};

//����
class Engine
{
public:
    virtual string getEngine() = 0;
    virtual ~Engine() {cout<<"���ٶ���"<<endl;}
};

class Human : public Engine
{   
public:
    string getEngine() override
    {
        return string("��<����>�����ִ�...");
    }
};

class Fire : public Engine
{
public:
    string getEngine() override
    {
        return string("ʹ��<��ȼ������>...");
    }
};

class Nuclear : public Engine
{
public:
    string getEngine() override
    {
        return string("ʹ��<��������>...");
    }
};

// ����
class Weapon
{
public:
    virtual string getWeapon() = 0;
    virtual ~Weapon() {cout<<"��������"<<endl;}
};

class Gun : public Weapon
{
public:
    string getWeapon() override
    {
        return string("�䱸��������<ǹ>...");
    }
};

class Cannon : public Weapon
{
public:
    string getWeapon() override
    {
        return string("�䱸��������<�Զ�������>...");
    }
};

class Ray : public Weapon
{
public:
    string getWeapon() override
    {
        return string("�䱸��������<����>...");
    }
};

// �ִ���
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
        cout<<"�����ִ�"<<endl;
    }
private:
    ShipBody* m_body = nullptr;
    Weapon* m_weapon = nullptr;
    Engine* m_engine = nullptr;
};

//�촬��Ҫ���������ͺŵĴ�����ôҲ����������Ҫ���������ߣ����Զ�Ӧ�Ĺ�����Ҳ�Ͳ�ֹһ��������˼·����һ���ģ��ṩһ������Ļ��࣬Ȼ����������������ɸ����ͺŵĴ�����װ��ÿ�������Ӧ�ľ���һ�������ߡ�

//���󹤳����ж�����һ�����麯��createShip()�����ڴ�����ֻ����Ȼ���ھ���Ĺ�������ʵ�������������ɴ�ֻ����װ������
class AbstractFactory
{
public:
    virtual Ship* createShip() = 0;
    virtual ~AbstractFactory() {cout<<"���ٹ���"<<endl;}
};

class BasicFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new WoodBody, new Gun, new Human);
        cout << "<������>ս���������, ������ˮ��..." << endl;
        return ship;
    }
};

class StandardFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new IronBody, new Cannon, new Fire);
        cout << "<��׼��>ս���������, ������ˮ��..." << endl;
        return ship;
    }
};

class UltimateFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new MetalBody, new Ray, new Nuclear);
        cout << "<�콢��>ս���������, ������ˮ��..." << endl;
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
