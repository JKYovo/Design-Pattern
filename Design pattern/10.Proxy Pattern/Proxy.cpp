#include <iostream>
#include <string>
using namespace std;

// ����ģʽ��Ϊ���������ṩһ�ִ����Կ��ƶ��������ķ��ʡ�
// ����ģʽ���Ƕ�һ���������������ԭ�������һЩ�����������������ⷿ��ʱ���ͨ���н顣

// ����ͨ����
class Communication
{
public:
    virtual void communicate() = 0; // ͨ��
    virtual ~Communication() {}
};

// ��������
class Speaker : public Communication
{
public:
    void communicate() override
    {
        cout << "��ʼ˵��..." << endl;
        cout << "ͨ��ʱ������һЩ�еı���仯..." << endl;
    }
};

// �绰��
class DenDenMushi : public Communication
{
public:
    DenDenMushi()
    {
        m_isStart = true;
        m_speaker = new Speaker;
    }
    ~DenDenMushi()
    {
        if (m_speaker != nullptr)
        {
            delete m_speaker;
        }
    }
    // �ж��Ƿ��Ѿ���ʼͨ����
    bool isStart()
    {
        return m_isStart;
    }
    void communicate() override
    {
        if (isStart())
        {
            // �õ�ͨ�������Ժͱ�����Ϣ, ������ģ��
            cout << "�绰�濪ʼʵʱģ��ͨ���ߵ����Ժͱ���..." << endl;
            m_speaker->communicate();
       }
    }
private:
    bool m_isStart = false;
    Speaker* m_speaker = nullptr;
};

int main()
{
    // ֱ�ӽ���
    Communication* comm = new Speaker;
    comm->communicate();
    delete comm;
    cout << "===================================" << endl;
    // ʹ�õ绰��
    comm = new DenDenMushi;
    comm->communicate();
    delete comm;

    return 0;
}
//ͨ�����Գ������ǿ��Եõ����½��ۣ����ʹ�ô���ģʽ�����ܸı����������Ľӿڣ�ʹ�ô���ģʽ��Ŀ����Ϊ�˼�ǿ���ơ�