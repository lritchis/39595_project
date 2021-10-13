#include "Item.h"
#include "Thing.h"

Item::Item() : Thing () {

}

void Item::setDescription(std::string descToSet) {
    desc = descToSet;
}

void Item::setWriting(std::string writingToSet) {
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