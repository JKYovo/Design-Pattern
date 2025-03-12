// ʹ�ù���ģʽ���Ժ������Ľ�����������⣬�򵥹���ģʽ��ֻ��һ�������࣬������ģʽ���кܶ�Ĺ����ࣺ

// һ�����࣬����һ���鹤������������ʵ�ֶ�̬��
// ������࣬��д����Ĺ���������ÿ���ӹ����ฺ������һ�ֶ�ħ��ʵ�����൱���ٴν�����������ְ���ٴβ�֡�ϸ�������Ҫ������Ʒ�ֵĶ�ħ��ʵ����ôֻ��Ҫ��Ӷ�Ӧ�Ĺ����࣬�����޸�ԭ�еĴ��롣
// ��ħ��ʵ������

#include <iostream>
using namespace std;

// ���ࣺ�����ħ��ʵ
class AbstractSmile
{
public:
    virtual void transform() = 0; // ���麯��������
    virtual void ability() = 0;   // ���麯��������
    virtual ~AbstractSmile() { cout<<"�ͷ� AbstractSmile ����ص��ڴ���Դ"<<endl;}  // ������������ȷ����ȷ�ͷ����������
};

// ������̬��ħ��ʵ
class SheepSmile : public AbstractSmile
{
public:
    void transform() override
    {
        cout << "������� -- ɽ������̬..." << endl;
    }
    void ability() override
    {
        cout << "���ֱ۱������ǵ���ʽ -- �����" << endl;
    }
};

// ʨ����̬��ħ��ʵ
class LionSmile : public AbstractSmile
{
public:
    void transform() override
    {
        cout << "������� -- ʨ������̬..." << endl;
    }
    void ability() override
    {
        cout << "��ݡ� ������֮��..." << endl;
    }
};

// ������̬��ħ��ʵ
class BatSmile : public AbstractSmile
{
public:
    void transform() override
    {
        cout << "������� -- ��������̬..." << endl;
    }
    void ability() override
    {
        cout << "��������֮�򽣹���..." << endl;
    }
};

class AbstractFactory
{
public:
    virtual AbstractSmile *createSmile() = 0;// ���麯����һ��������麯�������ڻ�����û�ж��壬Ҫ����������붨�塣
    virtual ~AbstractFactory() {cout << "�ͷ� AbstractFactory ����ص��ڴ���Դ" << endl;}
};

class SheepFactory : public AbstractFactory
{
public:
    AbstractSmile *createSmile() override //override�ؼ��֣�������ʽ��ָʾһ�������Ǹ��ǻ����е��麯��,�� C++11 ֮ǰ����������д�����麯��ʱ���������ǩ����ƥ�䣨����������ͻ��������󣩣����������ᱨ�����ǽ�����Ϊһ���µĺ���������ܵ����������Ϊ��
    {
        return new SheepSmile;
    }
    ~SheepFactory()
    {
        cout << "�ͷ� SheepFactory ����ص��ڴ���Դ" << endl;
    }
};

class LionFactory : public AbstractFactory
{
public:
    AbstractSmile *createSmile() override
    {
        return new LionSmile;
    }
    ~LionFactory()
    {
        cout << "�ͷ� LionFactory ����ص��ڴ���Դ" << endl;
    }
};

class BatFactory : public AbstractFactory
{
public:
    AbstractSmile *createSmile() override
    {
        return new BatSmile;
    }
    ~BatFactory()
    {
        cout << "�ͷ� BatFactory ����ص��ڴ���Դ" << endl;
    }
};

int main(){
    AbstractFactory *factory = new SheepFactory;
    AbstractSmile *obj = factory->createSmile();
    if (obj)
    {
        obj->transform();
        obj->ability();
        delete obj;
    }
    delete factory;
}