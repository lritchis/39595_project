#ifndef Creature_H_
#define Creature_H_

#include <vector>
#include <string>
#include "Thing.h"

class Creature : public Thing {
public:
    Creature();
    Creature(Creature& orig);

    virtual void addVulnerability(std::string vulnToAdd);

    virtual std::vector<std::string> getVuln();

protected:
    std::vector<std::string> vulnerability;
};

#endif