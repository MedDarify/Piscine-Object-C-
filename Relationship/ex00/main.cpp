#include "worker.hpp"
#include "Workshop.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include <iostream>

void demonstrateComposition() {
	std::cout << "\n┌────────────────────────────────────────────┐\n";
	std::cout << "│          1. COMPOSITION DEMO               │\n";
	std::cout << "└────────────────────────────────────────────┘\n";
	std::cout << "🧱 Creating Worker: 'Bob' (on stack)...\n";
	Worker bob("Bob");
	std::cout << "🧹 'Bob' is now leaving scope...\n";
}

void demonstrateAggregation() {
	std::cout << "\n┌────────────────────────────────────────────┐\n";
	std::cout << "│     2. AGGREGATION & INHERITANCE DEMO      │\n";
	std::cout << "└────────────────────────────────────────────┘\n";
	std::cout << "🛠️  Creating tools on heap...\n";
	Tool* shovel = new Shovel();
	Tool* hammer = new Hammer();

	{
		std::cout << "\n╭───────────────────────────╮\n";
		std::cout << "│ Entering new work scope   │\n";
		std::cout << "╰───────────────────────────╯\n";
		std::cout << "👷 Creating Worker: 'Alice' (on stack)...\n";
		Worker alice("Alice");
		alice.giveTool(shovel);
		alice.giveTool(hammer);
		alice.useTools();
		std::cout << "🚪 'Alice' is leaving scope...\n";
	}
	std::cout << "\n✅ Exited scope successfully.\n";
	std::cout << "🔩 Tools still exist after Worker destruction:\n";
	shovel->use();
	hammer->use();

	std::cout << "\n🧪 Testing tool reassignment...\n";
	Worker workerA("WorkerA");
	Worker workerB("WorkerB");

	workerA.giveTool(shovel);
	std::cout << "🔧 Tool now belongs to WorkerA.\n";

	workerB.giveTool(shovel);
	std::cout << "🔧 Tool reassigned to WorkerB.\n";

	std::cout << "\n👷 WorkerA uses tools:\n";
	workerA.useTools();
	std::cout << "👷 WorkerB uses tools:\n";
	workerB.useTools();

	std::cout << "\n🧹 Cleaning up heap-allocated tools...\n";
	delete shovel;
	delete hammer;
}

void demonstrateAssociation() {
	std::cout << "\n┌────────────────────────────────────────────┐\n";
	std::cout << "│             3. ASSOCIATION DEMO            │\n";
	std::cout << "└────────────────────────────────────────────┘\n";
	std::cout << "🏭 Creating Workers and Workshops...\n";
	Worker* charlie = new Worker("Charlie");
	Worker* diana = new Worker("Diana");
	Workshop* mainWorkshop = new Workshop();
	Workshop* secondaryWorkshop = new Workshop();

	mainWorkshop->registerWorker(charlie);
	mainWorkshop->registerWorker(diana);
	charlie->registerToWorkshop(secondaryWorkshop);

	mainWorkshop->executeWorkDay();
	secondaryWorkshop->executeWorkDay();

	std::cout << "\n🚪 Diana is leaving the main workshop...\n";
	mainWorkshop->releaseWorker(diana);

	mainWorkshop->executeWorkDay();

	std::cout << "\n🧹 Cleaning up Association objects...\n";
	delete charlie;
	delete diana;
	delete mainWorkshop;
	delete secondaryWorkshop;
}

int main() {
	std::cout << "\n============================================\n";
	std::cout << "        OBJECT RELATIONSHIP DEMONSTRATION    \n";
	std::cout << "============================================\n";

	demonstrateComposition();
	demonstrateAggregation();
	demonstrateAssociation();

	std::cout << "\n🏁 All demonstrations complete.\n";
	return 0;
}
