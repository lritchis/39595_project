#include <string>
#include <vector>
#include <iostream>
#include "XMLParser.h"
#include "tinyxml.h"

// for a couple of concepts in parsing, TinyXML converts an XML file into a tree structure containing nodes
// a node for our uses will either be an element node (for example, <Student>...</Student>) or a text node (the "Prof. Midkiff" in <name>Prof. Midkiff</name>)

// in parsing the XML file, there are a few cases where there are multiple methods to perform the same task, so I tried to show both ways in this code
// in those cases, there should be comments pointing to the other methods to perform the task, so choose whichever method you like the best

Dungeon XMLParser::parseDungeon(TiXmlElement* element) {
	Dungeon dungeon = Dungeon();

	// this method of iterating child nodes uses the IterateChildren method as recommended in the TinyXML docs. It is overall the most compact, but it requires a complex while loop condition
	// I would advise against using this unless you understand exactly what it is doing
	// parseCourse shows this same method written as a for loop which might help with understanding this method
	// alternatively, parseRoom shows a cleaner for loop approach using FirstChild and NextSibling to iterate a linked list of child nodes
	TiXmlNode* node = NULL;
	while ((node = element->IterateChildren(node)) != NULL) {
		// this function will cast the node if its a TiXmlElement, or returh NULL if it is not
		// there is also a ToText function to get a TiXmlText, which represents raw text inside an XML element
		TiXmlElement* childElement = node->ToElement();
		if (childElement->ValueStr() == "Room") {
			dungeon.addRoom(parseRoom(childElement));
		}
        else if (childElement->ValueStr() == "Item") {
			dungeon.addItem(parseItem(childElement));
		}
        else if (childElement->ValueStr() == "Container") {
			dungeon.addContainer(parseContainer(childElement));
		}
        else if (childElement->ValueStr() == "Creature") {
			dungeon.addCreature(parseCreature(childElement));
		}
	}

	return dungeon;
}

Room XMLParser::parseRoom(TiXmlElement* element) {
	// fetch the name attribute as a string, if defined 
	Room room = Room();

	// if we wanted, we could make use of activities to set sizes for arrays and alike
	// however, for this example we are just using vectors which resize automatically so its not needed
	//int numActivities = -1;
	//element->Attribute("numActivities", &numActivities);

	// this is the method of iterating nodes that is the cleanest in my opinion. Essentially nodes in TinyXML are a linked list, so we are iterating through a linked list
	// parseStudents shows how to iterate decendents using the element IterateChildren method, which is more compact but also harder to read
	for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling()) {
		// the ToElement function returns null if the node is not an element
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			// if the element type is one we recognize, handle with the proper function
			// note with more if statements, we could parse multiple different child types, for instance we could include Address or Advisor as another element nested inside Student
			
            // ValueStr gets the name of the element type
			std::string name = childElement->ValueStr();
			// this method gets the text contained inside the node
			std::string value = childElement->GetText();

			// need a condition for each attribute we want to parse. Any unknown attributes are ignored
			if (name == "name") {
				room.setName(value);
			}
			else if (name == "status") {
				room.setStatus(value);
			}
			else if (name == "type") {
				room.setType(value);
			}
            else if (name == "description") {
				room.setDescription(value);
			}
            else if (name == "border") {
				std::string direction = getTextFromNamedChild(childElement, "direction");
                if(direction == "north") {
                    room.setNorth(getTextFromNamedChild(childElement, "name"));
                }
                else if(direction == "south") {
                    room.setSouth(getTextFromNamedChild(childElement, "name"));
                }
                else if(direction == "east") {
                    room.setEast(getTextFromNamedChild(childElement, "name"));
                }
                else if(direction == "west") {
                    room.setWest(getTextFromNamedChild(childElement, "name"));
                }
			}
            else if (name == "item") {
                room.addItem(value);
            }
            else if (name == "container") {
                room.addContainer(value);
            }
            else if (name == "creature") {
                room.addCreature(value);
            }
			else if (name == "trigger") {
				room.addTrigger(parseTrigger(childElement));
			}
		}
	}

	return room;
}

Item XMLParser::parseItem(TiXmlElement* element) {
	// there are two different ways to parse the values contained in nested elements
	// this function iterates all the elements child nodes nodes, and if an element matches one of the expected names then set the cooresponding attribute
	// see parseClub for the other method
	Item item = Item();

	// iterate child nodes using IterateChildren in a for loop. This method is a bit more verbose than the while loop used by `parseStudents`, but it is also much easier to read
	// `parseStudent` shows a cleaner way of using a for loop via FirstChild and NextSibling instead. You could also mix the two methods, using FirstChild and IterateChildren for instance
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			// ValueStr gets the name of the element type
			std::string name = childElement->ValueStr();
			// this method gets the text contained inside the node
			std::string value = childElement->GetText();

			// need a condition for each attribute we want to parse. Any unknown attributes are ignored
			if (name == "name") {
				item.setName(value);
			}
			else if (name == "status") {
				item.setStatus(value);
			}
			else if (name == "description") {
				item.setDescription(value);
			}
			else if (name == "writing") {
				item.setWriting(value);
			}
			else if (name == "turnon") {
				item.setTurnonAction(getTextFromNamedChild(childElement, "action"));
				item.setTurnonPrint(getTextFromNamedChild(childElement, "print"));
			}
			else if (name == "trigger") {
				item.addTrigger(parseTrigger(childElement));
			}
		}
	}

	return item;
}

Container XMLParser::parseContainer(TiXmlElement* element) {
	// there are two different ways to parse the values contained in nested elements
	// this function iterates all the elements child nodes nodes, and if an element matches one of the expected names then set the cooresponding attribute
	// see parseClub for the other method
	Container container = Container();

	// iterate child nodes using IterateChildren in a for loop. This method is a bit more verbose than the while loop used by `parseStudents`, but it is also much easier to read
	// `parseStudent` shows a cleaner way of using a for loop via FirstChild and NextSibling instead. You could also mix the two methods, using FirstChild and IterateChildren for instance
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			// ValueStr gets the name of the element type
			std::string name = childElement->ValueStr();
			// this method gets the text contained inside the node
			std::string value = childElement->GetText();

			// need a condition for each attribute we want to parse. Any unknown attributes are ignored
			if (name == "name") {
				container.setName(value);
			}
			else if (name == "status") {
				container.setStatus(value);
			}
			else if (name == "description") {
				container.setDescription(value);
			}
			else if (name == "accept") {
				container.addAccept(value);
			}
			else if (name == "item") {
				container.addItem(value);
			}
			else if (name == "trigger") {
				container.addTrigger(parseTrigger(childElement));
			}
		}
	}

	return container;
}

Creature XMLParser::parseCreature(TiXmlElement* element) {
	// there are two different ways to parse the values contained in nested elements
	// this function iterates all the elements child nodes nodes, and if an element matches one of the expected names then set the cooresponding attribute
	// see parseClub for the other method
	Creature creature = Creature();
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			// ValueStr gets the name of the element type
			std::string name = childElement->ValueStr();
			// this method gets the text contained inside the node
			std::string value = childElement->GetText();

			// need a condition for each attribute we want to parse. Any unknown attributes are ignored
			if (name == "name") {
				creature.setName(value);
			}
			else if (name == "status") {
				creature.setStatus(value);
			}
			else if (name == "vulnerability") {
				creature.addVulnerability(value);
			}
			else if (name == "attack") {
				creature.setAttack(parseAttack(childElement));
			}
			else if (name == "trigger") {
				creature.addTrigger(parseTrigger(childElement));
			}
		}
	}

	return creature;
}

Trigger XMLParser::parseTrigger(TiXmlElement* element) {
	// there are two different ways to parse the values contained in nested elements
	// this function iterates all the elements child nodes nodes, and if an element matches one of the expected names then set the cooresponding attribute
	// see parseClub for the other method
	Trigger trigger = Trigger();
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			// ValueStr gets the name of the element type
			std::string name = childElement->ValueStr();
			// this method gets the text contained inside the node
			std::string value = childElement->GetText();

			// need a condition for each attribute we want to parse. Any unknown attributes are ignored
			if (name == "type") {
				trigger.setType(value);
			}
			else if (name == "command") {
				trigger.setCommand(value);
			}
			else if (name == "condition") {
				trigger.addCondition(parseCondition(childElement));
			}
			else if (name == "print") {
				trigger.addPrint(value);
			}
			else if (name == "action") {
				trigger.addAction(value);
			}
		}
	}

	return trigger;
}

Attack XMLParser::parseAttack(TiXmlElement* element) {
	// there are two different ways to parse the values contained in nested elements
	// this function iterates all the elements child nodes nodes, and if an element matches one of the expected names then set the cooresponding attribute
	// see parseClub for the other method
	Attack attack = Attack();
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			// ValueStr gets the name of the element type
			std::string name = childElement->ValueStr();
			// this method gets the text contained inside the node
			std::string value = childElement->GetText();

			// need a condition for each attribute we want to parse. Any unknown attributes are ignored
			if (name == "condition") {
				attack.addCondition(parseCondition(childElement));
			}
			else if (name == "print") {
				attack.addPrint(value);
			}
			else if (name == "action") {
				attack.addAction(value);
			}
		}
	}

	return attack;
}

Condition XMLParser::parseCondition(TiXmlElement* element) {
	// there are two different ways to parse the values contained in nested elements
	// this function iterates all the elements child nodes nodes, and if an element matches one of the expected names then set the cooresponding attribute
	// see parseClub for the other method
	Condition condition = Condition();
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			// ValueStr gets the name of the element type
			std::string name = childElement->ValueStr();
			// this method gets the text contained inside the node
			std::string value = childElement->GetText();

			// need a condition for each attribute we want to parse. Any unknown attributes are ignored
			if (name == "object") {
				condition.setObject(value);
			}
			else if (name == "status") {
				condition.setStatus(value);
			}
			else if (name == "owner") {
				condition.setOwner(value);
			}
			else if (name == "has") {
				condition.setHas(value);
			}
		}
	}

	return condition;
}

/**
 * Helper function to get the text contained within the element with the given name
 * If the passed element has a child element with the given name, this method returns the text contained in the element
 * If the passed element does not have a child element with the given name, or the child has no text, an empty string is returned
 */
std::string getTextFromNamedChild(TiXmlElement* element, std::string name) {
	TiXmlElement* child = element->FirstChildElement(name);
	if (child != NULL) {
		// we could use GetText instead of getting the child and calling ToText, but I wanted to show another method of parsing the child node
		TiXmlNode* grandchild = child->FirstChild();
		if (grandchild != NULL) {
			// similar to ToElement, this returns null if the node is not a text node
			TiXmlText* text = grandchild->ToText();
			if (text != NULL) {
				return text->ValueStr();
			}
		}
	}
	return "";
}

/**
 * Parses the XML file for the given filename. Returns a vector of students if successful
 * If failed, prints an error and returns an empty vector
 */
Dungeon XMLParser::parseXML(std::string filename) {
	// start parsing XML, we first need to create a TiXmlDocument and read it
	TiXmlDocument doc(filename);
	doc.LoadFile();

	// fetch the top level element, this should be the students array
	TiXmlElement* rootElement = doc.RootElement();
	// null check handles the case where the filename is not a valid XML file
	// there may be a way to get more info (determine whether the file is missing or just contains invalid XML), but for the example this is good enough
	if (rootElement == NULL) {
		std::cerr << "Invalid XML file, contains no data" << std::endl;
		return;
	}
	// this validation is not strictly needed, but its can help avoid the problem of accidently using an XML file from the wrong source
	if (rootElement->ValueStr() != "map") {
		std::cerr << "Invalid XML file, should start with a 'map'" << std::endl;
		return;
	}
	// found the proper root element, so call the relevant parsing function
	return parseDungeon(rootElement);
}

/*
#include <string>
#include <vector>
#include <iostream>
#include "XMLParser.h"
#include "tinyxml.h"

// for a couple of concepts in parsing, TinyXML converts an XML file into a tree structure containing nodes
// a node for our uses will either be an element node (for example, <Student>...</Student>) or a text node (the "Prof. Midkiff" in <name>Prof. Midkiff</name>)

// in parsing the XML file, there are a few cases where there are multiple methods to perform the same task, so I tried to show both ways in this code
// in those cases, there should be comments pointing to the other methods to perform the task, so choose whichever method you like the best

Dungeon* XMLParser::parseDungeon(TiXmlElement* element) {
	Dungeon* dungeon = new Dungeon();

	// this method of iterating child nodes uses the IterateChildren method as recommended in the TinyXML docs. It is overall the most compact, but it requires a complex while loop condition
	// I would advise against using this unless you understand exactly what it is doing
	// parseCourse shows this same method written as a for loop which might help with understanding this method
	// alternatively, parseRoom shows a cleaner for loop approach using FirstChild and NextSibling to iterate a linked list of child nodes
	TiXmlNode* node = NULL;
	while ((node = element->IterateChildren(node)) != NULL) {
		// this function will cast the node if its a TiXmlElement, or returh NULL if it is not
		// there is also a ToText function to get a TiXmlText, which represents raw text inside an XML element
		TiXmlElement* childElement = node->ToElement();
		if (childElement->ValueStr() == "Room") {
			dungeon->addRoom(parseRoom(childElement));
		}
        else if (childElement->ValueStr() == "Item") {
			dungeon->addItem(parseItem(childElement));
		}
        else if (childElement->ValueStr() == "Container") {
			dungeon->addContainer(parseContainer(childElement));
		}
        else if (childElement->ValueStr() == "Creature") {
			dungeon->addCreature(parseCreature(childElement));
		}
	}

	return dungeon;
}

Room* XMLParser::parseRoom(TiXmlElement* element) {
	// fetch the name attribute as a string, if defined 
	Room* room = new Room();

	// if we wanted, we could make use of activities to set sizes for arrays and alike
	// however, for this example we are just using vectors which resize automatically so its not needed
	//int numActivities = -1;
	//element->Attribute("numActivities", &numActivities);

	// this is the method of iterating nodes that is the cleanest in my opinion. Essentially nodes in TinyXML are a linked list, so we are iterating through a linked list
	// parseStudents shows how to iterate decendents using the element IterateChildren method, which is more compact but also harder to read
	for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling()) {
		// the ToElement function returns null if the node is not an element
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			// if the element type is one we recognize, handle with the proper function
			// note with more if statements, we could parse multiple different child types, for instance we could include Address or Advisor as another element nested inside Student
			
            // ValueStr gets the name of the element type
			std::string name = childElement->ValueStr();
			// this method gets the text contained inside the node
			std::string value = childElement->GetText();

			// need a condition for each attribute we want to parse. Any unknown attributes are ignored
			if (name == "name") {
				room->setName(value);
			}
			else if (name == "status") {
				room->setStatus(value);
			}
			else if (name == "type") {
				room->setType(value);
			}
            else if (name == "description") {
				room->setDescription(value);
			}
            else if (name == "border") {
				std::string direction = getTextFromNamedChild(childElement, "direction");
                if(direction == "north") {
                    room->setNorth(getTextFromNamedChild(childElement, "name"));
                }
                else if(direction == "south") {
                    room->setSouth(getTextFromNamedChild(childElement, "name"));
                }
                else if(direction == "east") {
                    room->setEast(getTextFromNamedChild(childElement, "name"));
                }
                else if(direction == "west") {
                    room->setWest(getTextFromNamedChild(childElement, "name"));
                }
			}
            else if (name == "item") {
                room->addItem(value);
            }
            else if (name == "container") {
                room->addContainer(value);
            }
            else if (name == "creature") {
                room->addCreature(value);
            }
			else if (name == "trigger") {
				room->addTrigger(parseTrigger(childElement));
			}
		}
	}

	return room;
}

Item* XMLParser::parseItem(TiXmlElement* element) {
	// there are two different ways to parse the values contained in nested elements
	// this function iterates all the elements child nodes nodes, and if an element matches one of the expected names then set the cooresponding attribute
	// see parseClub for the other method
	Item* item = new Item();

	// iterate child nodes using IterateChildren in a for loop. This method is a bit more verbose than the while loop used by `parseStudents`, but it is also much easier to read
	// `parseStudent` shows a cleaner way of using a for loop via FirstChild and NextSibling instead. You could also mix the two methods, using FirstChild and IterateChildren for instance
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			// ValueStr gets the name of the element type
			std::string name = childElement->ValueStr();
			// this method gets the text contained inside the node
			std::string value = childElement->GetText();

			// need a condition for each attribute we want to parse. Any unknown attributes are ignored
			if (name == "name") {
				item->setName(value);
			}
			else if (name == "status") {
				item->setStatus(value);
			}
			else if (name == "description") {
				item->setDescription(value);
			}
			else if (name == "writing") {
				item->setWriting(value);
			}
			else if (name == "turnon") {
				item->setTurnonAction(getTextFromNamedChild(childElement, "action"));
				item->setTurnonPrint(getTextFromNamedChild(childElement, "print"));
			}
			else if (name == "trigger") {
				item->addTrigger(parseTrigger(childElement));
			}
		}
	}

	return item;
}

Container* XMLParser::parseContainer(TiXmlElement* element) {
	// there are two different ways to parse the values contained in nested elements
	// this function iterates all the elements child nodes nodes, and if an element matches one of the expected names then set the cooresponding attribute
	// see parseClub for the other method
	Container* container = new Container();

	// iterate child nodes using IterateChildren in a for loop. This method is a bit more verbose than the while loop used by `parseStudents`, but it is also much easier to read
	// `parseStudent` shows a cleaner way of using a for loop via FirstChild and NextSibling instead. You could also mix the two methods, using FirstChild and IterateChildren for instance
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			// ValueStr gets the name of the element type
			std::string name = childElement->ValueStr();
			// this method gets the text contained inside the node
			std::string value = childElement->GetText();

			// need a condition for each attribute we want to parse. Any unknown attributes are ignored
			if (name == "name") {
				container->setName(value);
			}
			else if (name == "status") {
				container->setStatus(value);
			}
			else if (name == "description") {
				container->setDescription(value);
			}
			else if (name == "accept") {
				container->addAccept(value);
			}
			else if (name == "item") {
				container->addItem(value);
			}
			else if (name == "trigger") {
				container->addTrigger(parseTrigger(childElement));
			}
		}
	}

	return container;
}

Creature* XMLParser::parseCreature(TiXmlElement* element) {
	// there are two different ways to parse the values contained in nested elements
	// this function iterates all the elements child nodes nodes, and if an element matches one of the expected names then set the cooresponding attribute
	// see parseClub for the other method
	Creature* creature = new Creature();
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			// ValueStr gets the name of the element type
			std::string name = childElement->ValueStr();
			// this method gets the text contained inside the node
			std::string value = childElement->GetText();

			// need a condition for each attribute we want to parse. Any unknown attributes are ignored
			if (name == "name") {
				creature->setName(value);
			}
			else if (name == "status") {
				creature->setStatus(value);
			}
			else if (name == "vulnerability") {
				creature->addVulnerability(value);
			}
			else if (name == "attack") {
				creature->setAttack(parseAttack(childElement));
			}
			else if (name == "trigger") {
				creature->addTrigger(parseTrigger(childElement));
			}
		}
	}

	return creature;
}

Trigger* XMLParser::parseTrigger(TiXmlElement* element) {
	// there are two different ways to parse the values contained in nested elements
	// this function iterates all the elements child nodes nodes, and if an element matches one of the expected names then set the cooresponding attribute
	// see parseClub for the other method
	Trigger* trigger = new Trigger();
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			// ValueStr gets the name of the element type
			std::string name = childElement->ValueStr();
			// this method gets the text contained inside the node
			std::string value = childElement->GetText();

			// need a condition for each attribute we want to parse. Any unknown attributes are ignored
			if (name == "type") {
				trigger->setType(value);
			}
			else if (name == "command") {
				trigger->setCommand(value);
			}
			else if (name == "condition") {
				trigger->addCondition(parseCondition(childElement));
			}
			else if (name == "print") {
				trigger->addPrint(value);
			}
			else if (name == "action") {
				trigger->addAction(value);
			}
		}
	}

	return trigger;
}

Attack* XMLParser::parseAttack(TiXmlElement* element) {
	// there are two different ways to parse the values contained in nested elements
	// this function iterates all the elements child nodes nodes, and if an element matches one of the expected names then set the cooresponding attribute
	// see parseClub for the other method
	Attack* attack = new Attack();
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			// ValueStr gets the name of the element type
			std::string name = childElement->ValueStr();
			// this method gets the text contained inside the node
			std::string value = childElement->GetText();

			// need a condition for each attribute we want to parse. Any unknown attributes are ignored
			if (name == "condition") {
				attack->addCondition(parseCondition(childElement));
			}
			else if (name == "print") {
				attack->addPrint(value);
			}
			else if (name == "action") {
				attack->addAction(value);
			}
		}
	}

	return attack;
}

Condition* XMLParser::parseCondition(TiXmlElement* element) {
	// there are two different ways to parse the values contained in nested elements
	// this function iterates all the elements child nodes nodes, and if an element matches one of the expected names then set the cooresponding attribute
	// see parseClub for the other method
	Condition* condition = new Condition();
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
			// ValueStr gets the name of the element type
			std::string name = childElement->ValueStr();
			// this method gets the text contained inside the node
			std::string value = childElement->GetText();

			// need a condition for each attribute we want to parse. Any unknown attributes are ignored
			if (name == "object") {
				condition->setObject(value);
			}
			else if (name == "status") {
				condition->setStatus(value);
			}
			else if (name == "owner") {
				condition->setOwner(value);
			}
			else if (name == "has") {
				condition->setHas(value);
			}
		}
	}

	return condition;
}

/**
 * Helper function to get the text contained within the element with the given name
 * If the passed element has a child element with the given name, this method returns the text contained in the element
 * If the passed element does not have a child element with the given name, or the child has no text, an empty string is returned
 */
/*
std::string getTextFromNamedChild(TiXmlElement* element, std::string name) {
	TiXmlElement* child = element->FirstChildElement(name);
	if (child != NULL) {
		// we could use GetText instead of getting the child and calling ToText, but I wanted to show another method of parsing the child node
		TiXmlNode* grandchild = child->FirstChild();
		if (grandchild != NULL) {
			// similar to ToElement, this returns null if the node is not a text node
			TiXmlText* text = grandchild->ToText();
			if (text != NULL) {
				return text->ValueStr();
			}
		}
	}
	return "";
}

/**
 * Parses the XML file for the given filename. Returns a vector of students if successful
 * If failed, prints an error and returns an empty vector
 */
/*
Dungeon* XMLParser::parseXML(std::string filename) {
	// start parsing XML, we first need to create a TiXmlDocument and read it
	TiXmlDocument doc(filename);
	doc.LoadFile();

	// fetch the top level element, this should be the students array
	TiXmlElement* rootElement = doc.RootElement();
	// null check handles the case where the filename is not a valid XML file
	// there may be a way to get more info (determine whether the file is missing or just contains invalid XML), but for the example this is good enough
	if (rootElement == NULL) {
		std::cerr << "Invalid XML file, contains no data" << std::endl;
		return NULL;
	}
	// this validation is not strictly needed, but its can help avoid the problem of accidently using an XML file from the wrong source
	if (rootElement->ValueStr() != "map") {
		std::cerr << "Invalid XML file, should start with a 'map'" << std::endl;
		return NULL;
	}
	// found the proper root element, so call the relevant parsing function
	return parseDungeon(rootElement);
}
*/