#ifndef EMPLOYEEMANAGEMENT_HPP
#define EMPLOYEEMANAGEMENT_HPP

#include "employee.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

class EmployeeManager
{
private:
    std::vector<Employee *> _employees;

public:
    EmployeeManager() {}

    ~EmployeeManager()
    {
        for (std::vector<Employee *>::iterator it = _employees.begin(); it != _employees.end(); ++it)
        {
            delete *it;
        }
        _employees.clear();
        std::cout << "🧹 Manager: All employees cleared from memory.\n";
    }

    void addEmployee(Employee *e)
    {
        if (!e)
        {
            std::cout << "⚠️  Manager: Cannot hire a null employee.\n";
            return;
        }
        _employees.push_back(e);
        std::cout << "✅ Manager: Hired " << e->getName() << ".\n";
    }

    void removeEmployee(Employee *e)
    {
        if (!e)
        {
            std::cout << "⚠️  Manager: Invalid employee pointer.\n";
            return;
        }

        std::vector<Employee *>::iterator it = std::find(_employees.begin(), _employees.end(), e);
        if (it != _employees.end())
        {
            std::cout << "❌ Manager: Removed " << e->getName() << ".\n";
            delete *it;
            _employees.erase(it);
        }
        else
        {
            std::cout << "⚠️  Manager: Employee not found: " << e->getName() << ".\n";
        }
    }

    void executeWorkday()
    {
        std::cout << "\n🕒 --- Manager: Executing a 7-hour Workday ---\n";
        for (std::vector<Employee *>::iterator it = _employees.begin(); it != _employees.end(); ++it)
        {
            (*it)->executeWorkday();
        }
    }

    void calculatePayroll()
    {
        std::cout << "\n💰 --- Manager: Calculating Monthly Payroll ---\n";
        for (std::vector<Employee *>::iterator it = _employees.begin(); it != _employees.end(); ++it)
        {
            double pay = (*it)->calculatePay();
            std::cout << "🧾 Manager: Paying " << (*it)->getName()
                      << " " << pay << " €.\n";
        }
    }
};

#endif
