#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include "account.hpp"

class Account;

class Bank
{
private:
    int _liquidity;
    std::vector<Account *> _clientAccounts;
    static const double COMMISSION_RATE;
    int _nextId;

public:
    Bank(int liquidity = 0)
        : _liquidity(liquidity), _nextId(1)
    {
        if (liquidity < 0)
            throw std::invalid_argument("Bank liquidity cannot be negative");
    }

    ~Bank()
    {
        std::vector<Account *>::iterator it = _clientAccounts.begin();
        while (it != _clientAccounts.end())
        {
            delete *it;
            ++it;
        }
    }

    int getLiquidity() const
    {
        return _liquidity;
    }

    Account *createAccount(int value)
    {
        if (value < 0)
            throw std::invalid_argument("value not accepeted for create an account");
        int commission = static_cast<int>(value * COMMISSION_RATE);
        int initialAmount = value - commission;
        std::cout << "initial amount ==> " << initialAmount << std::endl;
        Account *client = new Account(_nextId++, initialAmount);
        _liquidity += initialAmount;
        _clientAccounts.push_back(client);
        return client;
    }

    void deposit(Account &client, int amount)
    {
        if (amount <= 0)
            throw std::invalid_argument("Deposit amount must be positive");
        int commission = static_cast<int>(amount * COMMISSION_RATE);
        client._initialAmount += (amount - commission);
        std::cout         << "┌───────────────────────────────────────┐\n"
                          << "│     Account Deletion Log              │\n"
                          << "├───────────────────────────────────────┤\n"
                          << "│ Account ID : " << client._initialAmount << "\n"
                          << "│ Status     : ✅ Successfully deposit  │\n"
                          << "└───────────────────────────────────────┘\n";
        _liquidity += amount;
    }

    void deleteAccountById(int id)
    {
        std::vector<Account *>::iterator it = _clientAccounts.begin();
        while (it != _clientAccounts.end())
        {
            if ((*it)->getId() == id)
            {
                _liquidity -= (*it)->getAmount();
                delete *it;
                it = _clientAccounts.erase(it);
                std::cout << "┌───────────────────────────────────────┐\n"
                          << "│     Account Deletion Log              │\n"
                          << "├───────────────────────────────────────┤\n"
                          << "│ Account ID : " << id << "\n"
                          << "│ Status     : ✅ Successfully deleted  │\n"
                          << "└───────────────────────────────────────┘\n";
                return;
            }
            else
                ++it;
        }

        std::cout << "\n┌──────────────────────────────┐\n"
                  << "│     Account Deletion Log     │\n"
                  << "├──────────────────────────────┤\n"
                  << "│ Account ID : " << id << "\n"
                  << "│ Status     : ❌ Not found\n"
                  << "└──────────────────────────────┘\n";
    }

    void withdraw(Account &client, int amount)
    {
        if (amount <= 0)
            throw std::invalid_argument("Withdraw amount must be positive");
        if (amount > client._initialAmount)
            throw std::runtime_error("Insufficient funds");
        client._initialAmount -= amount;
        _liquidity -= amount;
    }

    void giveLoan(Account &client, int amount)
    {
        if (amount <= 0)
            throw std::invalid_argument("Loan amount must be positive");
        if (_liquidity < amount)
            throw std::runtime_error("Bank has insufficient liquidity");

        client._initialAmount += amount;
        _liquidity -= amount;
    }

    friend std::ostream &operator<<(std::ostream &os, const Bank &bank)
    {
        os << "┌──────────────────────────────────────┐\n"
           << "│           Bank Report                │\n"
           << "├──────────────────────────────────────┤\n"
           << "│ Total Liquidity : $" << bank._liquidity << "\n"
           << "│ Number of Clients: " << bank._clientAccounts.size() << "\n"
           << "├──────────────────────────────────────┤\n";

        if (bank._clientAccounts.empty())
            os << "│ No accounts available.               │\n";
        else
        {
            for (std::vector<Account *>::const_iterator it = bank._clientAccounts.begin();
                 it != bank._clientAccounts.end(); ++it)
            {
                os << "│ " << "Client " << (*it)->getId()
                   << " → Balance: $" << (*it)->getAmount() << "\n";
            }
        }

        os << "└──────────────────────────────────────┘";
        return os;
    }
};

const double Bank::COMMISSION_RATE = 0.05;

#endif