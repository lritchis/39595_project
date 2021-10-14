#include "Container.h"

Container::Container() : Thing() {
    std::cout << "Creating a container" << std::endl;
}

Container::Container(const Container& orig) : Thing(orig) {
    desc = orig.getDescription();
    accept = orig.getAccepts();
    items = orig.getItems();
}

Container::~Container() {
    
}

void Container::setDescription(std::string descToSet) {
    std::cout << "Setting container description to " << descToSet << std::endl;
    desc = descToSet;
}

void Container::addItem(std::string itemToAdd) {
    std::cout << "Adding item " << itemToAdd << " to container" << std::endl;
    items.push_back(itemToAdd);
}

void Container::addAccept(std::string acceptToAdd) {
    std::cout << "Adding item " << acceptToAdd << " to list of acceptable items for container" << std::endl;
    accept.push_back(acceptToAdd);
}

std::string Container::getDescription() const {
    return desc;
}

std::vector<std::string> Container::getAccepts() const {
    return accept;
}

std::vector<std::string> Container::getItems() const {
    return items;
}

