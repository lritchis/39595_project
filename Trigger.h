#ifndef Trigger_H_
#define Trigger_H_
#include <iostream>
#include "Condition.h"
#include "string.h"

class Trigger {
public:
    Trigger::Trigger();
    Trigger::Trigger(std::string _type, std::string _command, Condition* _condition);

    virtual void setType(std::string typeToSet);
    virtual void setCommand(std::string commandToSet);
    virtual void setCondition(Condition* conditionToSet);
    virtual void setPrint(std::string printToSet);
    virtual void setAction(std::string actionToSet);

    virtual std::string getType();
    virtual std::string getCommand();
    virtual Condition* getCondition();
    virtual std::string getPrint();
    virtual std::string getAction();

private:
    std::string type;
    std::string command;
    std::vector<Condition*> condition;
    std::string print;
    std::string action;
};

#endif

