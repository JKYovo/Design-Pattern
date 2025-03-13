#include <list>
#include <string>
#include <iostream>
using namespace std;

// 声明订阅者类, 只是做了声明, 并没有包含这个类的头文件
class Observer;
// 新闻社
class NewsAgency
{
public:
    void attach(Observer* ob);          //添加订阅者
    void deatch(Observer* ob);          //删除订阅者
    virtual void notify(string msg) = 0;//通知订阅者
    virtual ~NewsAgency() {};
protected:
    list<Observer*> m_list;             // 订阅者列表
};

// 摩根斯的新闻社
class Morgans : public NewsAgency
{
public:
    void notify(string msg) override;
};


