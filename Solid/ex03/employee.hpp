#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
#include <string>

class Employee
{
protected:
    std::string empName;
    int hourlyValue;

public:
    Employee(const std::string &name, int value)
        : empName(name), hourlyValue(value) {}

    virtual ~Employee() {}

    virtual int executeWorkday() = 0;
    virtual double calculatePay() = 0;

    const std::string &getName() const
    {
        return empName;
    }

    virtual void displayInfo() const
    {
        std::cout << "----------------------------------\n"
                  << "👤 Employee Information\n"
                  << "----------------------------------\n"
                  << "Name          : " << empName << "\n"
                  << "Hourly Value  : " << hourlyValue << " €\n"
                  << "----------------------------------\n";
    }
};

#endif
