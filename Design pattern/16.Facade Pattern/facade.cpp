#include <iostream>
#include <string>
using namespace std;

// Facade Pattern:
// Provide one simple entrance for a group of complex subsystem operations.

class Navigator
{
public:
    void readLogPose()
    {
        cout << "Nami reads the Log Pose and confirms the next island." << endl;
    }
};

class Shipwright
{
public:
    void checkShip()
    {
        cout << "Franky checks the hull, cola tank and cannon." << endl;
    }
};

class Cook
{
public:
    void prepareFood()
    {
        cout << "Sanji prepares food for the voyage." << endl;
    }
};

class Doctor
{
public:
    void prepareMedicine()
    {
        cout << "Chopper prepares medicine and emergency tools." << endl;
    }
};

class GoingToSeaFacade
{
public:
    void ready()
    {
        cout << "===== Straw Hat crew prepares to leave port =====" << endl;
        m_navigator.readLogPose();
        m_shipwright.checkShip();
        m_cook.prepareFood();
        m_doctor.prepareMedicine();
        cout << "Everything is ready. Set sail!" << endl;
    }

private:
    Navigator m_navigator;
    Shipwright m_shipwright;
    Cook m_cook;
    Doctor m_doctor;
};

int main()
{
    GoingToSeaFacade facade;
    facade.ready();

    return 0;
}
