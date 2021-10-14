#ifndef Trigger_H_
#define Trigger_H_
#include <iostream>
#include "Condition.h"
#include <string>
#include <vector>

class Trigger {
public:
    Trigger();
    Trigger(const Trigger& orig);

    virtual void setType(std::string typeToSet);
    virtual void setCommand(std::string commandToSet);
    virtual void addCondition(Condition conditionToAdd);
    virtual void addPrint(std::string printToAdd);
    virtual void addAction(std::string actionToAdd);

    virtual std::string getType() const;
    virtual std::string getCommand() const;
    virtual std::vector<Condition> getConditions() const;
    virtual std::vector<std::string> getPrints() const;
    virtual std::vector<std::string> getActions() const;

private:
    std::string type;
    std::string command;
    std::vector<Condition> conditions;
    std::vector<std::string> prints;
    std::vector<std::string> actions;
};

#endif

