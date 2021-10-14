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
    rooms = orig.getRooms();
    creatures = orig.getCreatures();
    items = orig.getItems();
    containers = orig.getContainers();
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

std::vector<Room> Dungeon::getRooms() const {
    return rooms;
}

std::vector<Creature> Dungeon::getCreatures() const {
    return creatures;
}

std::vector<Item> Dungeon::getItems() const {
    return items;
}

std::vector<Container> Dungeon::getContainers() const {
    return containers;
}