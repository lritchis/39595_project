#ifndef Item_H_
#define Item_H_

#include <iostream>
#include <string>

class Item : public Thing {
public:
    Item();
    Item(const Item& orig);
    
    virtual void setDescription(std::string descToSet);
    virtual void setWriting(std::string writingToSet);
    virtual void setTurnonAction(std::string turnonActionToSet);
    virtual void setTurnonPrint(std::string turnonPrintToSet);

    virtual std::string getDescription() const;
    virtual std::string getWriting() const;
    virtual std::string getTurnonAction() const;
    virtual std::string getTurnonPrint() const;

protected:
    std::string desc;
    std::string writing;
    std::string turnonAction;
    std::string turnonPrint;
};

#endif