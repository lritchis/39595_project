#include "Creature.h"

Creature::Creature() : Thing() {
    std::cout << "Creature constructor of name " << name << std::endl;
}

Creature::Creature(Creature& orig) : Thing(orig) {
    vulnerability = orig.vulnerability;
}

void Creature::addVulnerability(std::string vulnToAdd) {
    std::cout << "Added vulterability of " << vulnToAdd << std::endl;
    vulnerability.push_back(vulnToAdd);
}

std::vector<std::string> Creature::getVuln() {
    return vulnerability;
}