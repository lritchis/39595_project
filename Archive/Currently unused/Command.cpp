#include "Command.h"

Command::Command() : type("single"), Condition() {

}

void Command::setType(std::string typeToSet) {
    type = typeToSet;
}

void Command::addPrint(std::string printToAdd) {
    print.push_back(printToAdd);
}

void Command::addAction(std::string actionToAdd) {
    action.push_back(actionToAdd);
}

std::string Command::getType() {
    return type;
}