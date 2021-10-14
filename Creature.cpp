#include "Creature.h"

Creature::Creature() : Thing() {
    std::cout << "Creating a creature" << std::endl;
}

Creature::Creature(const Creature& orig) : Thing(orig) {
    vulnerability = orig.vulnerability;
}

Creature::~Creature() {}

void Creature::addVulnerability(std::string vulnToAdd) {
    std::cout << "Added vulnarability of " << vulnToAdd << "to creature" << std::endl;
    vulnerability.push_back(vulnToAdd);
}

void Creature::setAttack(Attack attackToSet) {
    attack = attackToSet;
    std::cout << "Setting the attack of the creature" << std::endl;
}

std::vector<std::string> Creature::getVuln() const {
    return vulnerability;
}

Attack Creature::getAttack() const {
    return attack;
}