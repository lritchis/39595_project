#include "Condition.h"

Condition::Condition() : has(""), object(""), status(""), owner("") {
}

Condition::Condition(const Condition& orig) {
    has = orig.getHas();
    object = orig.getObject();
    status = orig.getStatus();
    owner = orig.getOwner();
}

Condition::~Condition() {
    
}

void Condition::setHas(std::string hasToSet) {
    has = hasToSet;
}

void Condition::setObject(std::string objectToSet) {
    object = objectToSet;
}

void Condition::setStatus(std::string statusToSet) {
    status = statusToSet;
}

void Condition::setOwner(std::string ownerToSet) {
    owner = ownerToSet;
}


std::string Condition::getHas() const {
    return has;
}

std::string Condition::getObject() const {
    return object;
}

std::string Condition::getStatus() const {
    return status;
}

std::string Condition::getOwner() const {
    return owner;
}

