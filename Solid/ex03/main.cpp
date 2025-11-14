#include "employeeManager.hpp"
#include "hourlyEmployee.hpp"
#include "salariedEmployee.hpp"
#include <iostream>

int main() {
    EmployeeManager manager;

    TempWorker* t = new TempWorker("Tim the Temp", 10);
    ContractEmployee* c = new ContractEmployee("Connie the Contractor", 20);
    Apprentice* a = new Apprentice("Andy the Apprentice", 8);

    manager.addEmployee(t);
    manager.addEmployee(c);
    manager.addEmployee(a);

    std::cout << "\n--- Logging Specific Hours ---\n";
    t->mobilize(20);
    c->logAbsence(14);
    a->logAbsence(7);
    a->logSchoolHours(40);

    manager.executeWorkday();
    manager.executeWorkday();
    manager.executeWorkday();

    manager.calculatePayroll();

    return 0;
}
