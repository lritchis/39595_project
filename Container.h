#ifndef Container_H_
#define Container_H_

#include <string>
#include <vector>
#include "Thing.h"
class Container : public Thing {
public:
    Container();
    Container(Container& orig);

    virtual void addAccept(std::string acceptToAdd);
    virtual void addItem(std::string itemToAdd);

    virtual std::vector<std::string> getAccepts();
    virtual std::vector<std::string> getItems();

protected:
    std::vector<std::string> accept;
    std::vector<std::string> items;

};
#endif