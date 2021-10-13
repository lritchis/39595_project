#ifndef Dungeon_H_
#define Dungeon_H_

#include <string>
#include <vector>
#include "Room.h"
#include "Item.h"
#include "Container.h"
#include "Creature.h"

class Dungeon {
public:
    Dungeon();
    Dungeon(Dungeon& orig);
    virtual void addRoom(Room room);
    virtual void addItem(Item item);
    virtual void addCreature(Creature creature);
    virtual void addContainer(Container container);

    std::vector<Room> getRooms();
    std::vector<Creature> getCreatures();
    std::vector<Item> getItems();
    std::vector<Container>getContainers();

private:
    std::vector<Room> rooms;
    std::vector<Creature> creatures;
    std::vector<Item> items;
    std::vector<Container> containers;
};

#endif