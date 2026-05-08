#include <iostream>
#include <memory>
#include <string>
#include <utility>
using namespace std;

// Bridge Pattern:
// Separate the "ship type" abstraction from the "power system" implementation.
// Then both sides can change independently.

class PowerSystem
{
public:
    virtual string name() const = 0;
    virtual void start() const = 0;
    virtual ~PowerSystem() {}
};

class ColaEngine : public PowerSystem
{
public:
    string name() const override
    {
        return "Cola Engine";
    }

    void start() const override
    {
        cout << "Franky starts the cola engine. Coup de Burst is ready!" << endl;
    }
};

class WindDial : public PowerSystem
{
public:
    string name() const override
    {
        return "Wind Dial";
    }

    void start() const override
    {
        cout << "Nami releases stored wind from the dial." << endl;
    }
};

class PirateShip
{
public:
    PirateShip(string name, unique_ptr<PowerSystem> power)
        : m_name(name), m_power(move(power)) {}

    virtual void sail() const = 0;
    virtual ~PirateShip() {}

protected:
    string m_name;
    unique_ptr<PowerSystem> m_power;
};

class BattleShip : public PirateShip
{
public:
    using PirateShip::PirateShip;

    void sail() const override
    {
        cout << "[" << m_name << "] uses " << m_power->name() << " for battle sailing." << endl;
        m_power->start();
    }
};

class ScoutShip : public PirateShip
{
public:
    using PirateShip::PirateShip;

    void sail() const override
    {
        cout << "[" << m_name << "] uses " << m_power->name() << " for quick scouting." << endl;
        m_power->start();
    }
};

int main()
{
    unique_ptr<PirateShip> sunny(new BattleShip("Thousand Sunny", unique_ptr<PowerSystem>(new ColaEngine)));
    unique_ptr<PirateShip> waver(new ScoutShip("Sky Waver", unique_ptr<PowerSystem>(new WindDial)));

    sunny->sail();
    cout << "====================================" << endl;
    waver->sail();

    return 0;
}
