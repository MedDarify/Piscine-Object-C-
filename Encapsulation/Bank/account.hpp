#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <stdexcept>

class Bank;

class Account
{
private:
    int _id;
    int _initialAmount;

public:
    Account(int id, int amount)
        : _id(id), _initialAmount(amount)
    {
        if (amount < 0)
            throw std::invalid_argument("Invalid amount value");
    }

    int getId() const { return _id; }
    int getAmount() const { return _initialAmount; }

    friend class Bank;

    friend std::ostream &operator<<(std::ostream &os, const Account &account)
    {
        os << "┌──────────────────────────────────────┐\n"
           << "│        Client  Information           │\n"
           << "├──────────────────────────────────────┤\n"
           << "│ client id : " << account._id << "\n"
           << "│ client Amount: " << account._initialAmount << "\n"
           << "├──────────────────────────────────────┤\n";
        return os;
    }
};

#endif
