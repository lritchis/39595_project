#include "Attack.h"

Attack::Attack() {
    std::cout << "Creating an Attack" << std::endl;
}

Attack::Attack(Attack& orig) {
    conditions = orig.conditions;
    prints = orig.prints;
    actions = orig.actions;
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
