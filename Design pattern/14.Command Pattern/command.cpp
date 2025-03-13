#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

// 厨师哲普
class CookerZeff
{
public:
    void makeDSX()
    {
        cout << "开始烹饪地三鲜...";
    }
    void makeGBJD()
    {
        cout << "开始烹饪宫保鸡丁...";
    }
    void makeYXRS()
    {
        cout << "开始烹饪鱼香肉丝...";
    }
    void makeHSPG()
    {
        cout << "开始烹饪红烧排骨...";
    }
};

// 点餐的命令 - 抽象类
class AbstractCommand
{
public:
    AbstractCommand(CookerZeff* receiver) : m_cooker(receiver) {}
    virtual void excute() = 0;  // 执行命令
    virtual string name() = 0;
    ~AbstractCommand() {}
protected:
    CookerZeff* m_cooker = nullptr; // 厨师
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
        return "地三鲜";
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
        return "宫保鸡丁";
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
        return "鱼香肉丝";
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
        return "红烧排骨";
    }
};

// 服务器路飞 - 命令的调用者
class WaiterLuffy
{
public:
    // 下单
    void setOrder(int index, AbstractCommand* cmd)
    {
        cout << index << "号桌点了" << cmd->name() << endl;
        if (cmd->name() == "鱼香肉丝")
        {
            cout << "没有鱼了, 做不了鱼香肉丝, 点个别的菜吧..." << endl;
            return;
        }
        // 没找到该顾客,这个顾客是第一次点餐
        if (m_cmdList.find(index) == m_cmdList.end())
        {
            list<AbstractCommand*> mylist{ cmd };
            m_cmdList.insert(make_pair(index, mylist));
        }
        else//顾客要继续点餐
        {
            m_cmdList[index].push_back(cmd);
        }
    }
    // 取消订单
    void cancelOrder(int index, AbstractCommand* cmd)
    {
        if (m_cmdList.find(index) != m_cmdList.end())
        {
            m_cmdList[index].remove(cmd);
            cout << index << "号桌, 撤销了" << cmd->name() << endl;
        }
    }
    // 结账
    void checkOut(int index)
    {
        cout << "第[" << index << "]号桌的顾客点的菜是: 【";
        for (const auto& item : m_cmdList[index])
        {
            cout << item->name();
            if (item != m_cmdList[index].back())
            {
                cout << ", ";
            }
        }
        cout << "】" << endl;
    }
    void notify(int index)
    {
        for (const auto& item : m_cmdList[index])
        {
            item->excute();
            cout << index << "号桌" << endl;
        }
    }
private:
    // 存储顾客的下单信息
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

    cout << "=================== 开始点餐 ===================" << endl;
    luffy->setOrder(1, yxrs);
    luffy->setOrder(1, dsx);
    luffy->setOrder(1, gbjd);
    luffy->setOrder(1, hspg);
    luffy->setOrder(2, dsx);
    luffy->setOrder(2, gbjd);
    luffy->setOrder(2, hspg);
    cout << "=================== 撤销订单 ===================" << endl;
    luffy->cancelOrder(1, dsx);
    cout << "=================== 开始烹饪 ===================" << endl;
    luffy->notify(1);
    luffy->notify(2);
    cout << "=================== 结账 ===================" << endl;
    luffy->checkOut(1);
    luffy->checkOut(2);

    return 0;
}
