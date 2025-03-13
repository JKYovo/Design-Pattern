#include <iostream>
#include <string>
#include <list>
using namespace std;

// �����������
class AbstractRobot
{
public:
    // ����
    virtual void weapon() = 0;
    // ���
    virtual void appearance() = 0;
    // ս������
    virtual void fightAbility() = 0;
    // ����
    virtual string getName() = 0;
    // ��������
    virtual void selfHealing() {};
    // �Ƿ��ܷ�
    virtual bool canFlying()
    {
        return false;
    }
    // �Ƿ����Զ�����
    virtual bool isAuto()
    {
        return true;
    }
    // �õ�����������
    virtual void getProperty()
    {
        cout << "�����ӿ������" << getName() << "����������: " << endl;
        if (canFlying())
        {
            cout << "�з�������!" << endl;
        }
        else
        {
            cout << "û�з�������!" << endl;
        }
        if (isAuto())
        {
            cout << "�����Զ�����, ��ȫ�������!" << endl;
        }
        else
        {
            cout << "�����Զ�����, ���Զ�������!" << endl;
        }
        weapon();
        appearance();
        fightAbility();
        selfHealing();
    }
};

// ��ƽ������
class Pacifist : public AbstractRobot
{
public:
    // ����
    void weapon() override
    {
        cout << "���Է��������..." << endl;
    }
    // ���
    void appearance() override
    {
        cout << "�ⲿ�Ͱ������ס���һ��, �����Ӵ�ӵ�гʰ�Բ�εĶ��䣬�ڲ��ƺ�������" << endl;
    }
    // ����
    void fightAbility() override
    {
        cout << "��ʵ����, ����ͨ���ֲ������첿�������伤��, �����ڻ�����!!!" << endl;
    }
    string getName() override
    {
        return "��ƽ������";
    }
};

// ����ʹ
class Seraphim : public AbstractRobot
{
public:
    // ����
    void weapon() override
    {
        cout << "���Է������伤��, ӥ�����εĳ���ʹЯ����һ�Ѿ޽�, ����ն��һ��!!!" << endl;
    }
    // ���
    void appearance() override
    {
        cout << "��ۺ����亣Сʱ�������һ��, ����ӵ��һ�Ժͽ�һ���ĳ��!!!" << endl;
    }
    // ����
    void fightAbility() override
    {
        cout << "�������Է������伤��, ��ӵ�����亣������, ţ��plus, �޵���!!!!" << endl;
    }
    // ��������
    void selfHealing() override
    {
        cout << "�ǳ���ʵ����, ����ӵ�зǳ�ǿ����������, ������!!!" << endl;
    }
    // �Ƿ��ܷ�
    bool canFlying() override
    {
        return true;
    }
    string getName() override
    {
        return "����ʹ";
    }
};

int main()
{
    AbstractRobot* robot = nullptr;
    robot = new Pacifist;
    robot->getProperty();
    delete robot;
    cout << "====================================" << endl;
    robot = new Seraphim; 
    robot->getProperty();
    delete robot;
    return 0;
}

