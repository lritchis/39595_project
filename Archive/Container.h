#ifndef Container_H_
#define Container_H_

#include <string>
#include <vector>
#include "Thing.h"
#include <iterator>
#include <algorithm>

class Container : public Thing {
public:
    Container();
    Container(const Container& orig);
    virtual ~Container();

    virtual void setDescription(std::string descToSet);
    virtual void addAccept(std::string acceptToAdd);
    virtual void addItem(std::string itemToAdd);

    virtual std::string getDescription() const;
    virtual std::vector<std::string> getAccepts() const;
    virtual std::vector<std::string> getItems() const;

    virtual bool removeItem(std::string itemToRemove);

protected:
    std::string desc;
    std::vector<std::string> accept;
    std::vector<std::string> items;

};
#endif