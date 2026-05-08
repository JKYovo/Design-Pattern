#include <iostream>
#include <memory>
#include <string>
#include <utility>
using namespace std;

// State Pattern:
// Let an object change its behavior when its internal state changes.

class Luffy;

class LuffyState
{
public:
    virtual void fight(Luffy& luffy) = 0;
    virtual string name() const = 0;
    virtual ~LuffyState() {}
};

class Luffy
{
public:
    void setState(unique_ptr<LuffyState> state)
    {
        m_state = move(state);
        cout << "Luffy changes state to: " << m_state->name() << endl;
    }

    void fight()
    {
        if (m_state)
        {
            m_state->fight(*this);
        }
    }

private:
    unique_ptr<LuffyState> m_state;
};

class NormalState : public LuffyState
{
public:
    void fight(Luffy& luffy) override;

    string name() const override
    {
        return "Normal";
    }
};

class GearSecondState : public LuffyState
{
public:
    void fight(Luffy& luffy) override;

    string name() const override
    {
        return "Gear Second";
    }
};

class GearFifthState : public LuffyState
{
public:
    void fight(Luffy&) override
    {
        cout << "Luffy uses Gear Fifth and turns imagination into power." << endl;
    }

    string name() const override
    {
        return "Gear Fifth";
    }
};

void NormalState::fight(Luffy& luffy)
{
    cout << "Luffy uses Gum-Gum Pistol." << endl;
    luffy.setState(unique_ptr<LuffyState>(new GearSecondState));
}

void GearSecondState::fight(Luffy& luffy)
{
    cout << "Luffy accelerates with Gear Second." << endl;
    luffy.setState(unique_ptr<LuffyState>(new GearFifthState));
}

int main()
{
    Luffy luffy;
    luffy.setState(unique_ptr<LuffyState>(new NormalState));

    luffy.fight();
    luffy.fight();
    luffy.fight();

    return 0;
}
