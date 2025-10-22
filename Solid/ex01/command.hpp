#pragma once
#include <iostream>
#include <vector>
#include <iomanip> // for formatting prices

struct Articles
{
    int id;
    double price;
    int quantity;
    std::string name;
};

class Command
{
protected:
    int _id;
    std::string _Date;
    std::string _Client;
    std::vector<Articles *> _Articles;

public:
    Command(int id, const std::string &Date, const std::string &Client)
        : _id(id), _Date(Date), _Client(Client)
    {
        std::cout << "\n┌────────────────────────────────────────────┐\n";
        std::cout << "│            🧾 NEW COMMAND CREATED          │\n";
        std::cout << "└────────────────────────────────────────────┘\n";
        std::cout << "📦 Command ID: " << _id << "\n";
        std::cout << "👤 Client: " << _Client << "\n";
        std::cout << "🗓️  Date: " << _Date << "\n";
        std::cout << "───────────────────────────────────────────────\n";
    }

    virtual ~Command()
    {
        std::cout << "\n🧹 Cleaning up command resources...\n";
        for (size_t i = 0; i < _Articles.size(); ++i)
            delete _Articles[i];
        std::cout << "✅ Command [" << _id << "] for client '" << _Client << "' destroyed.\n";
        std::cout << "───────────────────────────────────────────────\n";
    }

    void addArticleToCommand(const std::string &name, double price, int quantity)
    {
        Articles *newArticle = new Articles();
        newArticle->id = _Articles.size() + 1;
        newArticle->name = name;
        newArticle->price = price;
        newArticle->quantity = quantity;
        _Articles.push_back(newArticle);

        std::cout << "\n🧩 Added new article to Command #" << _id << ":\n";
        std::cout << "   🏷️  ID: " << newArticle->id << "\n";
        std::cout << "   📦 Name: " << name << "\n";
        std::cout << "   💰 Price: " << std::fixed << std::setprecision(2) << price << " USD\n";
        std::cout << "   🔢 Quantity: " << quantity << "\n";
        std::cout << "───────────────────────────────────────────────\n";
    }

    virtual double get_total_price()
    {
        double total = 0.0;
        for (std::vector<Articles *>::iterator it = _Articles.begin(); it != _Articles.end(); ++it)
            total += ((*it)->price * (*it)->quantity);

        std::cout << "\n💵 Calculating total price for Command #" << _id << "...\n";
        std::cout << "📦 Number of items: " << _Articles.size() << "\n";
        std::cout << "💰 Total amount: " << std::fixed << std::setprecision(2) << total << " USD\n";
        std::cout << "───────────────────────────────────────────────\n";
        return total;
    }

    void displayCommandDetails()
    {
        std::cout << "\n┌────────────────────────────────────────────┐\n";
        std::cout << "│           📋 COMMAND INFORMATION           │\n";
        std::cout << "└────────────────────────────────────────────┘\n";
        std::cout << "🧾 Command ID: " << _id << "\n";
        std::cout << "👤 Client: " << _Client << "\n";
        std::cout << "🗓️  Date: " << _Date << "\n";
        std::cout << "\n🛒 Articles:\n";
        std::cout << "----------------------------------------------\n";
        for (size_t i = 0; i < _Articles.size(); ++i)
        {
            std::cout << "  #" << _Articles[i]->id
                      << " | " << _Articles[i]->name
                      << " | Price: " << std::fixed << std::setprecision(2) << _Articles[i]->price << " USD"
                      << " | Qty: " << _Articles[i]->quantity << "\n";
        }
        std::cout << "----------------------------------------------\n";
        std::cout << "💰 Total: " << std::fixed << std::setprecision(2) << get_total_price() << " USD\n";
        std::cout << "───────────────────────────────────────────────\n";
    }
};
