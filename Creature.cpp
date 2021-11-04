#include "Creature.h"

Creature::Creature() : Thing() {
}

Creature::Creature(const Creature& orig) : Thing(orig) {
    vulnerability = orig.getVuln();
    attack = orig.getAttack();
}

Creature::~Creature() {}

void Creature::addVulnerability(std::string vulnToAdd) {
    vulnerability.push_back(vulnToAdd);
}

void Creature::setAttack(Attack attackToSet) {
    attack = attackToSet;
}

std::vector<std::string> Creature::getVuln() const {
    return vulnerability;
}

Attack Creature::getAttack() const {
    return attack;
}