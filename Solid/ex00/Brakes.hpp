#pragma once
#include <iostream>

class BraKes
{
private:
    int _force;

public:
    BraKes() : _force(0) {}
    ~BraKes() {}

    void apply_force_on_brakes(int force)
    {
        std::cout << "\n┌────────────────────────────────────────┐\n";
        std::cout << "│         🛞 BRAKE SYSTEM CONTROL         │\n";
        std::cout << "└────────────────────────────────────────┘\n";

        if (force < 110 || force > 700)
        {
            std::cout << "⚠️  Error: Brake force out of safe range! ("
                      << force << ")\n";
            std::cout << "💡 Acceptable range: 110 – 700\n";
            std::cout << "───────────────────────────────────────────────\n";
            return;
        }

        _force = force;
        std::cout << "✅ Applied brake force successfully!\n";
        std::cout << "🧭 Current Brake Force: " << _force << " N\n";
        std::cout << "───────────────────────────────────────────────\n";
    }

    void apply_emergency_brakes()
    {
        std::cout << "\n┌────────────────────────────────────────┐\n";
        std::cout << "│        🚨 EMERGENCY BRAKE SYSTEM        │\n";
        std::cout << "└────────────────────────────────────────┘\n";
        _force = 0;
        std::cout << "⚡ Emergency brakes activated!\n";
        std::cout << "🛑 All wheels locked. Force reset to " << _force << " N\n";
        std::cout << "───────────────────────────────────────────────\n";
    }
};
