#include "Container.h"

Container::Container() : Thing() {
    std::cout << "Creating a container" << std::endl;
}

Container::Container(Container& orig) : Thing(orig) {
    accept = orig.getAccepts();
    items = orig.getItems();
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

std::string Container::getDescription() {
    return desc;
}

std::vector<std::string> Container::getAccepts() {
    return accept;
}

std::vector<std::string> Container::getItems() {
    return items;
}

