#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// Visitor Pattern:
// Put operations into visitor objects, so element classes can stay stable.

class StrawHatVisitor;

class CrewRole
{
public:
    virtual void accept(StrawHatVisitor& visitor) = 0;
    virtual ~CrewRole() {}
};

class Swordsman;
class Navigator;
class Doctor;

class StrawHatVisitor
{
public:
    virtual void visit(Swordsman& swordsman) = 0;
    virtual void visit(Navigator& navigator) = 0;
    virtual void visit(Doctor& doctor) = 0;
    virtual ~StrawHatVisitor() {}
};

class Swordsman : public CrewRole
{
public:
    string skill() const
    {
        return "Three Sword Style";
    }

    void accept(StrawHatVisitor& visitor) override
    {
        visitor.visit(*this);
    }
};

class Navigator : public CrewRole
{
public:
    string skill() const
    {
        return "Weather Art";
    }

    void accept(StrawHatVisitor& visitor) override
    {
        visitor.visit(*this);
    }
};

class Doctor : public CrewRole
{
public:
    string skill() const
    {
        return "Rumble Ball";
    }

    void accept(StrawHatVisitor& visitor) override
    {
        visitor.visit(*this);
    }
};

class BattleReportVisitor : public StrawHatVisitor
{
public:
    void visit(Swordsman& swordsman) override
    {
        cout << "Battle report: Zoro uses " << swordsman.skill() << "." << endl;
    }

    void visit(Navigator& navigator) override
    {
        cout << "Battle report: Nami controls weather with " << navigator.skill() << "." << endl;
    }

    void visit(Doctor& doctor) override
    {
        cout << "Battle report: Chopper supports with " << doctor.skill() << "." << endl;
    }
};

class RewardReportVisitor : public StrawHatVisitor
{
public:
    void visit(Swordsman&) override
    {
        cout << "Reward report: increase Zoro's bounty." << endl;
    }

    void visit(Navigator&) override
    {
        cout << "Reward report: update Nami's intelligence value." << endl;
    }

    void visit(Doctor&) override
    {
        cout << "Reward report: please stop marking Chopper as a pet." << endl;
    }
};

int main()
{
    vector<unique_ptr<CrewRole>> crew;
    crew.push_back(unique_ptr<CrewRole>(new Swordsman));
    crew.push_back(unique_ptr<CrewRole>(new Navigator));
    crew.push_back(unique_ptr<CrewRole>(new Doctor));

    BattleReportVisitor battleReport;
    RewardReportVisitor rewardReport;

    for (const auto& role : crew)
    {
        role->accept(battleReport);
    }

    cout << "====================================" << endl;

    for (const auto& role : crew)
    {
        role->accept(rewardReport);
    }

    return 0;
}
