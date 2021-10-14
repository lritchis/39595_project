#ifndef Creature_H_
#define Creature_H_

#include <vector>
#include <string>
#include "Thing.h"
#include "Attack.h"

class Creature : public Thing {
public:
    Creature();
    Creature(const Creature& orig);
    virtual ~Creature();

    virtual void addVulnerability(std::string vulnToAdd);
    virtual void setAttack(Attack attackToSet);

    virtual std::vector<std::string> getVuln() const;
    virtual Attack getAttack() const;

protected:
    std::vector<std::string> vulnerability;
    Attack attack;
};

#endif