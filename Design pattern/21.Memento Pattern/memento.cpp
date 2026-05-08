#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>
using namespace std;

// Memento Pattern:
// Save and restore an object's state without exposing its inner details.

class MapMemento
{
public:
    MapMemento(string island, int logPoseProgress)
        : m_island(island), m_logPoseProgress(logPoseProgress) {}

private:
    friend class NamiMap;
    string m_island;
    int m_logPoseProgress = 0;
};

class NamiMap
{
public:
    void setState(const string& island, int logPoseProgress)
    {
        m_island = island;
        m_logPoseProgress = logPoseProgress;
    }

    unique_ptr<MapMemento> save() const
    {
        cout << "Save map state: " << m_island << ", progress " << m_logPoseProgress << "%" << endl;
        return unique_ptr<MapMemento>(new MapMemento(m_island, m_logPoseProgress));
    }

    void restore(const MapMemento& memento)
    {
        m_island = memento.m_island;
        m_logPoseProgress = memento.m_logPoseProgress;
        cout << "Restore map state: " << m_island << ", progress " << m_logPoseProgress << "%" << endl;
    }

    void show() const
    {
        cout << "Current map: " << m_island << ", Log Pose progress " << m_logPoseProgress << "%" << endl;
    }

private:
    string m_island = "unknown";
    int m_logPoseProgress = 0;
};

class MapHistory
{
public:
    void push(unique_ptr<MapMemento> memento)
    {
        m_history.push_back(move(memento));
    }

    unique_ptr<MapMemento> pop()
    {
        unique_ptr<MapMemento> last = move(m_history.back());
        m_history.pop_back();
        return last;
    }

private:
    vector<unique_ptr<MapMemento>> m_history;
};

int main()
{
    NamiMap map;
    MapHistory history;

    map.setState("Punk Hazard", 30);
    history.push(map.save());

    map.setState("Dressrosa", 80);
    map.show();

    unique_ptr<MapMemento> last = history.pop();
    map.restore(*last);

    return 0;
}
