#include "Room.h"

Room::Room() : name(""), status(""), type("regular"),  desc(""), north("none"), east("none"), south("none"), west("none"){
}

Room::Room(const Room& orig) {
    name = orig.getName();
    type = orig.getType();
    status = orig.getStatus();
    desc = orig.getDescription();
    north = orig.getNorth();
    east = orig.getEast();
    south = orig.getSouth();
    west = orig.getWest();
    items = orig.getItems();
    containers = orig.getContainers();
    creatures = orig.getCreatures();
    triggers = orig.getTriggers(0);
}

Room::~Room() {}

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

void Room::addTrigger(Trigger triggerToAdd) {
    triggers.push_back(triggerToAdd);
}

std::string Room::getName() const {
    return name;
}

std::string Room::getType() const {
    return type;
}

std::string Room::getStatus() const {
    return status;
}

std::string Room::getDescription() const {
    return desc;
}

std::string Room::getNorth() const {
    return north;
}

std::string Room::getEast() const {
    return east;
}

std::string Room::getSouth() const {
    return south;
}

std::string Room::getWest() const {
    return west;
}

std::vector<std::string> Room::getItems() const {
    return items;
}

std::vector<std::string> Room::getContainers() const {
    return containers;
}

std::vector<std::string> Room::getCreatures() const {
    return creatures;
}

std::vector<Trigger> Room::getTriggers(int i) const {
   return triggers;
}

std::vector<Trigger>* Room::getTriggers() {
    return &triggers;
}

bool Room::removeItem(std::string itemToRemove) {
    // Find the index of the item we're removing
    int itemIndex;
    std::vector<std::string>::iterator it;
    it = std::find_if(items.begin(), items.end(), [itemToRemove](const std::string& i){ return i == itemToRemove; });
    if (it != items.end()) {
        itemIndex = it - items.begin();
        items.erase(items.begin() + itemIndex);
        return true;
    }
    else {
        return false; // item not in list
    }
}

bool Room::removeCreature(std::string creatureToRemove) {
    // Find the index of the creature we're removing
    int creatureIndex;
    std::vector<std::string>::iterator it;
    it = std::find_if(creatures.begin(), creatures.end(), [creatureToRemove](const std::string& c){ return c == creatureToRemove; });
    if (it != creatures.end()) {
        creatureIndex = it - creatures.begin();
        creatures.erase(creatures.begin() + creatureIndex);
        return true;
    }
    else {
        return false; // creature not in list
    }
}

bool Room::removeContainer(std::string containerToRemove) {
    // Find the index of the container we're removing
    int containerIndex;
    std::vector<std::string>::iterator it;
    it = std::find_if(containers.begin(), containers.end(), [containerToRemove](const std::string& c){ return c == containerToRemove; });
    if (it != containers.end()) {
        containerIndex = it - containers.begin();
        containers.erase(containers.begin() + containerIndex);
        return true;
    }
    else {
        return false; // container not in list
    }
}
