#include "Condition.h"

Condition::Condition() : has(false), objName(""), owner("") {

}

Condition::Condition(bool _has, std::string _objName, std::string _owner) : has(_has), objName(_objName), owner(_owner) {

}

void Condition::setHas(bool hasToSet) {
    has = hasToSet;
}

void Condition::setObjName(std::string nameToSet) {
    objName = nameToSet;
}

void Condition::setOwner(std::string ownerName) {
    owner = ownerName;
}

bool Condition::getHas() {
    return has;
}

std::string Condition::getObjName() {
    return objName;
}

std::string Condition::getOwner() {
    return owner;
}