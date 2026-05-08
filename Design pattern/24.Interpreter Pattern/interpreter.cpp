#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Interpreter Pattern:
// Define grammar classes and interpret a simple language.
// Grammar in this example:
//   bounty <name>
//   title <name>

class Context
{
public:
    map<string, int> bounty;
    map<string, string> title;
};

class Expression
{
public:
    virtual string interpret(const Context& context) const = 0;
    virtual ~Expression() {}
};

class BountyExpression : public Expression
{
public:
    BountyExpression(string name) : m_name(name) {}

    string interpret(const Context& context) const override
    {
        auto iter = context.bounty.find(m_name);
        if (iter == context.bounty.end())
        {
            return "Unknown bounty for " + m_name;
        }
        return m_name + "'s bounty is " + to_string(iter->second) + " berries";
    }

private:
    string m_name;
};

class TitleExpression : public Expression
{
public:
    TitleExpression(string name) : m_name(name) {}

    string interpret(const Context& context) const override
    {
        auto iter = context.title.find(m_name);
        if (iter == context.title.end())
        {
            return "Unknown title for " + m_name;
        }
        return m_name + "'s title is " + iter->second;
    }

private:
    string m_name;
};

class Parser
{
public:
    unique_ptr<Expression> parse(const string& command) const
    {
        string type;
        string name;
        stringstream ss(command);
        ss >> type >> name;

        if (type == "bounty")
        {
            return unique_ptr<Expression>(new BountyExpression(name));
        }
        if (type == "title")
        {
            return unique_ptr<Expression>(new TitleExpression(name));
        }
        return unique_ptr<Expression>();
    }
};

int main()
{
    Context context;
    context.bounty["Luffy"] = 3000000000;
    context.bounty["Zoro"] = 1111000000;
    context.title["Luffy"] = "Emperor of the Sea";
    context.title["Zoro"] = "Pirate Hunter";

    Parser parser;
    vector<string> commands;
    commands.push_back("bounty Luffy");
    commands.push_back("title Zoro");
    commands.push_back("bounty Nami");

    for (const auto& command : commands)
    {
        unique_ptr<Expression> expression = parser.parse(command);
        if (expression)
        {
            cout << expression->interpret(context) << endl;
        }
    }

    return 0;
}
