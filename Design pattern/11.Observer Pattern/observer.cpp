#include "NewsAgency.h"
//#include "Observer.h"	// 在源文件中包含该头文件
#include <iostream>
using namespace std;

//新闻社更新订阅者就会发出通知


void NewsAgency::attach(Observer* ob)
{
    m_list.push_back(ob);
}

void NewsAgency::deatch(Observer* ob)
{
    m_list.remove(ob);
}

void Morgans::notify(string msg)
{
    cout << "摩根斯新闻社报纸的订阅者一共有<" << m_list.size() << ">人" << endl;
    for (const auto& item : m_list)
    {
        item->update(msg);	// 订阅者类的定义在下面
    }
}

// 抽象的订阅者类
class Observer
{
public:
    Observer(string name, NewsAgency* news) :m_name(name), m_news(news) 
    {
        m_news->attach(this);//把自己添加到订阅者列表
    }
    void unsubscribe()
    {
        m_news->deatch(this);//把自己从订阅者列表中删除
    }
    virtual void update(string msg) = 0;
    virtual ~Observer() {}
protected:
    string m_name;//订阅者名字
    NewsAgency* m_news;//新闻社
};

class Dragon : public Observer
{
public:
    using Observer::Observer;
    void update(string msg) override
    {
        cout << "@@@路飞的老爸革命军龙收到消息: " << msg << endl;
    }
};

int main()
{
    Morgans* ms = new Morgans;
    //Gossip* gossip = new Gossip;
    Dragon* dragon = new Dragon("蒙奇·D·龙", ms);
    //Shanks* shanks = new Shanks("香克斯", ms);
    //Bartolomeo* barto = new Bartolomeo("巴托洛米奥", gossip);
    ms->notify("蒙奇·D·路飞成为新世界的新的四皇之一, 赏金30亿贝里!!!");//新闻社使用notify()发布消息，订阅队列里的订阅者就会调用update方法
    //cout << "======================================" << endl;
    //gossip->notify("女帝汉库克想要嫁给路飞, 给路飞生猴子, 哈哈哈...");

    delete ms;
    //delete gossip;
    delete dragon;
    //delete shanks;
    //delete barto;

    return 0;
}
