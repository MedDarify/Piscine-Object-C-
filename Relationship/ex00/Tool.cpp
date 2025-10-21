// Tool.cpp

#include "Tool.hpp"
#include "worker.hpp" 
#include <iostream>

Tool::Tool() : numberOfUses(0), currentWorker(0) {
	std::cout << "Tool base constructor called" << std::endl;
}

Tool::~Tool() {
	std::cout << "Tool base destructor called" << std::endl;
	if (this->currentWorker) {
		this->currentWorker->takeTool(this);
	}
}

void Tool::setCurrentWorker(Worker* worker) {
	this->currentWorker = worker;
}

Worker* Tool::getCurrentWorker() const {
	return this->currentWorker;
}