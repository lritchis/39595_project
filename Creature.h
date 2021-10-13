#ifndef Creature_H_
#define Creature_H_

#include <vector>
#include <string>
#include "Thing.h"

class Creature : public Thing {
public:
    Creature();

    virtual void addVulnerability(std::string vulnToAdd);

protected:
    std::vector<std::string> vulnerability;
};

#endif