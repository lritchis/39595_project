#ifndef Item_H_
#define Item_H_

#include <iostream>
#include <string>

class Item : public Thing {
public:
    Item();
    
    virtual void setDescription(std::string descToSet);
    virtual void setWriting(std::string writingToSet);
    virtual void setTurnonAction(std::string turnonActionToSet);
    virtual void setTurnonPrint(std::string turnonPrintToSet);

    virtual std::string getDescription();
    virtual std::string getWriting();
    virtual std::string getTurnonAction();
    virtual std::string getTurnonPrint();

protected:
    std::string desc;
    std::string writing;
    std::string turnonAction;
    std::string turnonPrint;
};

#endif