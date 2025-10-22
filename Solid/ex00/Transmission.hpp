#pragma once
#include <iostream>

class Transmission
{
private:
    int _level;

public:
    Transmission() : _level(0)
    {
        std::cout << "\n┌────────────────────────────────────────────┐\n";
        std::cout << "│        ⚙️  TRANSMISSION SYSTEM ONLINE       │\n";
        std::cout << "└────────────────────────────────────────────┘\n";
        std::cout << "✅ Transmission constructor called.\n";
    }

    ~Transmission()
    {
        std::cout << "\n🧹 Transmission system shutting down...\n";
        std::cout << "Transmission destructor called.\n";
    }

    void shift_gears_up()
    {
        std::cout << "\n┌────────────────────────────────────────────┐\n";
        std::cout << "│            🔼 GEAR SHIFT UP                │\n";
        std::cout << "└────────────────────────────────────────────┘\n";
        if (_level < 5)
        {
            _level++;
            std::cout << "✅ Gear increased successfully.\n";
            std::cout << "⚙️  Current gear: " << _level << "\n";
        }
        else
        {
            std::cout << "⚠️  Already in highest gear!\n";
        }
        std::cout << "───────────────────────────────────────────────\n";
    }

    void shift_gears_down()
    {
        std::cout << "\n┌────────────────────────────────────────────┐\n";
        std::cout << "│            🔽 GEAR SHIFT DOWN              │\n";
        std::cout << "└────────────────────────────────────────────┘\n";
        if (_level > 0)
        {
            _level--;
            std::cout << "✅ Gear decreased successfully.\n";
            std::cout << "⚙️  Current gear: " << _level << "\n";
        }
        else
        {
            std::cout << "⚠️  Already in lowest gear!\n";
        }
        std::cout << "───────────────────────────────────────────────\n";
    }

    void reverse()
    {
        std::cout << "\n┌────────────────────────────────────────────┐\n";
        std::cout << "│               ↩️ REVERSE GEAR              │\n";
        std::cout << "└────────────────────────────────────────────┘\n";
        _level = -1;
        std::cout << "✅ Transmission shifted into reverse.\n";
        std::cout << "⚙️  Current gear: R\n";
        std::cout << "───────────────────────────────────────────────\n";
    }
};
