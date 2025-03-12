//ԭ��ģʽ�����ܹ��������еĶ��󣬶�������ʹ�������������������ࡣ
//����˵��������ͨ�����ж����¡����һ���µĶ��󣬲��ҿ�¡���������Ҫʹ�ù��캯����
#include <iostream>
using namespace std;

class GermaSoldier
{
public:
    virtual GermaSoldier* clone() = 0;
    virtual string whoAmI() = 0;
    virtual ~GermaSoldier() {}
};

class Soldier66 : public GermaSoldier
{
public:
    GermaSoldier* clone() override
    {
        return new Soldier66(*this);
    }
    string whoAmI() override
    {
        return string("���ǽܶ���66�ĳ���ʿ��!!!");
    }
};

class Soldier67 : public GermaSoldier
{
public:
    GermaSoldier* clone()
    {
        return new Soldier67(*this);
    }
    string whoAmI() override
    {
        return string("���ǽܶ���67�ĳ���ʿ��!!!");
    }
};

int main()
{
    GermaSoldier* obj = new Soldier66;
    GermaSoldier* soldier = obj->clone();
    cout << soldier->whoAmI() << endl;
    delete soldier;
    delete obj;

    obj = new Soldier67;
    soldier = obj->clone();
    cout << soldier->whoAmI() << endl;
    delete soldier;
    delete obj;
}
