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
    
    
    virtual std::string getHas();
    virtual std::string getObject();
    virtual std::string getStatus();
    virtual std::string getOwner();
    
    
protected:
    std::string has;
    std::string object;
    std::string status;
    std::string owner;
};

#endif 