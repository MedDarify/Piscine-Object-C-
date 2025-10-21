#include "worker.hpp"
#include "Tool.hpp"
#include "Workshop.hpp"
#include <algorithm>

Worker::Worker(std::string const &name)
	: _name(name), _coordonnee(0, 0, 0), _stat(1, 0)
{
	std::cout << "Worker " << this->_name << " constructor called" << std::endl;
}

Worker::~Worker()
{
	std::cout << "Worker " << this->_name << " destructor called" << std::endl;
	for (std::list<Tool *>::iterator it = _tools.begin(); it != _tools.end(); ++it)
		if ((*it)->getCurrentWorker() == this)
			(*it)->setCurrentWorker(0);

	while (!_workshops.empty())
		_workshops.front()->releaseWorker(this);
}

void Worker::giveTool(Tool *tool)
{
	if (!tool)
		return;

	if (tool->getCurrentWorker())
		tool->getCurrentWorker()->takeTool(tool);
	this->_tools.push_back(tool);
	tool->setCurrentWorker(this);
	std::cout << this->_name << " acquired a tool." << std::endl;
}

void Worker::takeTool(Tool *tool)
{
	if (!tool)
		return;

	std::list<Tool *>::iterator it = std::find(_tools.begin(), _tools.end(), tool);
	if (it != _tools.end())
	{
		_tools.erase(it);
		tool->setCurrentWorker(0);
		std::cout << this->_name << " lost a tool." << std::endl;
	}
}

void Worker::useTools()
{
	std::cout << this->_name << " starts using tools..." << std::endl;
	for (std::list<Tool *>::iterator it = _tools.begin(); it != _tools.end(); ++it)
		(*it)->use();
}

void Worker::registerToWorkshop(Workshop *workshop)
{
	if (workshop)
	{
		std::cout << this->_name << " attempts to register at a workshop." << std::endl;
		workshop->registerWorker(this);
	}
}

void Worker::leaveWorkshop(Workshop *workshop)
{
	if (workshop)
	{
		std::cout << this->_name << " attempts to leave a workshop." << std::endl;
		workshop->releaseWorker(this);
	}
}

void Worker::_internal_addWorkshop(Workshop *workshop)
{
	std::list<Workshop *>::iterator it = std::find(_workshops.begin(), _workshops.end(), workshop);
	if (it == _workshops.end())
	{
		_workshops.push_back(workshop);
		std::cout << this->_name << " successfully joined a workshop." << std::endl;
	}
}

void Worker::_internal_removeWorkshop(Workshop *workshop)
{
	std::list<Workshop *>::iterator it = std::find(_workshops.begin(), _workshops.end(), workshop);
	if (it != _workshops.end())
	{
		_workshops.erase(it);
		std::cout << this->_name << " successfully left a workshop." << std::endl;
	}
}

void Worker::work()
{
	if (this->_tools.empty())
		std::cout << "Worker " << this->_name << " is working with bare hands." << std::endl;
	else
	{
		std::cout << "Worker " << this->_name << " is working with a tool." << std::endl;
		this->_tools.front()->use();
	}
}

std::string const &Worker::getName() const
{
	return this->_name;
}