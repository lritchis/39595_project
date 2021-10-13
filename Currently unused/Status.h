#ifndef Status_H_
#define Status_H_

#include "Condition.h"
#include "string.h"

class Status : public Condition {
public:
    Status();

    virtual void setStatus(std::string statusToSet);

    virtual std::string getStatus();

protected:
    std::string status;
};

#endif