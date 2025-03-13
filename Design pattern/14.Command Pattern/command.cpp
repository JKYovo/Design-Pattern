#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

// ��ʦ����
class CookerZeff
{
public:
    void makeDSX()
    {
        cout << "��ʼ��⿵�����...";
    }
    void makeGBJD()
    {
        cout << "��ʼ��⿹�������...";
    }
    void makeYXRS()
    {
        cout << "��ʼ���������˿...";
    }
    void makeHSPG()
    {
        cout << "��ʼ��⿺����Ź�...";
    }
};

// ��͵����� - ������
class AbstractCommand
{
public:
    AbstractCommand(CookerZeff* receiver) : m_cooker(receiver) {}
    virtual void excute() = 0;  // ִ������
    virtual string name() = 0;
    ~AbstractCommand() {}
protected:
    CookerZeff* m_cooker = nullptr; // ��ʦ
};

class DSXCommand : public AbstractCommand
{
public:
    DSXCommand(CookerZeff* receiver) : AbstractCommand(receiver) {}
    void excute() override
    {
        m_cooker->makeDSX();
    }
    string name() override
    {
        return "������";
    }
};

class GBJDCommand : public AbstractCommand
{   
public:
    GBJDCommand(CookerZeff* receiver) : AbstractCommand(receiver) {}
    void excute() override
    {
        m_cooker->makeGBJD();
    }
    string name() override
    {
        return "��������";
    }
};

class YXRSCommand : public AbstractCommand
{
public:
    YXRSCommand(CookerZeff* receiver) : AbstractCommand(receiver) {}
    void excute() override
    {
        m_cooker->makeYXRS();
    }
    string name() override
    {
        return "������˿";
    }
};

class HSPGCommand : public AbstractCommand
{
public:
    HSPGCommand(CookerZeff* receiver) : AbstractCommand(receiver) {}
    void excute() override
    {
        m_cooker->makeHSPG();
    }
    string name() override
    {
        return "�����Ź�";
    }
};

// ������·�� - ����ĵ�����
class WaiterLuffy
{
public:
    // �µ�
    void setOrder(int index, AbstractCommand* cmd)
    {
        cout << index << "��������" << cmd->name() << endl;
        if (cmd->name() == "������˿")
        {
            cout << "û������, ������������˿, �����Ĳ˰�..." << endl;
            return;
        }
        // û�ҵ��ù˿�,����˿��ǵ�һ�ε��
        if (m_cmdList.find(index) == m_cmdList.end())
        {
            list<AbstractCommand*> mylist{ cmd };
            m_cmdList.insert(make_pair(index, mylist));
        }
        else//�˿�Ҫ�������
        {
            m_cmdList[index].push_back(cmd);
        }
    }
    // ȡ������
    void cancelOrder(int index, AbstractCommand* cmd)
    {
        if (m_cmdList.find(index) != m_cmdList.end())
        {
            m_cmdList[index].remove(cmd);
            cout << index << "����, ������" << cmd->name() << endl;
        }
    }
    // ����
    void checkOut(int index)
    {
        cout << "��[" << index << "]�����Ĺ˿͵�Ĳ���: ��";
        for (const auto& item : m_cmdList[index])
        {
            cout << item->name();
            if (item != m_cmdList[index].back())
            {
                cout << ", ";
            }
        }
        cout << "��" << endl;
    }
    void notify(int index)
    {
        for (const auto& item : m_cmdList[index])
        {
            item->excute();
            cout << index << "����" << endl;
        }
    }
private:
    // �洢�˿͵��µ���Ϣ
    map<int, list<AbstractCommand*>> m_cmdList;
};

int main()
{
    CookerZeff* cooker = new CookerZeff;
    WaiterLuffy* luffy = new WaiterLuffy;

    YXRSCommand* yxrs = new YXRSCommand(cooker);
    GBJDCommand* gbjd = new GBJDCommand(cooker);
    DSXCommand* dsx = new DSXCommand(cooker);
    HSPGCommand* hspg = new HSPGCommand(cooker);

    cout << "=================== ��ʼ��� ===================" << endl;
    luffy->setOrder(1, yxrs);
    luffy->setOrder(1, dsx);
    luffy->setOrder(1, gbjd);
    luffy->setOrder(1, hspg);
    luffy->setOrder(2, dsx);
    luffy->setOrder(2, gbjd);
    luffy->setOrder(2, hspg);
    cout << "=================== �������� ===================" << endl;
    luffy->cancelOrder(1, dsx);
    cout << "=================== ��ʼ��� ===================" << endl;
    luffy->notify(1);
    luffy->notify(2);
    cout << "=================== ���� ===================" << endl;
    luffy->checkOut(1);
    luffy->checkOut(2);

    return 0;
}
