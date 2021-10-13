#include "Thing.h"

Thing::Thing() : name(""), roomNum(-1), status("") {

}

Thing::Thing(std::string _name, int _roomNum, std::string _status) : name(_name), roomNum(_roomNum), status(_status) {

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

std::string Thing::getName() {
    return name;
}

int Thing::getRoomNum() {
    return roomNum;
}

std::string Thing::getStatus() {
    return status;
}

void Thing::addTrigger(Trigger* triggerToAdd) {
    triggers.push_back(triggerToAdd);
}
