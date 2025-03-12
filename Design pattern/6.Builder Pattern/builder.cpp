#include <iostream>
#include <vector>
#include <map>
using namespace std;

// ɣ���
class SunnyShip
{
public:
    // ������
    void addParts(string name)
    {
        m_parts.push_back(name);
    }
    void showParts()
    {
        for (const auto& item : m_parts)
        {
            cout << item << "   ";
        }
        cout << endl;
    }
private:
    vector<string> m_parts;
};

// ÷����
class MerryShip
{
public:
    // ��װ
    void assemble(string name, string parts)
    {
        m_patrs.insert(make_pair(name, parts));
    }
    void showParts()
    {
        for (const auto& item : m_patrs)
        {
            cout << item.first << ": " << item.second << "  ";
        }
        cout << endl;
    }
private:
    map<string, string> m_patrs;
};

// ��������
class ShipBuilder
{
public:
    virtual void reset() = 0;
    virtual void buildBody() = 0;
    virtual void buildWeapon() = 0;
    virtual void buildEngine() = 0;
    virtual void buildInterior() = 0;
    virtual ~ShipBuilder() {}
};

// ɣ���������
class SunnyBuilder : public ShipBuilder
{
public:
    SunnyBuilder()
    {
        reset();
    }
    ~SunnyBuilder()
    {
        if (m_sunny != nullptr)
        {
            delete m_sunny;
        }
    }
    // �ṩ���ú���, Ŀ�����ܹ�ʹ���������������ɶ����Ʒ
    void reset() override
    {
        m_sunny = new SunnyShip;
    }
    void buildBody() override
    {
        m_sunny->addParts("�����ǵ�������");
    }
    void buildWeapon() override
    {
        m_sunny->addParts("ʨ����");
    }
    void buildEngine() override
    {
        m_sunny->addParts("��������");
    }
    void buildInterior() override
    {
        m_sunny->addParts("�������Ҿ�װ");
    }
    SunnyShip* getSunny()
    {
        SunnyShip* ship = m_sunny;
        m_sunny = nullptr;
        return ship;
    }
private:
    SunnyShip* m_sunny = nullptr;// ���ɵĲ�Ʒ
};

// ÷����������
class MerryBuilder : public ShipBuilder
{
public:
    MerryBuilder()
    {
        reset();
    }
    ~MerryBuilder()
    {
        if (m_merry != nullptr)
        {
            delete m_merry;
        }
    }
    void reset() override
    {
        m_merry = new MerryShip;
    }
    void buildBody() override
    {
        m_merry->assemble("����", "����ľ��");
    }
    void buildWeapon() override
    {
        m_merry->assemble("����", "���Ŵ���");
    }
    void buildEngine() override
    {
        m_merry->assemble("����", "������");
    }
    void buildInterior() override
    {
        m_merry->assemble("����", "��װ");
    }
    MerryShip* getMerry()
    {
        MerryShip* ship = m_merry;
        m_merry = nullptr;
        return ship;
    }
private:
    MerryShip* m_merry = nullptr;
};

// ������
class Director
{
public:
    void setBuilder(ShipBuilder* builder)   //ͨ�����������Ͷ���Ϊ ShipBuilder*������Խ����κ� ShipBuilder ������������� SunnyBuilder��MerryBuilder �ȣ���
                                            //������setBuilder �����������Խ��� SunnyBuilder�������Խ�������δ������ʵ�ֵ��������
    {
        m_builder = builder;
    }
    // ��Լ��
    void builderSimpleShip()
    {
        m_builder->buildBody();
        m_builder->buildEngine();
    }
    // ��׼��
    void builderStandardShip()
    {
        builderSimpleShip();
        m_builder->buildWeapon();
    }
    // ������
    void builderRegalShip()
    {
        builderStandardShip();
        m_builder->buildInterior();
    }
private:
    ShipBuilder* m_builder = nullptr;
};

// ����ɣ���
void builderSunny()
{
    Director* director = new Director;
    SunnyBuilder* builder = new SunnyBuilder;
    // ��Լ��
    director->setBuilder(builder);
    director->builderSimpleShip();
    SunnyShip* sunny = builder->getSunny();
    sunny->showParts();
    delete sunny;

    // ��׼��
    builder->reset();
    director->setBuilder(builder);
    director->builderStandardShip();
    sunny = builder->getSunny();
    sunny->showParts();
    delete sunny;

    // ������
    builder->reset();
    director->setBuilder(builder);
    director->builderRegalShip();
    sunny = builder->getSunny();
    sunny->showParts();
    delete sunny;
    delete builder;
    delete director;
}

// ����÷����
void builderMerry()
{
    Director* director = new Director;
    MerryBuilder* builder = new MerryBuilder;
    // ��Լ��
    director->setBuilder(builder);
    director->builderSimpleShip();
    MerryShip* merry = builder->getMerry();
    merry->showParts();
    delete merry;

    // ��׼��
    builder->reset();
    director->setBuilder(builder);
    director->builderStandardShip();
    merry = builder->getMerry();
    merry->showParts();
    delete merry;

    // ������
    builder->reset();
    director->setBuilder(builder);
    director->builderRegalShip();
    merry = builder->getMerry();
    merry->showParts();
    delete merry;
    delete builder;
    delete director;
}

int main()
{
    // builderSunny();
    // cout << "=====================================" << endl;
    // builderMerry();
    SunnyBuilder *builder = new SunnyBuilder;//�������ʹ��ShipBuilder *builder = new SunnyBuilder;��ôSunnyShip *sunny = builder->getSunny();�ᱨ����Ϊ���ǻ����������ĺ��������Ҫ��ôд�Ļ�Ҫд���麯��������ʵ��
    builder->buildBody();
    builder->buildEngine();
    builder->buildWeapon();
    builder->buildInterior();
    SunnyShip *sunny = builder->getSunny();
    sunny->showParts();
}
