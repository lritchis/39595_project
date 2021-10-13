#include "Condition.h"

Condition::Condition() : has(""), object(""), status(""), owner("") {
    std::cout << "Creating a Condition" << std::endl;
}

Condition::Condition(Condition& orig) {
    has = orig.getHas();
    object = orig.getObject();
    status = orig.getStatus();
    owner = orig.getOwner();
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


std::string Condition::getHas() {
    return has;
}

std::string Condition::getObject() {
    return object;
}

std::string Condition::getStatus() {
    return status;
}

std::string Condition::getOwner() {
    return owner;
}

