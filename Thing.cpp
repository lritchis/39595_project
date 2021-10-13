#include "Thing.h"

Thing::Thing() : name(""), roomNum(-1), status("") {

}

void Thing::setName(std::string nameToSet) {
    name = nameToSet;
    std::cout << "Setting name to " << nameToSet << std::endl;
}

void Thing::setRoomNum(int roomToSet) {
    roomNum = roomToSet;
}

void Thing::setStatus(std::string statusToSet) {
    status = statusToSet;
    std::cout << "Setting status to " << statusToSet << std::endl;
}

std::string Thing::getName() {
    return name;
}

int Thing::getRoomNum() {
    return roomNum;
}

std::string Thing::getStatus() {
    return status;
}

void Thing::addTrigger(Trigger triggerToAdd) {
    triggers.push_back(triggerToAdd);
    std::cout << "Adding a trigger" << std::endl;
}
