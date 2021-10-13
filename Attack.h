#ifndef Attack_H_
#define Attack_H_
#include <iostream>
#include "Condition.h"
#include <string>
#include <vector>

class Attack {
public:
    Attack();

    virtual void addCondition(Condition conditionToAdd);
    virtual void addPrint(std::string printToAdd);
    virtual void addAction(std::string actionToAdd);

private:
    std::vector<Condition> conditions;
    std::vector<std::string> prints;
    std::vector<std::string> actions;
};

#endif
