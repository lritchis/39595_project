#include "Room.h"

Room::Room() : name(""), status(""), type("regular"),  desc(""), north("none"),east("none"),south("none"),west("none"){

}

/*Room::Room(std::string _name, std::string _desc) : name(_name), desc(_desc) {

} */ //do we need anything except default constructors?

void Room::setName(std::string nameToSet) {
    name = nameToSet;
}

void Room::setType(std::string typeToSet) {
    type = typeToSet;
}

void Room::setStatus(std::string statusToSet) {
    status = statusToSet;
}

void Room::setDescription(std::string descToSet) {
    desc = descToSet;
}

void Room::setNorth(std::string northRoom) {
    north = northRoom;
}

void Room::setEast(std::string eastRoom) {
    east = eastRoom;
}

void Room::setSouth(std::string southRoom) {
    south = southRoom;
}

void Room::setWest(std::string westRoom) {
    west = westRoom;
}

void Room::addItem(std::string itemToAdd) {
    items.push_back(itemToAdd);
}

void Room::addContainer(std::string containerToAdd) {
    containers.push_back(containerToAdd);
}

void Room::addCreature(std::string creatureToAdd) {
    creatures.push_back(creatureToAdd);
}

void Room::addTrigger(Trigger* triggerToAdd) {
    triggers.push_back(triggerToAdd);
}

std::string Room::getName() {
    return name;
}

std::string Room::getType() {
    return type;
}

std::string Room::getStatus() {
    return status;
}

std::string Room::getDescription() {
    return desc;
}

std::string Room::getNorth() {
    return north;
}

std::string Room::getEast() {
    return east;
}

std::string Room::getSouth() {
    return south;
}

std::string Room::getWest() {
    return west;
}