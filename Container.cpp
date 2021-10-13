#include "Container.h"

Container::Container() : Thing() {
    std::cout << "Container constructor of name " << name << std::endl;
}

void Container::addItem(std::string itemToAdd) {
    std::cout << "Adding item " << itemToAdd << " to container " << name << std::endl;
    items.push_back(itemToAdd);
}

void Container::addAccept(std::string acceptToAdd) {
    std::cout << "Adding accept " << acceptToAdd << " to container " << name << std::endl;
    accept.push_back(acceptToAdd);
}