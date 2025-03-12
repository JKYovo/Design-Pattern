#include <iostream>
using namespace std;

// 饿汉模式, 饿汉模式就是在类加载的时候立刻进行实例化
class HungryTaskQueue
{
public:
    // = delete 代表函数禁用, 也可以将其访问权限设置为私有
    HungryTaskQueue(const HungryTaskQueue& obj) = delete;
    HungryTaskQueue& operator=(const HungryTaskQueue& obj) = delete;
    static HungryTaskQueue* getInstance()
    {
        return m_taskQ;
    }
private:
    HungryTaskQueue() = default;
    static HungryTaskQueue* m_taskQ;//为什么类里面有他自己的指针？
    //在单例模式中，类的唯一实例通常通过一个静态指针来维护。
    //这个指针指向类的唯一实例，并且在类的生命周期内保持不变。
    //通过这种方式，可以确保无论在哪里调用 getInstance 方法，返回的都是同一个实例。
};
// 静态成员初始化放到类外部处理
HungryTaskQueue* HungryTaskQueue::m_taskQ = new HungryTaskQueue;

int main()
{
    HungryTaskQueue* obj = HungryTaskQueue::getInstance();
}