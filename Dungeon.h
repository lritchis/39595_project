#include <string>
#include <vector>

class Dungeon {
public:
    Dungeon(std::string name);
    virtual void getDungeon(std::string name);
    virtual void addRoom(Room room);
    virtual void addItem(Item item);
    virtual void addCreature(Creature creature);
    virtual void addContainer(Container container);
private:
    std::vector<Room> rooms;
    std::vector<Creature> creatures;
    std::vector<Item> items;
    std::vector<Container> containers;
};