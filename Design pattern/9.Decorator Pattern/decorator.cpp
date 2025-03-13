//װ��ģʽҲ���Գ�֮Ϊ��װģʽ����ν�ķ�װ������ԭ����Ϊ֮�Ͻ�����չ��������ı����Ϊ�Ļ������ԡ�
//װ��ģʽ��һ����������̳еļ�������ͨ��һ�����붨������ķ�ʽ��������̬����ְ��ʹ�ö���֮��Ĺ�����ϵȡ����֮��ļ̳й�ϵ��
#include <iostream>
#include <string>
using namespace std;

// սʿ�ĳ�����
class Soldier
{
public:
    Soldier() {}
    Soldier(string name) : m_name(name) {}
    string getName() 
    { 
        return m_name;
    };
    virtual void fight() = 0;
    virtual ~Soldier() {}
protected:
    string m_name = string();
};

// �ں���(Marshall��D��Teach)
class Teach : public Soldier
{
public:
    using Soldier::Soldier;
    void fight() override
    {
        cout << m_name << "�������˵������͸߳�������ս��..." << endl;
    }
};

// ����Ķ�ħ��ʵ(װ����)
class DevilFruit : public Soldier
{
public:
    // ָ��Ҫ���ĸ��˳Զ�ħ��ʵ -- ��ħ
    void enchantment(Soldier* soldier)
    {
        m_human = soldier;
        m_name = m_human->getName();
    }
    virtual ~DevilFruit() {}
protected:
    Soldier* m_human = nullptr;
};

// ������ʵ
class DarkFruit : public DevilFruit
{
public:
    void fight() override
    {
        m_human->fight(); //��������ͨʿ����fight����
        // ʹ�õ�ǰ��ħ��ʵ������
        cout << m_human->getName() 
            << "���˰�����ʵ, ����ӵ�кڶ�һ��������������..." << endl;
        warning();
    }
private:
    void warning()
    {
        cout << m_human->getName() 
            << "��Ҫע��: ���˰�����ʵ, ����Ԫ�ػ�֮���ܶ�ܹ����������������˺�!" << endl;
    }
};

// �����ʵ
class QuakeFruit : public DevilFruit
{
public:
    void fight() override
    {
        m_human->fight();
        cout << m_human->getName() 
            << "���������ʵ, ����������ռ�������, �ݻ�Ŀ��...!" << endl;
    }
};

//ʹ��װ��ģʽ�����Էǳ�����ظ�����һ��սʿ����ս�����ܣ��������޸�ԭ�д��룬��ȫ���Ͽ��� �C ���ԭ��
// �����ʵ
class PieFruit : public DevilFruit
{
public:
    void fight() override
    {
        m_human->fight();
        cout << m_human->getName()
            << "���˴����ʵ, ��ô������...!" << endl;
        ability();
    }

    void ability()//������
    {
        cout << "��ǿ���� -- �����ʵ���Խ���������ɴ��, �����Լ��Ͷ��ѻ�Ѫ..." << endl;
    }
};

int main(){
    Soldier *man = new Teach("����");
    DarkFruit *dark = new DarkFruit();
    QuakeFruit* quake = new QuakeFruit;
    PieFruit* pie = new PieFruit;

    dark->enchantment(man);//��ʱ��dark ����һ��ָ�� man ��ָ��
    quake->enchantment(dark);//��ʱ��quake ����һ��ָ�� dark ��ָ��
    pie->enchantment(quake);//��ʱ��pie ����һ��ָ�� quake ��ָ��
    //dark->fight();
    //quake->fight();
    pie->fight();
}
// ���װ��
// pie->fight()
//   |
//   +-- quake->fight()
//         |
//         +-- dark->fight()
//               |
//               +-- man->fight()