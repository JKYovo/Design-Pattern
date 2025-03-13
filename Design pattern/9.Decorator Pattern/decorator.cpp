//装饰模式也可以称之为封装模式，所谓的封装就是在原有行为之上进行拓展，并不会改变该行为的基本特性。
//装饰模式是一种用于替代继承的技术，它通过一种无须定义子类的方式来给对象动态增加职责，使用对象之间的关联关系取代类之间的继承关系。
#include <iostream>
#include <string>
using namespace std;

// 战士的抽象类
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

// 黑胡子(Marshall·D·Teach)
class Teach : public Soldier
{
public:
    using Soldier::Soldier;
    void fight() override
    {
        cout << m_name << "依靠惊人的力量和高超的体术战斗..." << endl;
    }
};

// 抽象的恶魔果实(装饰器)
class DevilFruit : public Soldier
{
public:
    // 指定要给哪个人吃恶魔果实 -- 附魔
    void enchantment(Soldier* soldier)
    {
        m_human = soldier;
        m_name = m_human->getName();
    }
    virtual ~DevilFruit() {}
protected:
    Soldier* m_human = nullptr;
};

// 暗暗果实
class DarkFruit : public DevilFruit
{
public:
    void fight() override
    {
        m_human->fight(); //调用了普通士兵的fight方法
        // 使用当前恶魔果实的能力
        cout << m_human->getName() 
            << "吃了暗暗果实, 可以拥有黑洞一样的无限吸引力..." << endl;
        warning();
    }
private:
    void warning()
    {
        cout << m_human->getName() 
            << "你要注意: 吃了暗暗果实, 身体元素化之后不能躲避攻击，会吸收所有伤害!" << endl;
    }
};

// 震震果实
class QuakeFruit : public DevilFruit
{
public:
    void fight() override
    {
        m_human->fight();
        cout << m_human->getName() 
            << "吃了震震果实, 可以在任意空间引发震动, 摧毁目标...!" << endl;
    }
};

//使用装饰模式，可以非常方便地给任意一个战士增加战斗技能，而无需修改原有代码，完全符合开放 – 封闭原则。
// 大饼果实
class PieFruit : public DevilFruit
{
public:
    void fight() override
    {
        m_human->fight();
        cout << m_human->getName()
            << "吃了大饼果实, 获得大饼铠甲...!" << endl;
        ability();
    }

    void ability()//新能力
    {
        cout << "最强辅助 -- 大饼果实可以将身边事物变成大饼, 帮助自己和队友回血..." << endl;
    }
};

int main(){
    Soldier *man = new Teach("蒂奇");
    DarkFruit *dark = new DarkFruit();
    QuakeFruit* quake = new QuakeFruit;
    PieFruit* pie = new PieFruit;

    dark->enchantment(man);//此时，dark 持有一个指向 man 的指针
    quake->enchantment(dark);//此时，quake 持有一个指向 dark 的指针
    pie->enchantment(quake);//此时，pie 持有一个指向 quake 的指针
    //dark->fight();
    //quake->fight();
    pie->fight();
}
// 层层装饰
// pie->fight()
//   |
//   +-- quake->fight()
//         |
//         +-- dark->fight()
//               |
//               +-- man->fight()