#include "Workshop.hpp"
#include "worker.hpp"
#include <algorithm> // For std::find

Workshop::Workshop() {
	std::cout << "Workshop constructor called" << std::endl;
}

Workshop::~Workshop() {
	std::cout << "Workshop destructor called" << std::endl;
}

void Workshop::registerWorker(Worker* worker) {
	if (!worker) return;

	std::list<Worker*>::iterator it = std::find(_workers.begin(), _workers.end(), worker);
	if (it == _workers.end()) {
		_workers.push_back(worker);
		worker->_internal_addWorkshop(this);
		std::cout << "Workshop registered " << worker->getName() << "." << std::endl;
	}
}

void Workshop::releaseWorker(Worker* worker) {
	if (!worker) return;
	
	std::list<Worker*>::iterator it = std::find(_workers.begin(), _workers.end(), worker);
	if (it != _workers.end()) {
		_workers.erase(it);
		worker->_internal_removeWorkshop(this);
		std::cout << "Workshop released " << worker->getName() << "." << std::endl;
	}
}

void Workshop::executeWorkDay() {
	std::cout << "\n--- WORKSHOP: Executing Work Day ---" << std::endl;
	for (std::list<Worker*>::iterator it = _workers.begin(); it != _workers.end(); ++it) {
		(*it)->work();
	}
	std::cout << "--- WORKSHOP: Work Day Finished ---" << std::endl;
}