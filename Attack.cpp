#include "Attack.h"

Attack::Attack() {

}

Attack::Attack(int i) {
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
}

void Attack::addPrint(std::string printToAdd) {
    prints.push_back(printToAdd);
}

void Attack::addAction(std::string actionToAdd) {
    actions.push_back(actionToAdd);
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