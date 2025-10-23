#ifndef CONTRACTEMPLOYEE_HPP
#define CONTRACTEMPLOYEE_HPP

#include "employee.hpp"

class ContractEmployee : public Employee
{
protected:
    static const int MONTHLY_HOURS = 140;
    int _hoursAbsent;

public:
    ContractEmployee(std::string const &name, int hourlyValue)
        : Employee(name, hourlyValue), _hoursAbsent(0) {}

    virtual int executeWorkday() 
    {
        std::cout << "ContractEmployee " << empName << " worked." << std::endl;
        return 0;
    }

    virtual double calculatePay()
    {
        int hoursToPay = MONTHLY_HOURS - _hoursAbsent;
        if (hoursToPay < 0)
            hoursToPay = 0;

        double pay = hoursToPay * hourlyValue;
        _hoursAbsent = 0;
        return pay;
    }
    
    void logAbsence(int hours)
    {
        std::cout << "ContractEmployee " << empName << " logged " << hours << " absence hours." << std::endl;
        this->_hoursAbsent += hours;
    }
};

class Apprentice : public Employee {
protected:
    static const int MONTHLY_HOURS = 140;
    int _hoursAbsent;
    int _schoolHours;

public:
    Apprentice(std::string const& name, int hourlyValue)
        : Employee(name, hourlyValue), _hoursAbsent(0), _schoolHours(0) {}

    virtual int executeWorkday()  
    {
        std::cout << "Apprentice " << empName << " worked." << std::endl;
        return 0;
    }

    virtual double calculatePay() {
        int workHours = MONTHLY_HOURS - _hoursAbsent - _schoolHours;
        if (workHours < 0) workHours = 0;

        double workPay = workHours * hourlyValue;
        double schoolPay = _schoolHours * (hourlyValue * 0.5);

        _hoursAbsent = 0;
        _schoolHours = 0;
        return workPay + schoolPay;
    }

    void logAbsence(int hours) {
        std::cout << "Apprentice " << empName << " logged " << hours << " absence hours." << std::endl;
        this->_hoursAbsent += hours;
    }
    
    void logSchoolHours(int hours) {
        std::cout << "Apprentice " << empName << " logged " << hours << " school hours." << std::endl;
        this->_schoolHours += hours;
    }
};

#endif