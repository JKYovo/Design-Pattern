#include <iostream>
#include <map>
#include <memory>
#include <string>
using namespace std;

// Flyweight Pattern:
// Share intrinsic state. Pass extrinsic state from the outside when using it.

class WantedPoster
{
public:
    WantedPoster(string name, string title)
        : m_name(name), m_title(title)
    {
        cout << "Create poster template for " << m_name << endl;
    }

    void show(const string& island, int bounty) const
    {
        cout << "Poster on " << island << ": " << m_name
             << " - " << m_title << ", bounty " << bounty << " berries" << endl;
    }

private:
    string m_name;
    string m_title;
};

class PosterFactory
{
public:
    shared_ptr<WantedPoster> getPoster(const string& name, const string& title)
    {
        string key = name + "#" + title;
        if (m_pool.find(key) == m_pool.end())
        {
            m_pool[key] = shared_ptr<WantedPoster>(new WantedPoster(name, title));
        }
        return m_pool[key];
    }

    void showCount() const
    {
        cout << "Poster templates in memory: " << m_pool.size() << endl;
    }

private:
    map<string, shared_ptr<WantedPoster>> m_pool;
};

int main()
{
    PosterFactory factory;

    shared_ptr<WantedPoster> luffy = factory.getPoster("Monkey D. Luffy", "Emperor of the Sea");
    luffy->show("Water 7", 3000000000);
    luffy->show("Dressrosa", 3000000000);

    shared_ptr<WantedPoster> zoro = factory.getPoster("Roronoa Zoro", "Pirate Hunter");
    zoro->show("Sabaody", 1111000000);

    shared_ptr<WantedPoster> luffyAgain = factory.getPoster("Monkey D. Luffy", "Emperor of the Sea");
    luffyAgain->show("Wano", 3000000000);

    factory.showCount();

    return 0;
}
