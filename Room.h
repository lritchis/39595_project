#ifndef Room_H_
#define Room_H_

#include "string.h"
#include <vector>
#include <iostream>
#include "Trigger.h"

class Room {
public:
    Room::Room();
    Room::Room(std::string _name, std::string _desc);

    virtual void setName(std::string nameToSet);
    virtual void setDesc(std::string descToSet);
    virtual void setNorth(std::string northRoom);
    virtual void setEast(std::string eastRoom);
    virtual void setSouth(std::string southRoom);
    virtual void setWest(std::string westRoom);

    virtual void addItem(std::string itemToAdd);
    virtual void addContainer(std::string containerToAdd);
    virtual void addCreature(std::string creatureToAdd);
    virtual void addTrigger(Trigger* triggerToAdd);

    virtual std::string getName();
    virtual std::string getDesc();
    virtual std::string getNorth();
    virtual std::string getEast();
    virtual std::string getSouth();
    virtual std::string getEast();

private:
    std::string name;
    std::string desc;
    std::vector<std::string> items;
    std::vector<std::string> containers;
    std::vector<std::string> creatures;
    std::vector<Trigger> triggers;
    
    std::string north;
    std::string east;
    std::string south;
    std::string west;
};


#endif /*Room_H_*/