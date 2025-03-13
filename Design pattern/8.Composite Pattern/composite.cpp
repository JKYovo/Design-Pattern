#include <iostream>
#include <vector>
#include <map>
#include <list>
using namespace std;

// ����ڵ�
class AbstractTeam
{
public:
    AbstractTeam(string name) :m_name(name) {}
    // ���ø��ڵ�
    void setParent(AbstractTeam* node)
    {
        m_parent = node;
    }
    AbstractTeam* getParent()
    {
        return m_parent;
    }
    string getName()
    {
        return m_name;
    }
    virtual bool hasChild()
    {
        return false;
    }
    virtual void add(AbstractTeam* node) {} // ��ӽڵ�
    virtual void remove(AbstractTeam* node) {} // �Ƴ��ڵ�
    virtual void fight() = 0; // ��ս
    virtual void display() = 0; // ��ʾ�ڵ���Ϣ
    virtual ~AbstractTeam() {}
protected:
    string m_name;
    AbstractTeam* m_parent = nullptr;
};

// Ҷ�ӽڵ��С�ӣ���Ҫ�̳г���ڵ�
class LeafTeam : public AbstractTeam
{
public:
    using AbstractTeam::AbstractTeam;
    void fight() override
    {
        cout << m_parent->getName() + m_name + "��ں��ӵĴ�Ա���н������ⲫս..." << endl;
    }
    void display() override
    {
        cout << "����" << m_parent->getName() << "������" << m_name << endl;
    }
    ~LeafTeam()
    {
        cout << "����" << m_parent->getName() << "������" << m_name 
            << ", ս���Ѿ�����, �ݰ�..." << endl;
    }
};

// ��Ͻڵ��С�ӣ������ߣ�����Ҫ�̳г���ڵ�
class ManagerTeam : public AbstractTeam
{
public:
    using AbstractTeam::AbstractTeam;
    void fight() override
    {
        cout << m_name + "�ͺں��ӵĶ�ħ��ʵ������ս��!!!" << endl;
    }
    void add(AbstractTeam* node) override
    {
        node->setParent(this); //thisָ��ָ��ǰ����
        m_children.push_back(node);
    }
    void remove(AbstractTeam* node) override
    {
        node->setParent(nullptr);
        m_children.remove(node);
    }
    bool hasChild()
    {
        return true;
    }
    list<AbstractTeam*> getChildren()
    {
        return m_children;
    }
    void display()
    {
        string info = string();
        for (const auto item : m_children)
        {
            if (item == m_children.back())
            {
                info += item->getName();
            }
            else
            {
                // ���ȼ�: + > +=
                info += item->getName() + ", ";
            }
        }
        cout << m_name + "�Ĵ����ǡ�" << info << "��" << endl;
    }
    ~ManagerTeam()
    {
        cout << "���ǡ�" << m_name << "��ս������, �ݰ�..." << endl;
    }
private:
    list<AbstractTeam*> m_children;
};

// �ڴ��ͷ�
void gameover(AbstractTeam* root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root && root->hasChild())
    {
        ManagerTeam* team = dynamic_cast<ManagerTeam*>(root); //dynamic_cast ��һ������ʱ������ת������Ҫ�����ڼ̳в�νṹ�н��а�ȫ������ת�ͣ��ӻ���ָ��ת��Ϊ������ָ�룩��
        list<AbstractTeam*> children = team->getChildren();
        for (const auto item : children)
        {
            gameover(item);
        }
    }
    delete root;
}

// �ͺں���ս��
void fighting()
{
    vector<string> nameList = {
        "����������", "���о��ֲ�", "�˱�ˮ��", "����ŷ������",
        "������������", "�ޱ�������", "Լ�������Ǵ���"
    };
    // ���ڵ�
    ManagerTeam* root = new ManagerTeam("��ñ������");
    for (int i = 0; i < nameList.size(); ++i)
    {
        ManagerTeam* child = new ManagerTeam(nameList.at(i));
        root->add(child);
        if (i == nameList.size() - 1)
        {
            // �����һ������(Լ�������Ǵ���)����Ӵ���
            for (int j = 0; j < 9; ++j)
            {
                LeafTeam* leaf = new LeafTeam("��" + to_string(j + 1) + "����");
                child->add(leaf);
                leaf->fight();
                leaf->display();
            }
            child->fight();
            child->display();
        }
    }
    root->fight();
    root->display();

    cout << "====================================" << endl;
    gameover(root);
}

int main()
{
    fighting();
    return 0;
}
