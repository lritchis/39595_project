#include "Room.h"

Room::Room() : name(""), status(""), type("regular"),  desc(""), north("none"), east("none"), south("none"), west("none"){
    std::cout << "Creating a Room" << std::endl;
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
    triggers = orig.getTriggers();
}

Room::~Room() {
    
}

void Room::setName(std::string nameToSet) {
    name = nameToSet;
    std::cout << "Setting room name to " << nameToSet << std::endl;
}

void Room::setType(std::string typeToSet) {
    type = typeToSet;
    std::cout << "Setting room type to " << typeToSet << std::endl;
}

void Room::setStatus(std::string statusToSet) {
    status = statusToSet;
    std::cout << "Setting room status to " << statusToSet << std::endl;
}

void Room::setDescription(std::string descToSet) {
    desc = descToSet;
    std::cout << "Setting room description to " << descToSet << std::endl;
}

void Room::setNorth(std::string northRoom) {
    north = northRoom;
    std::cout << "Setting north border to " << northRoom << std::endl;
}

void Room::setEast(std::string eastRoom) {
    east = eastRoom;
    std::cout << "Setting east border to " << eastRoom << std::endl;
}

void Room::setSouth(std::string southRoom) {
    south = southRoom;
    std::cout << "Setting south border to " << southRoom << std::endl;
}

void Room::setWest(std::string westRoom) {
    west = westRoom;
    std::cout << "Setting west border to " << westRoom << std::endl;
}

void Room::addItem(std::string itemToAdd) {
    items.push_back(itemToAdd);
    std::cout << "Adding item to Room: " << itemToAdd << std::endl;
}

void Room::addContainer(std::string containerToAdd) {
    containers.push_back(containerToAdd);
    std::cout << "Adding container to Room: " << containerToAdd << std::endl;
}

void Room::addCreature(std::string creatureToAdd) {
    creatures.push_back(creatureToAdd);
    std::cout << "Adding creature to Room: " << creatureToAdd << std::endl;
}

void Room::addTrigger(Trigger triggerToAdd) {
    triggers.push_back(triggerToAdd);
    std::cout << "Adding trigger to Room" << std::endl;
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

std::vector <Trigger> Room::getTriggers() const {
    return triggers;
}