#ifndef Thing_H_
#define Thing_H_
#include <iostream>
#include <vector>
#include "Trigger.h"
#include <string>

class Thing{
public:
    Thing();
    Thing(Thing& orig);
    
    virtual void setName(std::string nameToSet);
    virtual void setRoomNum(int roomToSet);
    virtual void setStatus(std::string statusToSet);

    virtual std::string getName();
    virtual int getRoomNum();
    virtual std::string getStatus();
    virtual std::vector<Trigger> getTriggers();

    virtual void addTrigger(Trigger triggerToAdd);

protected:
    std::string name;
    int roomNum;
    std::string status;
    std::vector<Trigger> triggers;

};  

#endif /* Thing_H_ */