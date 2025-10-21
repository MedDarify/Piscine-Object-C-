#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include <iostream>
#include <list>

class Worker; 
class Workshop {
private:
	std::list<Worker*> _workers; 

public:
	Workshop();
	~Workshop();

	void registerWorker(Worker* worker); 
	void releaseWorker(Worker* worker); 

	void executeWorkDay();
};

#endif