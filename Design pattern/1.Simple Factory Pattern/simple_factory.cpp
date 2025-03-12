#include <iostream>
using namespace std;

// 基类：抽象恶魔果实
class AbstractSmile {
public:
    virtual void transform() = 0; // 纯虚函数：变身
    virtual void ability() = 0;   // 纯虚函数：能力
    virtual ~AbstractSmile() {}   // 虚析构函数，确保正确释放派生类对象
};

// 绵羊形态恶魔果实
class SheepSmile : public AbstractSmile {
public:
    void transform() override {
        cout << "变成人兽 -- 山羊人形态..." << endl;
    }
    void ability() override {
        cout << "将手臂变成绵羊角的招式 -- 巨羊角" << endl;
    }
};

// 狮子形态恶魔果实
class LionSmile : public AbstractSmile {
public:
    void transform() override {
        cout << "变成人兽 -- 狮子人形态..." << endl;
    }
    void ability() override {
        cout << "火遁· 豪火球之术..." << endl;
    }
};

// 蝙蝠形态恶魔果实
class BatSmile : public AbstractSmile {
public:
    void transform() override {
        cout << "变成人兽 -- 蝙蝠人形态..." << endl;
    }
    void ability() override {
        cout << "声纳引箭之万剑归宗..." << endl;
    }
};

// 恶魔果实类型枚举
enum class Type : char {
    SHEEP, // 绵羊形态
    LION,  // 狮子形态
    BAT    // 蝙蝠形态
};

// 恶魔果实工厂类
//  1.强类型枚举的枚举值不会隐式转换为整数，这避免了传统枚举中可能出现的类型安全问题。
//  2.强类型枚举的枚举值的作用域被限制在枚举类内部，避免了传统枚举中可能出现的命名冲突。
class SmileFactory {
public:
    // 创建恶魔果实对象
    AbstractSmile* createSmile(Type type) {
        switch (type) {
            case Type::SHEEP: return new SheepSmile; // 创建绵羊形态
            case Type::LION:  return new LionSmile;  // 创建狮子形态
            case Type::BAT:   return new BatSmile;  // 创建蝙蝠形态
            default: return nullptr;               // 未知类型返回空指针
        }
    }
};

int main() {
    SmileFactory factory; // 创建工厂对象
    AbstractSmile* obj = factory.createSmile(Type::BAT); // 创建蝙蝠形态恶魔果实
    if (obj) {
        obj->transform(); // 变身
        obj->ability();   // 使用能力
        delete obj;       // 释放对象
    }
    return 0;
}

//在上面的工厂函数中需要生成三种人造恶魔果实，现在如果想要生成更多，那么就需要在工厂函数的switch语句中添加更多的case，很明显这违背了封闭原则，也就意味着需要基于开放原则来解决这个问题。

