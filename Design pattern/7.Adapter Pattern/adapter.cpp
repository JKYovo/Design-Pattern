#include <iostream>
#include <vector>
#include <map>
using namespace std;

//��������������֮�������������һ����Ľӿ�ת���ɿͻ�ϣ��������һ���ӿڡ�
//������ģʽ����Щ�������ڽӿڲ����ݶ�����һ�����������һ������
class Foreigner
{
public:
    virtual string confession() = 0; //��
    void setResult(string msg)  // ��
    {
        cout << "Panda Say: " << msg << endl;
    }
    virtual ~Foreigner() {}
};

// ������
class American : public Foreigner
{
public:
    string confession() override
    {
        return string("��������, ������!!!");
    }
};

// ������
class French : public Foreigner
{
public:
    string confession()
    {
        return string("����ǿ��, �Ҹ���!!!");
    }
};

// ����è
class Panda
{
public:
    void recvMessage(string msg) //��
    {
        cout << msg << endl;
    }
    string sendMessage() //��
    {
        return string("ǿ�������֡������ǲ����ܱ���ˡ��ԭ�µģ�");
    }
};

// �����ǰ���������
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

// Ӣ���ǰ�������
class EnglishChopper : public AbstractChopper
{
public:
    // �̳й��캯��
    using AbstractChopper::AbstractChopper;
    void translateToPanda() override
    {
        string msg = m_foreigner->confession();
        // ���벢����Ϣ���ݸ���è����
        m_panda.recvMessage("������˵: " + msg);
    }
    void translateToHuman() override
    {
        // ������è����Ϣ
        string msg = m_panda.sendMessage();
        // ���벢����è�Ļ�ת����������
        m_foreigner->setResult("������, " + msg);
    }
};

// �����ǰ�������
class FrenchChopper : public AbstractChopper
{
public:
    using AbstractChopper::AbstractChopper;
    void translateToPanda() override
    {
        string msg = m_foreigner->confession();
        // ���벢����Ϣ���ݸ���è����
        m_panda.recvMessage("������˵: " + msg);
    }
    void translateToHuman() override
    {
        // ������è����Ϣ
        string msg = m_panda.sendMessage();
        // ���벢����è�Ļ�ת����������
        m_foreigner->setResult("������, " + msg);
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
