#ifndef Creature_H_
#define Creature_H_

#include <vector>
#include "string.h"

class Creature : public Thing {
public:
    Creature();

    void addVulnerability;

protected:
    std::vector<std::string> vulnerability;
};

#endif