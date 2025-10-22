#ifndef THUESDAYDISCOUNT_HPP
#define THUESDAYDISCOUNT_HPP

#include "command.hpp"
#include <iostream>
#include <iomanip>

class ThuesdayDiscountCommand : public Command
{
public:
    ThuesdayDiscountCommand(int id, const std::string &date, const std::string &client)
        : Command(id, date, client)
    {
        std::cout << "\n┌────────────────────────────────────────────┐\n";
        std::cout << "│         📅 TUESDAY DISCOUNT COMMAND        │\n";
        std::cout << "└────────────────────────────────────────────┘\n";
        std::cout << "✅ Special discount command created for '" << client << "'.\n";
        std::cout << "📆 Order date: " << _Date << "\n";
        std::cout << "───────────────────────────────────────────────\n";
    }

    virtual ~ThuesdayDiscountCommand()
    {
        std::cout << "\n🧹 Destroying Tuesday Discount Command for '" << _Client << "'...\n";
        std::cout << "💼 Tuesday discount resources released.\n";
        std::cout << "───────────────────────────────────────────────\n";
    }

    virtual double get_total_price()
    {
        std::cout << "\n💰 Calculating total with Tuesday discount policy...\n";
        double baseTotal = Command::get_total_price();

        std::cout << "📦 Base total before discount: "
                  << std::fixed << std::setprecision(2)
                  << baseTotal << " USD\n";

        if (_Date == "Tuesday")
        {
            double discount = baseTotal * 0.10;
            double discountedTotal = baseTotal - discount;

            std::cout << "🎉 It's Tuesday! Applying 10% discount.\n";
            std::cout << "💵 Discount amount: "
                      << std::fixed << std::setprecision(2)
                      << discount << " USD\n";
            std::cout << "✅ Total after discount: "
                      << discountedTotal << " USD\n";
            std::cout << "───────────────────────────────────────────────\n";
            return discountedTotal;
        }

        std::cout << "ℹ️  No Tuesday discount applied (order date: "
                  << _Date << ").\n";
        std::cout << "Final total: "
                  << std::fixed << std::setprecision(2)
                  << baseTotal << " USD\n";
        std::cout << "───────────────────────────────────────────────\n";
        return baseTotal;
    }
};

#endif
