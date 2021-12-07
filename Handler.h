#include <iostream>
#include <string>
#include <vector>
#include "Dungeon.h"

class Handler {
public:
    Handler(Dungeon* _dungeon);
    virtual ~Handler();
    virtual int handleInput();
	virtual int handleKey(std::string input);
    virtual int handleBehindTheScenes(std::string input);
    virtual int setObjectOwners();

private:
    std::vector<std::string> inventory;
	std::string currRoom;
    int currRoomIndex;
    Dungeon* dungeon;

};