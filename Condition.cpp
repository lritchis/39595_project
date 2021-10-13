#include "Condition.h"

Condition::Condition() : has(false), objName("") {

}

Condition::Condition(bool _has, std::string _objName) : has(_has), objName(_objName) {

}

void Condition::setHas(bool hasToSet) {
    has = hasToSet;
}

void Condition::setObjName(std::string nameToSet) {
    objName = nameToSet;
}

bool Condition::getHas() {
    return has;
}

std::string Condition::getObjName() {
    return objName;
}

