#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
#include "Handler.h"

Handler::Handler(Dungeon* _dungeon) : dungeon(_dungeon) {
	currRoom = "Entrance";

	// Find the index of the Entrance room
	std::vector<Room>::iterator it;
	it = std::find_if((dungeon->getRooms()).begin(), (dungeon->getRooms()).end(), [this](const Room& r){ return r.getName() == currRoom; });
	if (it != (dungeon->getRooms()).end()) {
		currRoomIndex = it - (dungeon->getRooms()).begin();
	}
	else {
		std::cout << "Error: no 'Entrance' room." << std::endl;
	}
}

Handler::~Handler() {}

int Handler::handleInput() {
	std::string input;

	do {
		std::cin >> input;
		int check = handleKey(input);
		if (check == 0) {
			return 0;
		}
	} while (true);

	return 1;
}

int Handler::handleKey(std::string input) {
	if (input == "n" || input == "N" || input == "north" || input == "North" || input == "NORTH") {
		// Find the destination
		std::string destination = (dungeon->getRooms())[currRoomIndex].getNorth();
		if (destination == "none") {
			std::cout << "Cannot move north." << std::endl;
		}
		else {
			std::vector<Room> roomList = (dungeon->getRooms());

			// Find the index of the new room
			std::vector<Room>::iterator it;
			it = std::find_if roomList.begin(), roomList.end(), [destination](Room r){ return r.getName() == destination; });
			if (it != roomList.end())
			{
				currRoomIndex = it - roomList.begin();
				
				// Print the description of the room you just entered
				std::cout << roomList[currRoomIndex].getDescription() << std::endl;
			}
			else {
				std::cout << "Error: north room doesn't exist." << std::endl;
			}
		}
	}
	else if (input == "s" || input == "S" || input == "south" || input == "South" || input == "SOUTH") {
		// Find the destination
		std::string destination = (dungeon->getRooms())[currRoomIndex].getSouth();
		if (destination == "none") {
			std::cout << "Cannot move south." << std::endl;
		}
		else {
			std::vector<Room> roomList = (dungeon->getRooms());

			// Find the index of the new room
			std::vector<Room>::iterator it;
			it = std::find_if (roomList.begin(), roomList.end(), [destination](Room r){ return r.getName() == destination; });
			if (it != (roomList.end())
			{
				currRoomIndex = it - (roomList.begin();
				
				// Print the description of the room you just entered
				std::cout << roomList[currRoomIndex].getDescription() << std::endl;
			}
			else {
				std::cout << "Error: south room doesn't exist." << std::endl;
			}
		}
	}
	else if (input == "e" || input == "E" || input == "east" || input == "East" || input == "EAST") {
		// Find the destination
		std::string destination = (dungeon->getRooms())[currRoomIndex].getEast();
		if (destination == "none") {
			std::cout << "Cannot move east." << std::endl;
		}
		else {
			std::vector<Room> roomList = (dungeon->getRooms());

			// Find the index of the new room
			std::vector<Room>::iterator it;
			it = std::find_if (roomList.begin(), roomList.end(), [destination](Room r){ return r.getName() == destination; });
			if (it != roomList.end())
			{
				currRoomIndex = it - roomList.begin();
				
				// Print the description of the room you just entered
				std::cout << roomList[currRoomIndex].getDescription() << std::endl;
			}
			else {
				std::cout << "Error: east room doesn't exist." << std::endl;
			}
		}
	}
	else if (input == "w" || input == "W" || input == "west" || input == "West" || input == "WEST") {
		// Find the destination
		std::string destination = (dungeon->getRooms())[currRoomIndex].getWest();
		if (destination == "none") {
			std::cout << "Cannot move west." << std::endl;
		}
		else {
			std::vector<Room> roomList = (dungeon->getRooms());

			// Find the index of the new room
			std::vector<Room>::iterator it;
			it = std::find_if (roomList.begin(), roomList.end(), [destination](Room r){ return r.getName() == destination; });
			if (it != roomList.end())
			{
				currRoomIndex = it - roomList.begin();
				
				// Print the description of the room you just entered
				std::cout << roomList[currRoomIndex].getDescription() << std::endl;
			}
			else {
				std::cout << "Error: west room doesn't exist." << std::endl;
			}
		}
	}
	else if (input == "i" || input == "I" || input == "inventory" || input == "Inventory" || input == "INVENTORY") {
		// Deal with an empty inventory
		if (inventory.empty()) {
			std::cout << "Inventory: empty" << std::endl;
		}
		else {
			std::cout << "Inventory:";
			for (int i = 0; i < inventory.size(); i++) {
				if (i == 0) {
					std::cout << " " << inventory[i];
				}
				else {
					std::cout << ", " << inventory[i];
				}
			}
			std::cout << std::endl;
		}
	}
	else if (input.substr(0,5) == "take " || input.substr(0,5) == "Take " || input.substr(0,5) == "TAKE ") {
		// Find the index of the item we're picking up
		int itemIndex;
		std::vector<Item>::iterator it;
		it = std::find_if((dungeon->getItems()).begin(), (dungeon->getItems()).end(), [input](const Item& i){ return i.getName() == input.substr(5); });
		if (it != (dungeon->getItems()).end()) {
			itemIndex = it - (dungeon->getItems()).begin();
		}
		else {
			std::cout << "That item does not exist." << std::endl;
			return 1;
		}

		// Remove the item from the room/container
		std::vector<Item> itemList = (currRoom->getItems());
		for (int i = 0; i < (itemList.size(); i++) {
			std::string theItem = itemList[i].getName();
			std::vector<Item> itemList = (dungeon->getItems());
			
			// Find the index of the item we're assigning the ownership of
			int itemIndex;
			std::vector<Item>::iterator it;
			it = std::find_if(itemList.begin(), itemList.end(), [theItem](const Item& i){ return i.getName() == theItem; });
			if (it != itemList.end()) {
				itemIndex = it - itemList.begin();
				itemList[itemIndex].setOwner(theRoom);
				itemList[itemIndex].setROC("Room");
			}
			else {
				std::cout << "Error: item " << theItem << " appears in room " << theRoom << ", but item " << theItem << " does not exist." << std::endl;
				return 0;
			}
		}

		// Add the item to inventory
		inventory.push_back((dungeon->getItems())[itemIndex].getName());

		std::string destination = (dungeon->getRooms())[currRoomIndex].getNorth();
		if (destination == "none") {
			std::cout << "Cannot move north." << std::endl;
		}
		else {
			std::vector<Room> roomList = (dungeon->getRooms());

			// Find the index of the new room
			std::vector<Room>::iterator it;
			it = std::find_if (roomList.begin(), roomList.end(), [destination](Room r){ return r.getName() == destination; });
			if (it != roomList.end())
			{
				currRoomIndex = it - roomList.begin();
				
				// Print the description of the room you just entered
				std::cout << roomList[currRoomIndex].getDescription() << std::endl;
			}
			else {
				std::cout << "Error: north room doesn't exist." << std::endl;
			}
		}
	}
	else if (input == "open exit" || input == "Open exit" || input == "Open Exit" || input == "OPEN EXIT") {
		// See if the room is an exit
		if ((dungeon->getRooms())[currRoomIndex].getType() == "exit") {
			std::cout << "Game over" << std::endl;
			return 0;
		}
		else {
			std::cout << "This room is not an exit" << std::endl;
		}
	}
	else if (input.substr(0,5) == "drop " || input.substr(0,5) == "Drop " || input.substr(0,5) == "DROP ") {
		// Deal with an empty inventory
		if (inventory.empty()) {
			std::cout << "Inventory: empty" << std::endl;
		}
		else {
			std::cout << "Inventory:";
			for (int i = 0; i < inventory.size(); i++) {
				if (i == 0) {
					std::cout << " " << inventory[i];
				}
				else {
					std::cout << ", " << inventory[i];
				}
			}
			std::cout << std::endl;
		}
	}
	else if (input == "QUIT" || input == "Quit" || input == "quit") {
		return 0;
	}
	else {
		std::cout << "Command not recognized." << std::endl;
	}
	return 1;
}

int Handler::setItemOwners() {
	// Iterate through rooms with items
	for (int i = 0; i < (dungeon->getRooms()).size(); i++) {
		// Iterate through the items in the room
		for (int j = 0; j < ((dungeon->getRooms())[i].getItems()).size(); j++) {
			std::string theItem = ((dungeon->getRooms())[i].getItems())[j];
			std::string theRoom = (dungeon->getRooms())[i].getName();
			std::vector<Item> itemList = (dungeon->getItems());
			
			// Find the index of the item we're assigning the ownership of
			int itemIndex;
			std::vector<Item>::iterator it;
			it = std::find_if(itemList.begin(), itemList.end(), [theItem](const Item& i){ return i.getName() == theItem; });
			if (it != itemList.end()) {
				itemIndex = it - itemList.begin();
				itemList[itemIndex].setOwner(theRoom);
				itemList[itemIndex].setROC("Room");
			}
			else {
				std::cout << "Error: item " << theItem << " appears in room " << theRoom << ", but item " << theItem << " does not exist." << std::endl;
				return 0;
			}
		}
	}
	// Iterate through containers with items
	for (int i = 0; i < (dungeon->getContainers()).size(); i++) {
		// Iterate through the items in the container
		for (int j = 0; j < ((dungeon->getContainers())[i].getItems()).size(); j++) {
			std::string theItem = ((dungeon->getContainers())[i].getItems())[j];
			std::string theContainer = (dungeon->getContainers())[i].getName();
			std::vector<Item> itemList = (dungeon->getItems());
			
			// Find the index of the item we're assigning the ownership of
			int itemIndex;
			std::vector<Item>::iterator it;
			it = std::find_if(itemList.begin(), itemList.end(), [theItem](const Item& i){ return i.getName() == theItem; });
			if (it != itemList.end()) {
				itemIndex = it - itemList.begin();
				itemList[itemIndex].setOwner(theContainer);
				itemList[itemIndex].setROC("Container");
			}
			else {
				std::cout << "Error: item " << theItem << " appears in container " << theContainer << ", but item " << theItem << " does not exist." << std::endl;
				return 0;
			}
		}
	}
	return 1;
}
