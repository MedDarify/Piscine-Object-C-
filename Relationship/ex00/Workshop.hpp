#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include <iostream>
#include <list>

class Worker; // Forward declaration [cite: 100]

// IV.4 Association [cite: 103]
class Workshop {
private:
	std::list<Worker*> _workers; // [cite: 100]

public:
	Workshop();
	~Workshop();

	// --- Association Methods ---
	void registerWorker(Worker* worker); // [cite: 104]
	void releaseWorker(Worker* worker); // [cite: 104]

	// --- Work Method ---
	void executeWorkDay(); // [cite: 107]
};

#endif