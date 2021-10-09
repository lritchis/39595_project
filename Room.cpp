#include "Room.h"

Room::Room() : name(""), desc(""), north("none"),east("none"),south("none"),west("none"){

}

Room::Room(std::string _name, std::string _desc) : name(_name), desc(_desc) {

}

