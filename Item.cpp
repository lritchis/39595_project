#include "Item.h"
#include "Thing.h"

Item::Item() : Thing () {
    std::cout << "Item constructor with name " << name << std::endl;
}

void Item::setDescription(std::string descToSet) {
    std::cout << "Set Item description to " << descToSet << std::endl;
    desc = descToSet;
}

void Item::setWriting(std::string writingToSet) {
    std::cout << "Set Item writing to " << writingToSet << std::endl;
    writing = writingToSet;
}

void Item::setTurnonAction(std::string turnonActionToSet) {
    turnonAction = turnonActionToSet;
}

void Item::setTurnonPrint(std::string turnonPrintToSet) {
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