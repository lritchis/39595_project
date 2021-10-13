#include "Condition.h"

Condition::Condition() : has(""), object(""), status(""), owner("") {
    std::cout << "Creating a Condition" << std::endl;
}

void Condition::setHas(std::string hasToSet) {
    has = hasToSet;
    std::cout << "Setting condition 'has' to " << hasToSet << std::endl;
}

void Condition::setObject(std::string objectToSet) {
    object = objectToSet;
    std::cout << "Setting condition object to " << objectToSet << std::endl;
}

void Condition::setStatus(std::string statusToSet) {
    status = statusToSet;
    std::cout << "Setting condition status to " << statusToSet << std::endl;
}

void Condition::setOwner(std::string ownerToSet) {
    owner = ownerToSet;
    std::cout << "Setting condition owner to " << ownerToSet << std::endl;
}

/*
bool Condition::getHas() {
    return has;
}

std::string Condition::getObjName() {
    return objName;
}
*/
