// Tool.hpp

#ifndef TOOL_HPP
#define TOOL_HPP

#include <iostream>

class Worker;

class Tool
{
protected:
    int numberOfUses;
    Worker *currentWorker;

public:
    Tool();
    virtual ~Tool();

    virtual void use() = 0;
    void setCurrentWorker(Worker *worker);
    Worker *getCurrentWorker() const;
};

#endif