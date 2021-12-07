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
	if (input == "n") {
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
	else if (input == "s") {
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
	else if (input == "e") {
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
	else if (input == "w") {
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
	else if (input == "i") {
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
	else if (input.substr(0,5) == "take ") {
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
			std::cout << "That item is not accessible from here." << std::endl;
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
					if((*(dungeon->getContainers()))[containerIndex].getOpen()) {
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
		}
		std::cout << "That item is not accessible from here." << std::endl;
	}
	else if (input == "open exit") {
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
	else if (input.substr(0,5) == "drop ") {
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
	else if (input.substr(0,5) == "open ") {
		// Find the name of the item we're dropping
		std::string containerName = input.substr(5);
		
		// Get a list of the containers in the room
		std::vector<std::string> roomContainers = dungeon->getRooms(0)[currRoomIndex].getContainers();

		// Find the index of the container in the room, if it is in the room
		int containerIndex;
		std::vector<std::string>::iterator it;
		it = std::find_if(roomContainers.begin(), roomContainers.end(), [containerName](const std::string& c){ return c == containerName; });
		if (it != roomContainers.end()) {
			containerIndex = it - roomContainers.begin();
			
			// Set the container to open
			(*(dungeon->getContainers()))[containerIndex].setOpen(true);

			// Get a list of items in the container
	        std::vector<std::string> containerItems = (*(dungeon->getContainers()))[containerIndex].getItems();

			// Print the items in the container
			if (!containerItems.empty()) {
				std::cout << containerName << " contains " << containerItems[0];
				for (int i = 0; i < containerItems.size(); i++) {
					if (i > 0) {
						std::cout << ", "  << containerItems[i];
					}
				}
				std::cout << "." << std::endl;
			}
			else {
				// Account for an empty container
				std::cout << containerName << " is empty." << std::endl;
			}
		}
		else {
			std::cout << containerName << " is not accessible from here." << std::endl;
			return 1;
		}
	}
	else if (input.substr(0,5) == "read ") {
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

			// Get the writing on the item
	        std::string writing = (*(dungeon->getItems()))[itemIndex].getWriting();

			// Print the writing
			if (writing != "") {
				std::cout << writing << std::endl;
			}
			else {
				// Account for an item with no writing
				std::cout << "Nothing written." << std::endl;
			}
		}
		else {
			std::cout << itemName << " not in inventory." << std::endl;
			return 1;
		}
	}
	else if (input.substr(0,4) == "put ") {
		// Find the name of the item and container
		std::string restOfString = input.substr(4);
		std::size_t found = restOfString.find(" in ");
		std::string itemName;
		std::string containerName;
		if (found != std::string::npos) {
			itemName = restOfString.substr(0, found);
			containerName = restOfString.substr(found + 4);
		}
		else {
			std::cout << "Command not recognized." << std::endl;
			return 1;
		}
		
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

			// Get a list of the containers in the room
			std::vector<std::string> roomContainers = dungeon->getRooms(0)[currRoomIndex].getContainers();

			// Find the index of the container in the room, if it is in the room
			int containerIndex;
			std::vector<std::string>::iterator it;
			it = std::find_if(roomContainers.begin(), roomContainers.end(), [containerName](const std::string& c){ return c == containerName; });
			if (it != roomContainers.end()) {
				containerIndex = it - roomContainers.begin();
				
				// Ensure the container is open
				if ((*(dungeon->getContainers()))[containerIndex].getOpen()) {
					// Remove item from inventory
					inventory.erase(inventory.begin() + itemIndex);

					// Add item to container
					(*(dungeon->getContainers()))[containerIndex].addItem(itemName);

					(*(dungeon->getItems()))[itemIndex].setOwner(containerName);
					(*(dungeon->getItems()))[itemIndex].setROC("Container");
				}
				else {
					std::cout << "Cannot add " << itemName << " to closed " << containerName << "." << std::endl;
				}
			}
			else {
				std::cout << containerName << " is not accessible from here." << std::endl;
				return 1;
			}
		}
		else {
			std::cout << itemName << " not in inventory." << std::endl;
			return 1;
		}
	}
	else if (input.substr(0,8) == "turn on ") {
		// Find the name of the item we're dropping
		std::string itemName = input.substr(8);

		// Deal with an empty inventory
		if (inventory.empty()) {
			std::cout << itemName << " not in inventory." << std::endl;
			return 1;
		}

		// Find the index in inventory of the item we're turning on
		int itemIndex;
		std::vector<std::string>::iterator it;
		it = std::find_if(inventory.begin(), inventory.end(), [itemName](const std::string& i){ return i == itemName; });
		if (it != inventory.end()) {
			itemIndex = it - inventory.begin();

			// Get turnon action and print
	        std::string turnOnAction = (*(dungeon->getItems()))[itemIndex].getTurnonAction();
			std::string turnOnPrint = (*(dungeon->getItems()))[itemIndex].getTurnonPrint();

			// Perform the turnon action and print the turnon print
			if (turnOnAction != "") {
				int check = handleBehindTheScenes(turnOnAction);
				if (check == 0) {
					return check;
				}
			}
			if (turnOnPrint != "") {
				std::cout << turnOnPrint << std::endl;
			}
		}
		else {
			std::cout << itemName << " not in inventory." << std::endl;
			return 1;
		}
	}
	else if (input == "quit") {
		return 0;
	}
	else {
		std::cout << "Command not recognized." << std::endl;
	}
	return 1;
}

int Handler::handleBehindTheScenes(std::string input) {
	if (input.substr(0,4) == "Add ") {
		// Find the name of the object and the room/container
		std::string restOfString = input.substr(4);
		std::size_t found = restOfString.find(" to ");
		std::string objectName;
		std::string containerName;
		if (found != std::string::npos) {
			objectName = restOfString.substr(0, found);
			containerName = restOfString.substr(found + 4);
		}

		// Determine if room/container is a container
		std::vector<Container> containerList = (dungeon->getContainers(0));
		int containerIndex;
		std::vector<Container>::iterator it;
		it = std::find_if(containerList.begin(), containerList.end(), [containerName](const Container& c){ return c.getName() == containerName; });
		if (it != containerList.end()) {
			containerIndex = it - containerList.begin();
			
			// Add the item to the container
			(*(dungeon->getContainers()))[containerIndex].addItem(objectName);

			// Set item owner and ROC
			std::vector<Item> itemList = (dungeon->getItems(0));
			int itemIndex;
			std::vector<Item>::iterator it;
			it = std::find_if(itemList.begin(), itemList.end(), [objectName](const Item& i){ return i.getName() == objectName; });
			if (it != itemList.end()) {
				itemIndex = it - itemList.begin();
				
				// Add the item to the room
				(*(dungeon->getRooms()))[containerIndex].addItem(objectName);

				(*(dungeon->getItems()))[itemIndex].setOwner(containerName);
				(*(dungeon->getItems()))[itemIndex].setROC("Container");
			}
		}
		else {
			// If the room/container is a room:
			std::vector<Room> roomList = (dungeon->getRooms(0));
			int roomIndex;
			std::vector<Room>::iterator it2;
			it2 = std::find_if(roomList.begin(), roomList.end(), [containerName](const Room& r){ return r.getName() == containerName; });
			if (it2 != roomList.end()) {
				roomIndex = it2 - roomList.begin();
			}

			// Determine if object is a container
			std::vector<Container> containerList = (dungeon->getContainers(0));
			int containerIndex;
			std::vector<Container>::iterator it;
			it = std::find_if(containerList.begin(), containerList.end(), [objectName](const Container& c){ return c.getName() == objectName; });
			if (it != containerList.end()) {
				containerIndex = it - containerList.begin();
				
				// Add the container to the room
				(*(dungeon->getRooms()))[roomIndex].addContainer(objectName);
			}
			else {
				// Otherwise, determine if object is an item
				std::vector<Item> itemList = (dungeon->getItems(0));
				int itemIndex;
				std::vector<Item>::iterator it;
				it = std::find_if(itemList.begin(), itemList.end(), [objectName](const Item& i){ return i.getName() == objectName; });
				if (it != itemList.end()) {
					itemIndex = it - itemList.begin();
					
					// Add the item to the room
					(*(dungeon->getRooms()))[roomIndex].addItem(objectName);

					(*(dungeon->getItems()))[itemIndex].setOwner(containerName);
					(*(dungeon->getItems()))[itemIndex].setROC("Room");
				}
				else {
					// Otherwise, object must be a creature
					std::vector<Creature> creatureList = (dungeon->getCreatures(0));
					int creatureIndex;
					std::vector<Creature>::iterator it;
					it = std::find_if(creatureList.begin(), creatureList.end(), [objectName](const Creature& c){ return c.getName() == objectName; });
					if (it != creatureList.end()) {
						creatureIndex = it - creatureList.begin();
						
						// Add the creature to the room
						(*(dungeon->getRooms()))[roomIndex].addCreature(objectName);
					}
				}
			}
		}
	}
	else if (input.substr(0,7) == "Delete ") {
		// Find the name of the object and the status
		std::string objectName = input.substr(7);

		// Determine if the object is a container
		std::vector<Container> containerList = (dungeon->getContainers(0));
		int containerIndex;
		std::vector<Container>::iterator it;
		it = std::find_if(containerList.begin(), containerList.end(), [objectName](const Container& c){ return c.getName() == objectName; });
		if (it != containerList.end()) {
			containerIndex = it - containerList.begin();
			
			// Delete the contents of the container
			for (int i = 0; i < (*(dungeon->getContainers()))[containerIndex].getItems().size(); i++) {
				handleBehindTheScenes("Delete " + (*(dungeon->getContainers()))[containerIndex].getItems()[i]);
			}

			// Reset the container owner
			(*(dungeon->getContainers()))[containerIndex].setOwner("");

			// Iterate through rooms to remove the container
			for (int i = 0; i < (dungeon->getRooms())->size(); i++) {
				if((*(dungeon->getRooms()))[i].removeContainer(objectName)) {
					return 1;
				}
			}

			// If we can't find it in any of the rooms
			std::cout << "Cannot delete container " << objectName << std::endl;
		}
		else {
			// Determine if the object is an item
			std::vector<Item> itemList = (dungeon->getItems(0));
			int itemIndex;
			std::vector<Item>::iterator it;
			it = std::find_if(itemList.begin(), itemList.end(), [objectName](const Item& i){ return i.getName() == objectName; });
			if (it != itemList.end()) {
				itemIndex = it - itemList.begin();
				
				// Account for an item in the inventory, a room, or a container
				if ((*(dungeon->getItems()))[itemIndex].getROC() == "Room") {
					// Reset the item owner and ROC
					(*(dungeon->getItems()))[itemIndex].setOwner("");
					(*(dungeon->getItems()))[itemIndex].setROC("");

					// Iterate through rooms to remove the item
					for (int i = 0; i < (dungeon->getRooms())->size(); i++) {
						if((*(dungeon->getRooms()))[i].removeItem(objectName)) {
							return 1;
						}
					}

					// If we can't find it in any of the rooms
					std::cout << "Cannot delete item " << objectName << std::endl;
				}
				else if ((*(dungeon->getItems()))[itemIndex].getROC() == "Container") {
					// Reset the item owner and ROC
					(*(dungeon->getItems()))[itemIndex].setOwner("");
					(*(dungeon->getItems()))[itemIndex].setROC("");

					// Iterate through containers to remove the item
					for (int i = 0; i < (dungeon->getContainers())->size(); i++) {
						if((*(dungeon->getContainers()))[i].removeItem(objectName)) {
							return 1;
						}
					}

					// If we can't find it in any of the rooms
					std::cout << "Cannot delete item " << objectName << std::endl;
				}
				else {
					// Otherwise, the item is in our inventory

					// Find the index of the item in our inventory
					int itemIndex;
					std::vector<std::string>::iterator it;
					it = std::find_if(inventory.begin(), inventory.end(), [objectName](const std::string& i){ return i == objectName; });
					if (it != inventory.end()) {
						itemIndex = it - inventory.begin();
						
						// Reset the item owner and ROC
						(*(dungeon->getItems()))[itemIndex].setOwner("");
						(*(dungeon->getItems()))[itemIndex].setROC("");
						
						// Erase the item from our inventory
						inventory.erase(inventory.begin() + itemIndex);
					}
					else {
						// Item not in inventory
						std::cout << "Cannot delete item " << objectName << std::endl;
					}
				}
			}
			else {
				// Determine if the object is a creature
				std::vector<Creature> creatureList = (dungeon->getCreatures(0));
				int creatureIndex;
				std::vector<Creature>::iterator it;
				it = std::find_if(creatureList.begin(), creatureList.end(), [objectName](const Creature& c){ return c.getName() == objectName; });
				if (it != creatureList.end()) {
					creatureIndex = it - creatureList.begin();
					
					// Reset the creature owner
					(*(dungeon->getCreatures()))[creatureIndex].setOwner("");

					// Iterate through rooms to remove the creature
					for (int i = 0; i < (dungeon->getRooms())->size(); i++) {
						if((*(dungeon->getRooms()))[i].removeCreature(objectName)) {
							return 1;
						}
					}

					// If we can't find it in any of the rooms
					std::cout << "Cannot delete creature " << objectName << std::endl;
				}
				else {
					// Determine if the object is a room
					std::vector<Room> roomList = (dungeon->getRooms(0));
					int roomIndex;
					std::vector<Room>::iterator it;
					it = std::find_if(roomList.begin(), roomList.end(), [objectName](const Room& r){ return r.getName() == objectName; });
					if (it != roomList.end()) {
						roomIndex = it - roomList.begin();
						
						// Delete the contents of the room
						for (int i = 0; i < (*(dungeon->getRooms()))[roomIndex].getItems().size(); i++) {
							handleBehindTheScenes("Delete " + (*(dungeon->getRooms()))[roomIndex].getItems()[i]);
						}
						for (int i = 0; i < (*(dungeon->getRooms()))[roomIndex].getContainers().size(); i++) {
							handleBehindTheScenes("Delete " + (*(dungeon->getRooms()))[roomIndex].getContainers()[i]);
						}
						for (int i = 0; i < (*(dungeon->getRooms()))[roomIndex].getCreatures().size(); i++) {
							handleBehindTheScenes("Delete " + (*(dungeon->getRooms()))[roomIndex].getCreatures()[i]);
						}

						// Remove the room
						dungeon->removeRoom(objectName);
					}
				}
			}
		}
	}
	else if (input.substr(0,7) == "Update ") {
		// Find the name of the object and the status
		std::string restOfString = input.substr(7);
		std::size_t found = restOfString.find(" to ");
		std::string objectName;
		std::string status;
		if (found != std::string::npos) {
			objectName = restOfString.substr(0, found);
			status = restOfString.substr(found + 4);
		}

		// Determine if the object is a container
		std::vector<Container> containerList = (dungeon->getContainers(0));
		int containerIndex;
		std::vector<Container>::iterator it;
		it = std::find_if(containerList.begin(), containerList.end(), [objectName](const Container& c){ return c.getName() == objectName; });
		if (it != containerList.end()) {
			containerIndex = it - containerList.begin();
			
			// Set the container status
			(*(dungeon->getContainers()))[containerIndex].setStatus(status);
		}
		else {
			// Determine if the object is an item
			std::vector<Item> itemList = (dungeon->getItems(0));
			int itemIndex;
			std::vector<Item>::iterator it;
			it = std::find_if(itemList.begin(), itemList.end(), [objectName](const Item& i){ return i.getName() == objectName; });
			if (it != itemList.end()) {
				itemIndex = it - itemList.begin();
				
				// Set the item status
				(*(dungeon->getItems()))[itemIndex].setStatus(status);
			}
			else {
				// Determine if the object is a creature
				std::vector<Creature> creatureList = (dungeon->getCreatures(0));
				int creatureIndex;
				std::vector<Creature>::iterator it;
				it = std::find_if(creatureList.begin(), creatureList.end(), [objectName](const Creature& c){ return c.getName() == objectName; });
				if (it != creatureList.end()) {
					creatureIndex = it - creatureList.begin();
					
					// Set the creature status
					(*(dungeon->getCreatures()))[creatureIndex].setStatus(status);
				}
				else {
					// Determine if the object is a room
					std::vector<Room> roomList = (dungeon->getRooms(0));
					int roomIndex;
					std::vector<Room>::iterator it;
					it = std::find_if(roomList.begin(), roomList.end(), [objectName](const Room& r){ return r.getName() == objectName; });
					if (it != roomList.end()) {
						roomIndex = it - roomList.begin();
						
						// Set the room status
						(*(dungeon->getRooms()))[roomIndex].setStatus(status);
					}
				}
			}
		}
	}
	else if (input == "Game Over") {
		std::cout << "Victory!" << std::endl;
		return 0;
	}
	else {
		handleKey(input);
	}
}

int Handler::setObjectOwners() {
	// Iterate through rooms with items, creatures, and containers
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

		// Iterate through the creatures in the room
		for (int j = 0; j < ((dungeon->getRooms(0))[i].getCreatures()).size(); j++) {
			std::string theCreature = ((dungeon->getRooms(0))[i].getCreatures())[j];
			std::string theRoom = (dungeon->getRooms(0))[i].getName();
			std::vector<Creature> creatureList = (dungeon->getCreatures(0));
			
			// Find the index of the creature we're assigning the ownership of
			int creatureIndex;
			std::vector<Creature>::iterator it;
			it = std::find_if(creatureList.begin(), creatureList.end(), [theCreature](const Creature& c){ return c.getName() == theCreature; });
			if (it != creatureList.end()) {
				creatureIndex = it - creatureList.begin();
				(*(dungeon->getCreatures()))[creatureIndex].setOwner(theRoom);
			}
			else {
				std::cout << "Error: creature " << theCreature << " appears in room " << theRoom << ", but creature " << theCreature << " does not exist." << std::endl;
				return 0;
			}
		}

		// Iterate through the containers in the room
		for (int j = 0; j < ((dungeon->getRooms(0))[i].getContainers()).size(); j++) {
			std::string theContainer = ((dungeon->getRooms(0))[i].getContainers())[j];
			std::string theRoom = (dungeon->getRooms(0))[i].getName();
			std::vector<Container> containerList = (dungeon->getContainers(0));
			
			// Find the index of the container we're assigning the ownership of
			int containerIndex;
			std::vector<Container>::iterator it;
			it = std::find_if(containerList.begin(), containerList.end(), [theContainer](const Container& c){ return c.getName() == theContainer; });
			if (it != containerList.end()) {
				containerIndex = it - containerList.begin();
				(*(dungeon->getContainers()))[containerIndex].setOwner(theRoom);
			}
			else {
				std::cout << "Error: container " << theContainer << " appears in room " << theRoom << ", but container " << theContainer << " does not exist." << std::endl;
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
