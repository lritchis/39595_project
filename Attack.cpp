#include "Attack.h"

Attack::Attack() {
    std::cout << "Creating an Attack" << std::endl;
}

Attack::Attack(const Attack& orig) {
    conditions = orig.getConditions();
    prints = orig.getPrints();
    actions = orig.getActions();
}

void Attack::addCondition(Condition conditionToAdd) {
    conditions.push_back(conditionToAdd);
    std::cout << "Adding condition to Attack" << std::endl;
}

void Attack::addPrint(std::string printToAdd) {
    prints.push_back(printToAdd);
    std::cout << "Adding print to Attack: " << printToAdd << std::endl;
}

void Attack::addAction(std::string actionToAdd) {
    actions.push_back(actionToAdd);
    std::cout << "Adding action to Attack: " << actionToAdd << std::endl;
}

const std::vector<Condition> Attack::getConditions() {
    return conditions;
}

const std::vector<std::string> Attack::getPrints() {
    return prints;
}

const std::vector<std::string> Attack::getActions() {
    return actions;
}