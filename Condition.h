#ifndef Condition_H_
#define Condition_H_

#include <iostream>
#include <string>

class Condition {
public:
    Condition();
    Condition(Condition& orig);

    virtual void setHas(std::string hasToSet);
    virtual void setObject(std::string objectToSet);
    virtual void setStatus(std::string statusToSet);
    virtual void setOwner(std::string ownerToSet);
    
    /*
    virtual bool getHas();
    virtual std::string getObjName();
    */
    
protected:
    std::string has;
    std::string object;
    std::string status;
    std::string owner;
};

#endif 