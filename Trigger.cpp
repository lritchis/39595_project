#include "Trigger.h"

Trigger::Trigger() : type("single"), command("") {
}

Trigger::Trigger(const Trigger& orig) {
    type = orig.type;
    command = orig.command;
    conditions = orig.conditions;
    prints = orig.prints;
    actions = orig.actions;
}

Trigger::~Trigger() {}

void Trigger::setType(std::string typeToSet) {
    type = typeToSet;
}

void Trigger::setCommand(std::string commandToSet) {
    command = commandToSet;
}

void Trigger::addCondition(Condition conditionToAdd) {
    conditions.push_back(conditionToAdd);
}

void Trigger::addPrint(std::string printToAdd) {
    prints.push_back(printToAdd);
}

void Trigger::addAction(std::string actionToAdd) {
    actions.push_back(actionToAdd);
}

std::string Trigger::getType() const {
    return type;
}

std::string Trigger::getCommand() const {
    return command;
}

std::vector<Condition> Trigger::getConditions() const {
    return conditions;
}

std::vector<std::string> Trigger::getPrints() const {
    return prints;
}

std::vector<std::string> Trigger::getActions() const {
    return actions;
}
