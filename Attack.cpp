#include "Attack.h"

Attack::Attack() {

}

Attack::Attack(int i) {
    std::cout << "Creating an Attack" << std::endl;
}

Attack::Attack(const Attack& orig) {
    conditions = orig.getConditions();
    prints = orig.getPrints();
    actions = orig.getActions();
}

Attack::~Attack() {
    
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

std::vector<Condition> Attack::getConditions() const {
    return conditions;
}

std::vector<std::string> Attack::getPrints() const {
    return prints;
}

std::vector<std::string> Attack::getActions() const {
    return actions;
}