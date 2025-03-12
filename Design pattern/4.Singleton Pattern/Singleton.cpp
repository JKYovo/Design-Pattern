#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
using namespace std;

class TaskQueue
{
public:
    // = delete 代表函数禁用, 也可以将其访问权限设置为私有
    TaskQueue(const TaskQueue& obj) = delete;
    TaskQueue& operator=(const TaskQueue& obj) = delete;
    static TaskQueue* getInstance()
    {
        return &m_obj;
    }
    // 任务队列是否为空
    bool isEmpty()
    {
        lock_guard<mutex> locker(m_mutex);
        bool flag = m_taskQ.empty();
        return flag;
    }
    // 添加任务
    void addTask(int data)
    {
        lock_guard<mutex> locker(m_mutex);
        m_taskQ.push(data);
    }
    // 取出一个任务
    int takeTask()
    {
        lock_guard<mutex> locker(m_mutex);
        if (!m_taskQ.empty())
        {
            return m_taskQ.front();
        }
        return -1;
    }
    // 删除一个任务
    bool popTask()
    {
        lock_guard<mutex> locker(m_mutex);
        if (!m_taskQ.empty())
        {
            m_taskQ.pop();
            return true;
        }
        return false;
    }
private:
    TaskQueue() = default;
    static TaskQueue m_obj;
    queue<int> m_taskQ;
    mutex m_mutex;
};
TaskQueue TaskQueue::m_obj;

int main()
{
    thread t1([]() {
        TaskQueue* taskQ = TaskQueue::getInstance();
        for (int i = 0; i < 100; ++i)
        {
            taskQ->addTask(i + 100);
            cout << "+++push task: " << i + 100 << ", threadID: " 
                << this_thread::get_id() << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    });
    thread t2([]() {
        TaskQueue* taskQ = TaskQueue::getInstance();
        this_thread::sleep_for(chrono::milliseconds(100));
        while (!taskQ->isEmpty())
        {
            int data = taskQ->takeTask();
            cout << "---take task: " << data << ", threadID: " 
                << this_thread::get_id() << endl;
            taskQ->popTask();
            this_thread::sleep_for(chrono::seconds(1));
        }
    });
    t1.join();
    t2.join();
}