#ifndef Owner_H_
#define Owner_H_

#include "Condition.h"

class Owner : public Condition {
public:
    Owner();
    virtual void setOwner(std::string ownerNameToSet);
    virtual std::string getOwner();
    
protected:
    std::string ownerName;
};

#endif