#include "Creature.h"

Creature::Creature() : Thing() {

}

void Creature::addVulnerability(std::string vulnToAdd) {
    std::cout << "Added vulterability of " << vulnToAdd << std::endl;
    vulnerability.push_back(vulnToAdd);
}