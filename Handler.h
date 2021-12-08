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
    virtual int checkCommandTriggers(std::string command);
    virtual int checkItemCommandTriggers(std::string command, std::string item);
    virtual int checkTriggers();
    virtual int checkItemTriggers(std::string item);
    virtual bool checkCondition(Condition cond);

private:
    std::vector<std::string> inventory;
	std::string currRoom;
    int currRoomIndex;
    Dungeon* dungeon;

};