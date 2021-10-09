#ifndef Condition_H_
#define Condition_H_

#include <iostream>
#include <string.h>

class Condition {
public:
    Condition::Condition();
    Condition::Condition(bool _has, std::string _objName, std::string _owner);

    virtual void setHas(bool hasToSet);
    virtual void setObjName(std::string nameToSet);
    virtual void setOwner(std::string ownerName);

    virtual bool getHas();
    virtual std::string getObjName();
    virtual std::string getOwner();
private:
    bool has;
    std::string objName;
    std::string owner;
};

#endif 