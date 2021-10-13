#ifndef Creature_H_
#define Creature_H_

#include <vector>
#include <string>
#include "Thing.h"
#include "Attack.h"

class Creature : public Thing {
public:
    Creature();
    Creature(Creature& orig);

    virtual void addVulnerability(std::string vulnToAdd);
    virtual void setAttack(Attack attackToSet);

    virtual std::vector<std::string> getVuln();
    virtual Attack getAttack();

protected:
    std::vector<std::string> vulnerability;
    Attack attack;
};

#endif