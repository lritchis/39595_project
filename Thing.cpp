#include "Thing.h"

Thing::Thing() : name(""), roomNum(-1), status(""), owner("") {
    
}

Thing::Thing(const Thing& orig) {
    name = orig.getName();
    roomNum = orig.getRoomNum();
    status = orig.getStatus();
    triggers = orig.getTriggers(0);
    owner = orig.getOwner();
}

void Thing::setName(std::string nameToSet) {
    name = nameToSet;
}

void Thing::setRoomNum(int roomToSet) {
    roomNum = roomToSet;
}

void Thing::setStatus(std::string statusToSet) {
    status = statusToSet;
}

void Thing::setOwner(std::string ownerToSet) {
    owner = ownerToSet;
}

std::string Thing::getName() const {
    return name;
}

int Thing::getRoomNum() const {
    return roomNum;
}

std::string Thing::getStatus() const {
    return status;
}

std::vector <Trigger> Thing::getTriggers(int i) const {
   return triggers;
}

std::vector<Trigger>* Thing::getTriggers() {
    return &triggers;
}

std::string Thing::getOwner() const {
    return owner;
}

void Thing::addTrigger(Trigger triggerToAdd) {
    triggers.push_back(triggerToAdd);
}
