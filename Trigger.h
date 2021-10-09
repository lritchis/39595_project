#ifndef Trigger_H_
#define Trigger_H_
#include <iostream>
#include "Condition.h"

class Trigger {
public:
    Trigger::Trigger();
    Trigger::Trigger(std::string _type, std::string _command, Condition* _condition);

    virtual void setType(std::string typeToSet);
    virtual void setCommand(std::string commandToSet);
    virtual void setCondition(Condition* conditionToSet);

    virtual std::string getType();
    virtual std::string getCommand();
    virtual Condition getCondition();

private:
    std::string type;
    std::string command;
    Condition* condition;
};

#endif

