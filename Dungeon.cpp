#include "string.h"
#include <vector>
#include <iostream>
#include "Dungeon.h"

Dungeon::Dungeon() {
}

Dungeon::Dungeon(int i) {
}

Dungeon::Dungeon(const Dungeon& orig) {
    rooms = orig.getRooms(0);
    creatures = orig.getCreatures(0);
    items = orig.getItems(0);
    containers = orig.getContainers(0);
}

void Dungeon::addRoom(Room room) {
    rooms.push_back(room);
}

void Dungeon::addItem(Item item) {
    items.push_back(item);
}

void Dungeon::addCreature(Creature creature) {
    creatures.push_back(creature);
}

void Dungeon::addContainer(Container container) {
    containers.push_back(container);
}

std::vector<Room>* Dungeon::getRooms() {
    return &rooms;
}

std::vector<Creature>* Dungeon::getCreatures() {
    return &creatures;
}

std::vector<Item>* Dungeon::getItems() {
    return &items;
}

std::vector<Container>* Dungeon::getContainers() {
    return &containers;
}

std::vector<Room> Dungeon::getRooms(int i) const {
    return rooms;
}

std::vector<Creature> Dungeon::getCreatures(int i) const {
    return creatures;
}

std::vector<Item> Dungeon::getItems(int i) const {
    return items;
}

std::vector<Container> Dungeon::getContainers(int i) const {
    return containers;
}

bool Dungeon::removeRoom(std::string roomToRemove) {
    // Find the index of the room we're removing
    int roomIndex;
    std::vector<Room>::iterator it;
    it = std::find_if(rooms.begin(), rooms.end(), [roomToRemove](const Room& r){ return r.getName() == roomToRemove; });
    if (it != rooms.end()) {
        roomIndex = it - rooms.begin();

        rooms.erase(rooms.begin() + roomIndex);
        return true;
    }
    else {
        return false; // room not in list
    }
}
