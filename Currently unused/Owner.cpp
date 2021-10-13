#include "Owner.h"

Owner::Owner() : ownerName(""), Condition() {

}

void Owner::setOwner(std::string ownerNameToSet) {
    ownerName = ownerNameToSet;
}

std::string Owner::getOwner() {
    return ownerName;
}

