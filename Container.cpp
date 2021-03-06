#include "Container.h"

Container::Container() : Thing(), desc("") {
    open = false;
}

Container::Container(const Container& orig) : Thing(orig) {
    desc = orig.getDescription();
    accept = orig.getAccepts();
    items = orig.getItems();
    open = orig.getOpen();
}

Container::~Container() {
    
}

void Container::setDescription(std::string descToSet) {
    desc = descToSet;
}

void Container::setOpen(bool openToSet) {
    open = openToSet;
}

void Container::addItem(std::string itemToAdd) {
    items.push_back(itemToAdd);
}

void Container::addAccept(std::string acceptToAdd) {
    accept.push_back(acceptToAdd);
}

std::string Container::getDescription() const {
    return desc;
}

bool Container::getOpen() const {
    return open;
}

std::vector<std::string> Container::getAccepts() const {
    return accept;
}

std::vector<std::string> Container::getItems() const {
    return items;
}

bool Container::removeItem(std::string itemToRemove) {
    // Find the index of the item we're removing
    int itemIndex;
    std::vector<std::string>::iterator it;
    it = std::find_if(items.begin(), items.end(), [itemToRemove](const std::string& i){ return i == itemToRemove; });
    if (it != items.end()) {
        itemIndex = it - items.begin();
        items.erase(items.begin() + itemIndex);
        return true;
    }
    else {
        return false; // item not in list
    }
}
