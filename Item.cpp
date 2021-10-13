#include "Item.h"
#include "Thing.h"

Item::Item() : Thing () {
    std::cout << "Creating an Item" << std::endl;
}

void Item::setDescription(std::string descToSet) {
    std::cout << "Setting item description to " << descToSet << std::endl;
    desc = descToSet;
}

void Item::setWriting(std::string writingToSet) {
    std::cout << "Setting item writing to " << writingToSet << std::endl;
    writing = writingToSet;
}

void Item::setTurnonAction(std::string turnonActionToSet) {
    std::cout << "Setting the turnon action to " << turnonActionToSet << std::endl;
    turnonAction = turnonActionToSet;
}

void Item::setTurnonPrint(std::string turnonPrintToSet) {
    std::cout << "Setting the turnon print to " << turnonPrintToSet << std::endl;
    turnonPrint = turnonPrintToSet;
}

std::string Item::getDescription() {
    return desc;
}

std::string Item::getWriting() {
    return writing;
}

std::string Item::getTurnonAction() {
    return turnonAction;
}

std::string Item::getTurnonPrint() {
    return turnonPrint;
}