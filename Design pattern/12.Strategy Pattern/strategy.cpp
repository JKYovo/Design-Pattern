#include <iostream>
#include <string>
#include <list>
using namespace std;

// ����Ĳ�����
class AbstractStrategy
{
public:
    virtual void fight(bool isfar = false) = 0;
    virtual ~AbstractStrategy() {}
};

// һ��
class YiDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** ����ʹ�õ���һ��: ";
        if (isfar)
        {
            cout << "�𽺻���ǹ" << endl;
        }
        else
        {
            cout << "�𽺡�������" <<endl;
        }
    }
};

// ����
class ErDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** �л��ɶ���: ";
        if (isfar)
        {
            cout << "��Jet���" << endl;
        }
        else
        {
            cout << "��Jet����Ҵ�" << endl;
        }
    }
};

// ����
class SanDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** �л�������: ";
        if (isfar)
        {
            cout << "�𽺾��˻�����" << endl;
        }
        else
        {
            cout << "�𽺾���ս��" << endl;
        }
    }
};

// �ĵ�
class SiDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** �л����ĵ�: ";
        if (isfar)
        {
            cout << "��ʨ�ӻ����" << endl;
        }
        else
        {
            cout << "��Ϭţ����" << endl;
        }
    }
};

// �嵵
class WuDang : public AbstractStrategy
{
public:
    void fight(bool isfar = false) override
    {
        cout << "*** �л����嵲: ����Ῠ��̬���԰���������, ������ı��������̬������й���!!!" << endl;
    }
};

// �Ѷȼ���
enum class Level:char {Easy, Normal, Hard, Experts, Professional};

// ·��
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