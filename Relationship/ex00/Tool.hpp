// Tool.hpp

#ifndef TOOL_HPP
#define TOOL_HPP

#include <iostream>

class Worker; // Forward declaration is still needed

// IV.3 Inheritance
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