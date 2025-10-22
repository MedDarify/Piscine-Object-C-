#pragma once
#include <iostream>

class Steering
{
private:
    int _angle;

public:
    Steering() : _angle(0)
    {
        std::cout << "\n┌────────────────────────────────────────────┐\n";
        std::cout << "│         🌀 STEERING SYSTEM ONLINE          │\n";
        std::cout << "└────────────────────────────────────────────┘\n";
        std::cout << "✅ Steering constructor called.\n";
    }

    ~Steering()
    {
        std::cout << "\n🧹 Steering system shutting down...\n";
        std::cout << "Steering destructor called.\n";
    }

    void turn_wheel(int angle)
    {
        std::cout << "\n┌────────────────────────────────────────────┐\n";
        std::cout << "│             ⚙️  TURNING WHEELS             │\n";
        std::cout << "└────────────────────────────────────────────┘\n";

        if (angle < -40 || angle > 40)
        {
            std::cout << "⚠️  Error: Input steering angle (" << angle
                      << ") out of allowed range [-40°, 40°].\n";
            std::cout << "───────────────────────────────────────────────\n";
            return;
        }
        if (_angle + angle < -40 || _angle + angle > 40)
        {
            std::cout << "⚠️  Error: Resulting steering angle ("
                      << _angle + angle
                      << "°) would exceed limits.\n";
            std::cout << "───────────────────────────────────────────────\n";
            return;
        }

        _angle += angle;
        std::cout << "✅ Wheel turned successfully.\n";
        std::cout << "🧭 Current steering angle: " << _angle << "°\n";
        std::cout << "───────────────────────────────────────────────\n";
    }

    void straighten_wheels()
    {
        std::cout << "\n┌────────────────────────────────────────────┐\n";
        std::cout << "│           🔄 STRAIGHTENING WHEELS          │\n";
        std::cout << "└────────────────────────────────────────────┘\n";
        _angle = 0;
        std::cout << "✅ Steering wheel centered successfully.\n";
        std::cout << "🧭 Current steering angle: " << _angle << "°\n";
        std::cout << "───────────────────────────────────────────────\n";
    }
};
