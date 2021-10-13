#include "Creature.h"

Creature::Creature() : Thing() {

}

void Creature::addVulnerability(std::string vulnToAdd) {
    vulnerability.push_back(vulnToAdd);
}