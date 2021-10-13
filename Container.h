#ifndef Container_H_
#define Container_H_

#include <string>
#include <vector>
#include "Thing.h"
class Container : public Thing {
public:
    Container();

    virtual void addAccept(std::string acceptToAdd);
    virtual void addItem(std::string itemToAdd);

protected:
    std::vector<std::string> accept;
    std::vector<std::string> items;

};
#endif