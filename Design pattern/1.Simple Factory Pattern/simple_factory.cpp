#include <iostream>
using namespace std;

// ���ࣺ�����ħ��ʵ
class AbstractSmile {
public:
    virtual void transform() = 0; // ���麯��������
    virtual void ability() = 0;   // ���麯��������
    virtual ~AbstractSmile() {}   // ������������ȷ����ȷ�ͷ����������
};

// ������̬��ħ��ʵ
class SheepSmile : public AbstractSmile {
public:
    void transform() override {
        cout << "������� -- ɽ������̬..." << endl;
    }
    void ability() override {
        cout << "���ֱ۱������ǵ���ʽ -- �����" << endl;
    }
};

// ʨ����̬��ħ��ʵ
class LionSmile : public AbstractSmile {
public:
    void transform() override {
        cout << "������� -- ʨ������̬..." << endl;
    }
    void ability() override {
        cout << "��ݡ� ������֮��..." << endl;
    }
};

// ������̬��ħ��ʵ
class BatSmile : public AbstractSmile {
public:
    void transform() override {
        cout << "������� -- ��������̬..." << endl;
    }
    void ability() override {
        cout << "��������֮�򽣹���..." << endl;
    }
};

// ��ħ��ʵ����ö��
enum class Type : char {
    SHEEP, // ������̬
    LION,  // ʨ����̬
    BAT    // ������̬
};

// ��ħ��ʵ������
//  1.ǿ����ö�ٵ�ö��ֵ������ʽת��Ϊ������������˴�ͳö���п��ܳ��ֵ����Ͱ�ȫ���⡣
//  2.ǿ����ö�ٵ�ö��ֵ��������������ö�����ڲ��������˴�ͳö���п��ܳ��ֵ�������ͻ��
class SmileFactory {
public:
    // ������ħ��ʵ����
    AbstractSmile* createSmile(Type type) {
        switch (type) {
            case Type::SHEEP: return new SheepSmile; // ����������̬
            case Type::LION:  return new LionSmile;  // ����ʨ����̬
            case Type::BAT:   return new BatSmile;  // ����������̬
            default: return nullptr;               // δ֪���ͷ��ؿ�ָ��
        }
    }
};

int main() {
    SmileFactory factory; // ������������
    AbstractSmile* obj = factory.createSmile(Type::BAT); // ����������̬��ħ��ʵ
    if (obj) {
        obj->transform(); // ����
        obj->ability();   // ʹ������
        delete obj;       // �ͷŶ���
    }
    return 0;
}

//������Ĺ�����������Ҫ�������������ħ��ʵ�����������Ҫ���ɸ��࣬��ô����Ҫ�ڹ���������switch�������Ӹ����case����������Υ���˷��ԭ��Ҳ����ζ����Ҫ���ڿ���ԭ�������������⡣

