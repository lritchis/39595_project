#ifndef Condition_H_
#define Condition_H_

#include <iostream>
#include <string>

class Condition {
public:
    Condition();
    Condition(const Condition& orig);

    virtual void setHas(std::string hasToSet);
    virtual void setObject(std::string objectToSet);
    virtual void setStatus(std::string statusToSet);
    virtual void setOwner(std::string ownerToSet);
    
    
    virtual std::string getHas() const;
    virtual std::string getObject() const;
    virtual std::string getStatus() const;
    virtual std::string getOwner() const;
    
    
protected:
    std::string has;
    std::string object;
    std::string status;
    std::string owner;
};

#endif 