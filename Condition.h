#ifndef Condition_H_
#define Condition_H_

#include <iostream>
#include <string>

class Condition {
public:
    Condition::Condition();
    Condition::Condition(bool _has, std::string _objName);

    virtual void setHas(bool hasToSet);
    virtual void setObjName(std::string nameToSet);
    

    virtual bool getHas();
    virtual std::string getObjName();
    
protected:
    bool has;
    std::string objName;
};

#endif 