#include "Container.h"

Container::Container() : Thing() {
    std::cout << "Container constructor of name " << name << std::endl;
}

Container::Container(Container& orig) : Thing(orig) {
    accept = orig.getAccepts();
    items = orig.getItems();
}

void Container::addItem(std::string itemToAdd) {
    std::cout << "Adding item " << itemToAdd << " to container " << name << std::endl;
    items.push_back(itemToAdd);
}

void Container::addAccept(std::string acceptToAdd) {
    std::cout << "Adding accept " << acceptToAdd << " to container " << name << std::endl;
    accept.push_back(acceptToAdd);
}

std::vector<std::string> Container::getAccepts() {
    return accept;
}

std::vector<std::string> Container::getItems() {
    return items;
}

