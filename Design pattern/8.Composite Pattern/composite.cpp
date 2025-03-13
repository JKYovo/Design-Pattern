#include <iostream>
#include <vector>
#include <map>
#include <list>
using namespace std;

// 抽象节点
class AbstractTeam
{
public:
    AbstractTeam(string name) :m_name(name) {}
    // 设置父节点
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
    virtual void add(AbstractTeam* node) {} // 添加节点
    virtual void remove(AbstractTeam* node) {} // 移除节点
    virtual void fight() = 0; // 作战
    virtual void display() = 0; // 显示节点信息
    virtual ~AbstractTeam() {}
protected:
    string m_name;
    AbstractTeam* m_parent = nullptr;
};

// 叶子节点的小队，需要继承抽象节点
class LeafTeam : public AbstractTeam
{
public:
    using AbstractTeam::AbstractTeam;
    void fight() override
    {
        cout << m_parent->getName() + m_name + "与黑胡子的船员进行近距离肉搏战..." << endl;
    }
    void display() override
    {
        cout << "我是" << m_parent->getName() << "下属的" << m_name << endl;
    }
    ~LeafTeam()
    {
        cout << "我是" << m_parent->getName() << "下属的" << m_name 
            << ", 战斗已经结束, 拜拜..." << endl;
    }
};

// 组合节点的小队（管理者），需要继承抽象节点
class ManagerTeam : public AbstractTeam
{
public:
    using AbstractTeam::AbstractTeam;
    void fight() override
    {
        cout << m_name + "和黑胡子的恶魔果实能力者战斗!!!" << endl;
    }
    void add(AbstractTeam* node) override
    {
        node->setParent(this); //this指针指向当前对象
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
                // 优先级: + > +=
                info += item->getName() + ", ";
            }
        }
        cout << m_name + "的船队是【" << info << "】" << endl;
    }
    ~ManagerTeam()
    {
        cout << "我是【" << m_name << "】战斗结束, 拜拜..." << endl;
    }
private:
    list<AbstractTeam*> m_children;
};

// 内存释放
void gameover(AbstractTeam* root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root && root->hasChild())
    {
        ManagerTeam* team = dynamic_cast<ManagerTeam*>(root); //dynamic_cast 是一种运行时的类型转换，主要用于在继承层次结构中进行安全的向下转型（从基类指针转换为派生类指针）。
        list<AbstractTeam*> children = team->getChildren();
        for (const auto item : children)
        {
            gameover(item);
        }
    }
    delete root;
}

// 和黑胡子战斗
void fighting()
{
    vector<string> nameList = {
        "俊美海贼团", "巴托俱乐部", "八宝水军", "艾迪欧海贼团",
        "咚塔塔海贼团", "巨兵海贼团", "约塔玛利亚大船团"
    };
    // 根节点
    ManagerTeam* root = new ManagerTeam("草帽海贼团");
    for (int i = 0; i < nameList.size(); ++i)
    {
        ManagerTeam* child = new ManagerTeam(nameList.at(i));
        root->add(child);
        if (i == nameList.size() - 1)
        {
            // 给最后一个番队(约塔玛利亚大船团)添加子船队
            for (int j = 0; j < 9; ++j)
            {
                LeafTeam* leaf = new LeafTeam("第" + to_string(j + 1) + "番队");
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
