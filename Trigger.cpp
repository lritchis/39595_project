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

std::string Trigger::getType() {
    return type;
}

std::string Trigger::getCommand() {
    return command;
}