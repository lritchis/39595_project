#include "Container.h"

Container::Container() : Thing() {
    
}

void Container::addItem(std::string itemToAdd) {
    items.push_back(itemToAdd);
}

void Container::addAccept(std::string acceptToAdd) {
    accept.push_back(acceptToAdd);
}