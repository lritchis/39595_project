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
    Dungeon(int i);
    Dungeon(const Dungeon& orig);
    virtual void addRoom(Room room);
    virtual void addItem(Item item);
    virtual void addCreature(Creature creature);
    virtual void addContainer(Container container);

    std::vector<Room>* getRooms();
    std::vector<Creature>* getCreatures();
    std::vector<Item>* getItems();
    std::vector<Container>* getContainers();
    
    std::vector<Room> getRooms(int i) const;
    std::vector<Creature> getCreatures(int i) const;
    std::vector<Item> getItems(int i) const;
    std::vector<Container> getContainers(int i) const;

    virtual bool removeRoom(std::string roomToRemove); 

private:
    std::vector<Room> rooms;
    std::vector<Creature> creatures;
    std::vector<Item> items;
    std::vector<Container> containers;
};

#endif