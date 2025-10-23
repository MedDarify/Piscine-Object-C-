#ifndef TEMPWORKER_HPP
#define TEMPWORKER_HPP

#include "employee.hpp"
#include <iostream>

class TempWorker : public Employee
{
private:
    int _hoursWorked;

public:
    TempWorker(const std::string &name, int hourlyValue)
        : Employee(name, hourlyValue), _hoursWorked(0) {}

    virtual int executeWorkday()
    {
        _hoursWorked += 7;
        std::cout << "🕒 TempWorker " << empName << " worked 7 hours.\n";
        return _hoursWorked;
    }

    virtual double calculatePay()
    {
        double pay = _hoursWorked * hourlyValue;
        std::cout << "💰 TempWorker " << empName
                  << " earned " << pay << " € for this period.\n";
        _hoursWorked = 0;
        return pay;
    }

    void mobilize(int hours)
    {
        _hoursWorked += hours;
        std::cout << "🚀 TempWorker " << empName
                  << " mobilized for " << hours << " extra hours.\n";
    }

    virtual void displayInfo()  const
    {
        std::cout << "----------------------------------\n"
                  << "🧑‍🔧 Temp Worker Information\n"
                  << "----------------------------------\n"
                  << "Name          : " << empName << "\n"
                  << "Hourly Value  : " << hourlyValue << " €\n"
                  << "Hours Worked  : " << _hoursWorked << "\n"
                  << "----------------------------------\n";
    }
};

#endif
