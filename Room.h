#ifndef Room_H_
#define Room_H_

#include "string.h"
#include <vector>
#include <iostream>
#include "Trigger.h"

class Room {
public:
    Room::Room();
    //Room::Room(std::string _name, std::string _type, std::string _status, std::string _desc); 
    //stick to default constructors?

    virtual void setName(std::string nameToSet);
    virtual void setType(std::string typeToSet);
    virtual void setStatus(std::string statusToSet);
    virtual void setDescription(std::string descToSet);
    virtual void setNorth(std::string northRoom);
    virtual void setEast(std::string eastRoom);
    virtual void setSouth(std::string southRoom);
    virtual void setWest(std::string westRoom);

    virtual void addItem(std::string itemToAdd);
    virtual void addContainer(std::string containerToAdd);
    virtual void addCreature(std::string creatureToAdd);
    virtual void addTrigger(Trigger* triggerToAdd);

    virtual std::string getName();
    virtual std::string getType();
    virtual std::string getStatus();
    virtual std::string getDescription();
    virtual std::string getNorth();
    virtual std::string getEast();
    virtual std::string getSouth();
    virtual std::string getWest();

    // !! should we add getters for items, containers, etc.?

private:
    std::string name;
    std::string status;
    std::string type;
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