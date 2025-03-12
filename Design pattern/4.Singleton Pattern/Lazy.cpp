#include <iostream>
#include <mutex>
using namespace std;

// 懒汉模式, 懒汉模式是在类加载的时候不去创建这个唯一的实例，而是在需要使用的时候再进行实例化
class LazyTaskQueue
{
public:
    // = delete 代表函数禁用, 也可以将其访问权限设置为私有
    LazyTaskQueue(const LazyTaskQueue& obj) = delete;
    LazyTaskQueue& operator=(const LazyTaskQueue& obj) = delete;
    static LazyTaskQueue* getInstance()//有线程安全问题，使用互斥锁
    {
        m_mutex.lock();
        if(m_taskQ == nullptr){
            lock_guard<mutex> lock(m_mutex); // 加锁，使用 lock_guard 管理互斥锁，确保锁在作用域结束时自动释放。
            //m_mutex.lock();//双重检查，防止多次上锁解锁
            if (m_taskQ == nullptr)
            {
                m_taskQ = new LazyTaskQueue;
            }
           // m_mutex.unlock();
        }
        
        return m_taskQ;
    }
private:
    LazyTaskQueue() = default;
    static LazyTaskQueue* m_taskQ;
    static mutex m_mutex;
};
LazyTaskQueue* LazyTaskQueue::m_taskQ = nullptr;
mutex LazyTaskQueue::m_mutex;


