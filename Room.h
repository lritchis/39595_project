#ifndef Room_H_
#define Room_H_

#include <string>
#include <vector>
#include <iostream>
#include "Trigger.h"
#include <iterator>
#include <algorithm>

class Room {
public:
    Room();
    Room(const Room& orig);
    virtual ~Room();

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
    virtual void addTrigger(Trigger triggerToAdd);

    virtual std::string getName() const;
    virtual std::string getType() const;
    virtual std::string getStatus() const;
    virtual std::string getDescription() const;
    virtual std::string getNorth() const;
    virtual std::string getEast() const;
    virtual std::string getSouth() const;
    virtual std::string getWest() const;

    virtual std::vector<std::string> getItems() const;
    virtual std::vector<std::string> getContainers() const;
    virtual std::vector<std::string> getCreatures() const;
    virtual std::vector<Trigger> getTriggers(int i) const;
    std::vector<Trigger>* getTriggers();
    
    virtual bool removeItem(std::string itemToRemove); 
    virtual bool removeCreature(std::string creatureToRemove); 
    virtual bool removeContainer(std::string containerToRemove); 

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