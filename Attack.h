#ifndef Attack_H_
#define Attack_H_
#include <iostream>
#include "Condition.h"
#include <string>
#include <vector>

class Attack {
public:
    Attack();
    Attack(const Attack& orig);
    virtual ~Attack();

    virtual void addCondition(Condition conditionToAdd);
    virtual void addPrint(std::string printToAdd);
    virtual void addAction(std::string actionToAdd);

    virtual std::vector<Condition> getConditions() const;
    virtual std::vector<std::string> getPrints() const;
    virtual std::vector<std::string> getActions() const;

private:
    std::vector<Condition> conditions;
    std::vector<std::string> prints;
    std::vector<std::string> actions;
};

#endif
