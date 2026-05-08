#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// Iterator Pattern:
// Access elements one by one without exposing the collection's inner structure.

class CrewIterator
{
public:
    CrewIterator(const vector<string>& crew)
        : m_crew(crew) {}

    bool hasNext() const
    {
        return m_index < m_crew.size();
    }

    string next()
    {
        return m_crew[m_index++];
    }

private:
    const vector<string>& m_crew;
    size_t m_index = 0;
};

class StrawHatCrew
{
public:
    void addMember(const string& name)
    {
        m_members.push_back(name);
    }

    unique_ptr<CrewIterator> createIterator() const
    {
        return unique_ptr<CrewIterator>(new CrewIterator(m_members));
    }

private:
    vector<string> m_members;
};

int main()
{
    StrawHatCrew crew;
    crew.addMember("Luffy");
    crew.addMember("Zoro");
    crew.addMember("Nami");
    crew.addMember("Sanji");
    crew.addMember("Chopper");

    unique_ptr<CrewIterator> it = crew.createIterator();
    while (it->hasNext())
    {
        cout << "Crew member: " << it->next() << endl;
    }

    return 0;
}
