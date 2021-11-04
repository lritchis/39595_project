#include "Thing.h"

Thing::Thing() : name(""), roomNum(-1), status("") {

}

Thing::Thing(const Thing& orig) {
    name = orig.getName();
    roomNum = orig.getRoomNum();
    status = orig.getStatus();
    triggers = orig.getTriggers();
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

std::string Thing::getName() const {
    return name;
}

int Thing::getRoomNum() const {
    return roomNum;
}

std::string Thing::getStatus() const {
    return status;
}

std::vector<Trigger> Thing::getTriggers() const {
    return triggers;
}

void Thing::addTrigger(Trigger triggerToAdd) {
    triggers.push_back(triggerToAdd);
}
