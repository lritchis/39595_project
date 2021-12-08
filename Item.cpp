#include "Item.h"
#include "Thing.h"

Item::Item() : Thing(), desc(""), writing(""), roomOrContainer("") {
}

Item::Item(const Item& orig) : Thing(orig) {
    desc = orig.getDescription();
    writing = orig.getWriting();
    turnonAction = orig.getTurnonAction();
    turnonPrint = orig.getTurnonPrint();
    roomOrContainer = orig.getROC();
}

Item::~Item() {}

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

void Item::setROC(std::string rocToSet) {
    roomOrContainer = rocToSet;
}

std::string Item::getDescription() const {
    return desc;
}

std::string Item::getWriting() const {
    return writing;
}

std::string Item::getTurnonAction() const {
    return turnonAction;
}

std::string Item::getTurnonPrint() const {
    return turnonPrint;
}

std::string Item::getROC() const {
    return roomOrContainer;
}
