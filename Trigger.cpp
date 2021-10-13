#include "Trigger.h"

Trigger::Trigger() : type("Permanent"), command(""), condition(new Condition) {

}

Trigger::Trigger(std::string _type, std::string _command, Condition* _condition) : type(_type), command(_command), condition(_condition) {

}

void Trigger::setType(std::string typeToSet) {
    type = typeToSet;
}

void Trigger::setCommand(std::string commandToSet) {
    command = commandToSet;
}

void Trigger::setCondition(Condition* conditionToSet) {
    condition = conditionToSet;
}

void Trigger::setPrint(std::string printToSet) {
    print = printToSet;
}

void Trigger::setAction(std::string actionToSet) {
    action = actionToSet;
}

std::string Trigger::getType() {
    return type;
}

std::string Trigger::getCommand() {
    return command;
}

// need to see if using Condition* is the way to do this or if it causes issues
Condition* Trigger::getCondition() {
    return condition;
}

std::string Trigger::getPrint() {
    return print;
}

std::string Trigger::getAction() {
    return action;
}
