#include "string.h"
#include <vector>
#include <iostream>
#include "Dungeon.h"

Dungeon::Dungeon() {
    std::cout << "Creating Dungeon Map" << std::endl;
}

Dungeon::Dungeon(int i) {
    std::cout << "Creating empty Dungeon Map" << std::endl;
}

Dungeon::Dungeon(const Dungeon& orig) {
    rooms = orig.getRooms(0);
    creatures = orig.getCreatures(0);
    items = orig.getItems(0);
    containers = orig.getContainers(0);
}

void Dungeon::addRoom(Room room) {
    rooms.push_back(room);
    std::cout << "Adding room " << room.getName() << " to dungeon" << std::endl;
}

void Dungeon::addItem(Item item) {
    items.push_back(item);
    std::cout << "Adding item " << item.getName() << " to dungeon" << std::endl;
}

void Dungeon::addCreature(Creature creature) {
    creatures.push_back(creature);
    std::cout << "Adding creature " << creature.getName() << " to dungeon" << std::endl;
}

void Dungeon::addContainer(Container container) {
    containers.push_back(container);
    std::cout << "Adding container " << container.getName() << " to dungeon" << std::endl;
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