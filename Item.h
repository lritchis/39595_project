#ifndef Item_H_
#define Item_H_

#include <iostream>
#include <string>
#include "Thing.h"

class Item : public Thing {
public:
    Item();
    Item(const Item& orig);
    virtual ~Item();
    
    virtual void setDescription(std::string descToSet);
    virtual void setWriting(std::string writingToSet);
    virtual void setTurnonAction(std::string turnonActionToSet);
    virtual void setTurnonPrint(std::string turnonPrintToSet);
    virtual void setROC(std::string rocToSet);

    virtual std::string getDescription() const;
    virtual std::string getWriting() const;
    virtual std::string getTurnonAction() const;
    virtual std::string getTurnonPrint() const;
    virtual std::string getROC() const;

protected:
    std::string desc;
    std::string writing;
    std::string turnonAction;
    std::string turnonPrint;
    std::string roomOrContainer;
};

#endif