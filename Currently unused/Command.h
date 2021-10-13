#ifndef Command_H_
#define Command_H_

#include "Condition.h"
#include "string.h"
#include <vector>

class Command : public Condition {
private:
    Command();
    virtual void setType(std::string typeToSet);
    virtual void addPrint(std::string printToAdd);
    virtual void addAction(std::string actionToAdd);

    virtual std::string getType();

protected:
    std::string type;
    std::vector<std::string> print;
    std::vector<std::string> action;
};

#endif 