#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Chain of Responsibility Pattern:
// Let a request pass along a chain until one handler processes it.

class Request
{
public:
    Request(string event, int dangerLevel)
        : m_event(event), m_dangerLevel(dangerLevel) {}

    string event() const
    {
        return m_event;
    }

    int dangerLevel() const
    {
        return m_dangerLevel;
    }

private:
    string m_event;
    int m_dangerLevel;
};

class Handler
{
public:
    void setNext(shared_ptr<Handler> next)
    {
        m_next = next;
    }

    virtual void handle(const Request& request)
    {
        if (m_next)
        {
            m_next->handle(request);
        }
        else
        {
            cout << "No one can handle: " << request.event() << endl;
        }
    }

    virtual ~Handler() {}

private:
    shared_ptr<Handler> m_next;
};

class Usopp : public Handler
{
public:
    void handle(const Request& request) override
    {
        if (request.dangerLevel() <= 2)
        {
            cout << "Usopp handles [" << request.event() << "] with tricks." << endl;
            return;
        }
        Handler::handle(request);
    }
};

class Sanji : public Handler
{
public:
    void handle(const Request& request) override
    {
        if (request.dangerLevel() <= 5)
        {
            cout << "Sanji handles [" << request.event() << "] with Diable Jambe." << endl;
            return;
        }
        Handler::handle(request);
    }
};

class Luffy : public Handler
{
public:
    void handle(const Request& request) override
    {
        if (request.dangerLevel() <= 10)
        {
            cout << "Luffy handles [" << request.event() << "] with Gear Fifth." << endl;
            return;
        }
        Handler::handle(request);
    }
};

int main()
{
    shared_ptr<Handler> usopp(new Usopp);
    shared_ptr<Handler> sanji(new Sanji);
    shared_ptr<Handler> luffy(new Luffy);

    usopp->setNext(sanji);
    sanji->setNext(luffy);

    usopp->handle(Request("small pirates blocking the road", 1));
    usopp->handle(Request("CP agent attack", 5));
    usopp->handle(Request("Yonko level fight", 9));
    usopp->handle(Request("ancient weapon wakes up", 99));

    return 0;
}
