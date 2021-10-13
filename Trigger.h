#ifndef Trigger_H_
#define Trigger_H_
#include <iostream>
#include "Condition.h"
#include <string>
#include <vector>

class Trigger {
public:
    Trigger();

    virtual void setType(std::string typeToSet);
    virtual void setCommand(std::string commandToSet);
    virtual void addCondition(Condition conditionToAdd);
    virtual void addPrint(std::string printToAdd);
    virtual void addAction(std::string actionToAdd);

/*
    virtual std::string getType();
    virtual std::string getCommand();
    virtual Condition getCondition();
    virtual std::string getPrint();
    virtual std::string getAction();
*/

private:
    std::string type;
    std::string command;
    std::vector<Condition> conditions;
    std::vector<std::string> prints;
    std::vector<std::string> actions;
};

#endif

