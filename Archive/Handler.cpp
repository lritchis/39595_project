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
	it = std::find_if((dungeon->getRooms())->begin(), (dungeon->getRooms())->end(), [this](const Room& r){ return r.getName() == currRoom; });
	if (it != (dungeon->getRooms())->end()) {
		currRoomIndex = it - (dungeon->getRooms())->begin();
	}
	else {
		std::cout << "Error: no 'Entrance' room." << std::endl;
	}
}

Handler::~Handler() {}

int Handler::handleInput() {
	std::string input;
	std::cout << (dungeon->getRooms(0))[currRoomIndex].getDescription() << std::endl;
	do {
		getline(std::cin, input);
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
		std::string destination = (dungeon->getRooms(0))[currRoomIndex].getNorth();
		if (destination == "none") {
			std::cout << "Cannot move north." << std::endl;
		}
		else {
			std::vector<Room> roomList = (dungeon->getRooms(0));

			// Find the index of the new room
			std::vector<Room>::iterator it;
			it = std::find_if (roomList.begin(), roomList.end(), [destination](Room r){ return r.getName() == destination; });
			if (it != roomList.end()) {
				currRoomIndex = it - roomList.begin();
				currRoom = roomList[currRoomIndex].getName();
				
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
		std::string destination = (dungeon->getRooms(0))[currRoomIndex].getSouth();
		if (destination == "none") {
			std::cout << "Cannot move south." << std::endl;
		}
		else {
			std::vector<Room> roomList = (dungeon->getRooms(0));

			// Find the index of the new room
			std::vector<Room>::iterator it;
			it = std::find_if (roomList.begin(), roomList.end(), [destination](Room r){ return r.getName() == destination; });
			if (it != roomList.end()) {
				currRoomIndex = it - (roomList.begin());
				currRoom = roomList[currRoomIndex].getName();
				
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
		std::string destination = (dungeon->getRooms(0))[currRoomIndex].getEast();
		if (destination == "none") {
			std::cout << "Cannot move east." << std::endl;
		}
		else {
			std::vector<Room> roomList = (dungeon->getRooms(0));

			// Find the index of the new room
			std::vector<Room>::iterator it;
			it = std::find_if (roomList.begin(), roomList.end(), [destination](Room r){ return r.getName() == destination; });
			if (it != roomList.end()) {
				currRoomIndex = it - roomList.begin();
				currRoom = roomList[currRoomIndex].getName();
				
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
		std::string destination = (dungeon->getRooms(0))[currRoomIndex].getWest();
		if (destination == "none") {
			std::cout << "Cannot move west." << std::endl;
		}
		else {
			std::vector<Room> roomList = (dungeon->getRooms(0));

			// Find the index of the new room
			std::vector<Room>::iterator it;
			it = std::find_if (roomList.begin(), roomList.end(), [destination](Room r){ return r.getName() == destination; });
			if (it != roomList.end()) {
				currRoomIndex = it - roomList.begin();
				currRoom = roomList[currRoomIndex].getName();
				
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
		// Find the name of the item we're picking up
		std::string itemName = input.substr(5);
		
		// Find the index of the item we're picking up
		int itemIndex;
		std::vector<Item>::iterator it;
		it = std::find_if((dungeon->getItems())->begin(), (dungeon->getItems())->end(), [itemName](const Item& i){ return i.getName() == itemName; });
		if (it != (dungeon->getItems())->end()) {
			itemIndex = it - (dungeon->getItems())->begin();
		}
		else {
			std::cout << "That item does not exist." << std::endl;
			return 1;
		}

		// Remove the item from the room/container
		if((*(dungeon->getRooms()))[currRoomIndex].removeItem(itemName)) {
			// Add the item to inventory
			inventory.push_back((dungeon->getItems(0))[itemIndex].getName());
			std::cout << "Item " << itemName << " added to the inventory." << std::endl;
			(*(dungeon->getItems()))[itemIndex].setOwner("");
			(*(dungeon->getItems()))[itemIndex].setROC("");
			return 1;
		}
		else {
			std::vector<Container> containerList = (dungeon->getContainers(0));
			for (int i = 0; i < containerList.size(); i++) {
				std::string containerName = containerList[i].getName();
				std::vector<std::string> roomContainers = dungeon->getRooms(0)[currRoomIndex].getContainers();

				// Find the index of the container in the room, if it is in the room
				int containerIndex;
				std::vector<std::string>::iterator it;
				it = std::find_if(roomContainers.begin(), roomContainers.end(), [containerName](const std::string& i){ return i == containerName; });
				if (it != roomContainers.end()) {
					containerIndex = it - roomContainers.begin();
					if((*(dungeon->getContainers()))[containerIndex].removeItem(itemName)) {
						// Add the item to inventory
						inventory.push_back((dungeon->getItems(0))[itemIndex].getName());
						std::cout << "Item " << itemName << " added to the inventory." << std::endl;
						(*(dungeon->getItems()))[itemIndex].setOwner("");
						(*(dungeon->getItems()))[itemIndex].setROC("");
						return 1;
					}
				}
			}
		}
		std::cout << "That item is not accessible from here." << std::endl;
	}
	else if (input == "open exit" || input == "Open exit" || input == "Open Exit" || input == "OPEN EXIT") {
		// See if the room is an exit
		if ((dungeon->getRooms(0))[currRoomIndex].getType() == "exit") {
			std::cout << "Game over" << std::endl;
			std::cout << "Victory!" << std::endl;
			return 0;
		}
		else {
			std::cout << "This room is not an exit" << std::endl;
		}
	}
	else if (input.substr(0,5) == "drop " || input.substr(0,5) == "Drop " || input.substr(0,5) == "DROP ") {
		// Find the name of the item we're dropping
		std::string itemName = input.substr(5);
		
		// Deal with an empty inventory
		if (inventory.empty()) {
			std::cout << itemName << " not in inventory." << std::endl;
			return 1;
		}

		// Find the index in inventory of the item we're dropping
		int itemIndex;
		std::vector<std::string>::iterator it;
		it = std::find_if(inventory.begin(), inventory.end(), [itemName](const std::string& i){ return i == itemName; });
		if (it != inventory.end()) {
			itemIndex = it - inventory.begin();

			// Remove item from inventory
	        inventory.erase(inventory.begin() + itemIndex);
			std::cout << itemName << " dropped." << std::endl;

			// Add item to current room
			(*(dungeon->getRooms()))[currRoomIndex].addItem(itemName);

			(*(dungeon->getItems()))[itemIndex].setOwner(currRoom);
			(*(dungeon->getItems()))[itemIndex].setROC("Room");
		}
		else {
			std::cout << itemName << " not in inventory." << std::endl;
			return 1;
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
	for (int i = 0; i < (dungeon->getRooms())->size(); i++) {
		// Iterate through the items in the room
		for (int j = 0; j < ((dungeon->getRooms(0))[i].getItems()).size(); j++) {
			std::string theItem = ((dungeon->getRooms(0))[i].getItems())[j];
			std::string theRoom = (dungeon->getRooms(0))[i].getName();
			std::vector<Item> itemList = (dungeon->getItems(0));
			
			// Find the index of the item we're assigning the ownership of
			int itemIndex;
			std::vector<Item>::iterator it;
			it = std::find_if(itemList.begin(), itemList.end(), [theItem](const Item& i){ return i.getName() == theItem; });
			if (it != itemList.end()) {
				itemIndex = it - itemList.begin();
				(*(dungeon->getItems()))[itemIndex].setOwner(theRoom);
				(*(dungeon->getItems()))[itemIndex].setROC("Room");
			}
			else {
				std::cout << "Error: item " << theItem << " appears in room " << theRoom << ", but item " << theItem << " does not exist." << std::endl;
				return 0;
			}
		}
	}
	// Iterate through containers with items
	for (int i = 0; i < (dungeon->getContainers())->size(); i++) {
		// Iterate through the items in the container
		for (int j = 0; j < ((dungeon->getContainers(0))[i].getItems()).size(); j++) {
			std::string theItem = ((dungeon->getContainers(0))[i].getItems())[j];
			std::string theContainer = (dungeon->getContainers(0))[i].getName();
			std::vector<Item> itemList = (dungeon->getItems(0));
			
			// Find the index of the item we're assigning the ownership of
			int itemIndex;
			std::vector<Item>::iterator it;
			it = std::find_if(itemList.begin(), itemList.end(), [theItem](const Item& i){ return i.getName() == theItem; });
			if (it != itemList.end()) {
				itemIndex = it - itemList.begin();
				(*(dungeon->getItems()))[itemIndex].setOwner(theContainer);
				(*(dungeon->getItems()))[itemIndex].setROC("Container");
			}
			else {
				std::cout << "Error: item " << theItem << " appears in container " << theContainer << ", but item " << theItem << " does not exist." << std::endl;
				return 0;
			}
		}
	}
	return 1;
}
