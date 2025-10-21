#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>
#include <string>
#include <list>
#include "Position.hpp"  
#include "Statistic.hpp" 

class Tool;
class Workshop;

class Worker {
private:
	std::string			_name;
	t_position			_coordonnee; 
	t_statictic			_stat;		 
	std::list<Tool*>	_tools;		 
	std::list<Workshop*> _workshops; 

public:
	Worker(std::string const& name);
	~Worker();

	void giveTool(Tool* tool);
	void takeTool(Tool* tool);
	void useTools();

	void registerToWorkshop(Workshop* workshop); 
	void leaveWorkshop(Workshop* workshop);

	void _internal_addWorkshop(Workshop* workshop);
	void _internal_removeWorkshop(Workshop* workshop);

	void work();

	std::string const& getName() const;
};

#endif