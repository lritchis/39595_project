#include "string.h"
#include <vector>
#include <iostream>
#include "Dungeon.h"

Dungeon::Dungeon() {
    std::cout << "Creating Dungeon Map" << std::endl;
}

void Dungeon::addRoom(Room room) {
    rooms.push_back(room);
    std::cout << "Adding room " << room.getName() << " to dungeon" << std::endl;
}

void Dungeon::addItem(Item item) {
    items.push_back(item);
    std::cout << "Adding item " << item.getName() << " to dungeon" << std::endl;

void Dungeon::addCreature(Creature creature) {
    creatures.push_back(creature);
    std::cout << "Adding creature " << creature.getName() << " to dungeon" << std::endl;
}

void Dungeon::addContainer(Container container) {
    containers.push_back(container);
    std::cout << "Adding container " << container.getName() << " to dungeon" << std::endl;
}
