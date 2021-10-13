#ifndef Trigger_H_
#define Trigger_H_
#include <iostream>
#include "Condition.h"
#include <string>

class Trigger {
public:
    Trigger::Trigger();
    Trigger::Trigger(std::string _type, std::string _command, Condition _condition);

    virtual void setType(std::string typeToSet);
    virtual void setCommand(std::string commandToSet);
    virtual void addCondition(Condition conditionToSet);
    virtual void addPrint(std::string printToSet);
    virtual void addAction(std::string actionToSet);

    virtual std::string getType();
    virtual std::string getCommand();
    virtual Condition getCondition();
    virtual std::string getPrint();
    virtual std::string getAction();

private:
    std::string type;
    std::string command;
    std::vector<Condition> conditions;
    std::vector<std::string> prints;
    std::vector<std::string> actions;
};

#endif

