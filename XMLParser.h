#pragma once
#include <vector>
#include <string>
#include "Dungeon.h"
#include "Room.h"
#include "Thing.h"
#include "Item.h"
#include "Container.h"
#include "Creature.h"
#include "Trigger.h"
#include "Condition.h"
#include "Turnon.h"
#include "Attack.h"
#include "tinyxml.h"

// The way this class is set up, you could easily use static methods or non-class C functions.
// I choose to use functions in a class to use something familar
class XMLParser {
private:
	Dungeon* parseDungeon(TiXmlElement* element);
    Room* parseRoom(TiXmlElement* element);
    Thing* parseThing(TiXmlElement* element);
    Item* parseItem(TiXmlElement* element);
    Container* parseContainer(TiXmlElement* element);
    Creature* parseCreature(TiXmlElement* element);
    Trigger* parseTrigger(TiXmlElement* element);
    Condition* parseCondition(TiXmlElement* element);
    Turnon* parseTurnon(TiXmlElement* element);
    Attack* parseAttack(TiXmlElement* element);

public:
	Dungeon* parseXML(std::string filename);
};

