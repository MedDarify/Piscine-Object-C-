#pragma once
#include "command.hpp"
#include <iomanip>

class PackageReductionDiscountCommand : public Command
{
public:
    PackageReductionDiscountCommand(int id, const std::string &date, const std::string &client)
        : Command(id, date, client)
    {
        std::cout << "\n┌────────────────────────────────────────────┐\n";
        std::cout << "│   🎁 PACKAGE REDUCTION DISCOUNT COMMAND    │\n";
        std::cout << "└────────────────────────────────────────────┘\n";
        std::cout << "✅ Specialized command created for client '" << client << "'.\n";
        std::cout << "───────────────────────────────────────────────\n";
    }

    virtual ~PackageReductionDiscountCommand()
    {
        std::cout << "\n🧹 Destroying PackageReductionDiscountCommand for client '" << _Client << "'...\n";
        std::cout << "💼 Discount command resources released.\n";
        std::cout << "───────────────────────────────────────────────\n";
    }

    virtual double get_total_price()
    {
        std::cout << "\n💰 Calculating total with package discount policy...\n";
        double baseTotal = Command::get_total_price();

        std::cout << "📦 Base total before discount: "
                  << std::fixed << std::setprecision(2) << baseTotal << " USD\n";

        if (baseTotal > 150.0)
        {
            double discount = baseTotal * 0.05;
            double discountedTotal = baseTotal - discount;
            std::cout << "🎉 Discount triggered! (5% OFF)\n";
            std::cout << "💵 Discount amount: " << std::fixed << std::setprecision(2)
                      << discount << " USD\n";
            std::cout << "✅ Total after discount: " << discountedTotal << " USD\n";
            std::cout << "───────────────────────────────────────────────\n";
            return discountedTotal;
        }

        std::cout << "ℹ️  Total below discount threshold (150 USD). No discount applied.\n";
        std::cout << "Final total: " << baseTotal << " USD\n";
        std::cout << "───────────────────────────────────────────────\n";
        return baseTotal;
    }
};
