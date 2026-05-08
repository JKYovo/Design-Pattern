#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Mediator Pattern:
// Let objects communicate through a mediator instead of referencing each other directly.

class CrewMember;

class SunnyMediator
{
public:
    void addMember(CrewMember* member)
    {
        m_members.push_back(member);
    }

    void broadcast(const string& from, const string& message);

private:
    vector<CrewMember*> m_members;
};

class CrewMember
{
public:
    CrewMember(string name, SunnyMediator* mediator)
        : m_name(name), m_mediator(mediator)
    {
        m_mediator->addMember(this);
    }

    string name() const
    {
        return m_name;
    }

    void send(const string& message)
    {
        cout << m_name << " sends: " << message << endl;
        m_mediator->broadcast(m_name, message);
    }

    void receive(const string& from, const string& message)
    {
        cout << m_name << " receives from " << from << ": " << message << endl;
    }

private:
    string m_name;
    SunnyMediator* m_mediator = nullptr;
};

void SunnyMediator::broadcast(const string& from, const string& message)
{
    for (const auto& member : m_members)
    {
        if (member->name() != from)
        {
            member->receive(from, message);
        }
    }
}

int main()
{
    SunnyMediator sunny;
    CrewMember nami("Nami", &sunny);
    CrewMember sanji("Sanji", &sunny);
    CrewMember zoro("Zoro", &sunny);

    nami.send("Storm is coming. Adjust the sail!");
    cout << "====================================" << endl;
    sanji.send("Dinner is ready.");

    return 0;
}
