#include "Trigger.h"

Trigger::Trigger() : type("single"), command("") {
    std::cout << "Creating a Trigger" << std::endl;
}

void Trigger::setType(std::string typeToSet) {
    type = typeToSet;
    std::cout << "Setting trigger type to " << typeToSet << std::endl;
}

void Trigger::setCommand(std::string commandToSet) {
    command = commandToSet;
    std::cout << "Setting trigger command to " << commandToSet << std::endl;
}

void Trigger::addCondition(Condition conditionToAdd) {
    conditions.push_back(conditionToAdd);
    std::cout << "Adding condition to Trigger" << std::endl;
}

void Trigger::addPrint(std::string printToAdd) {
    prints.push_back(printToAdd);
    std::cout << "Adding print to Trigger: " << printToAdd << std::endl;
}

void Trigger::addAction(std::string actionToAdd) {
    actions.push_back(actionToAdd);
    std::cout << "Adding action to Trigger: " << actionToAdd << std::endl;
}

std::string Trigger::getType() {
    return type;
}

std::string Trigger::getCommand() {
    return command;
}

std::vector<Condition> Trigger::getConditions() {
    return conditions;
}

std::vector<std::string> Trigger::getPrints() {
    return prints;
}

std::vector<std::string> Trigger::getActions() {
    return actions;
}
