#pragma once
#include <iostream>
#include "Enginne.hpp"
#include "Transmission.hpp"
#include "Steering.hpp"
#include "Brakes.hpp"

class Car
{
private:
    Enginne _Enginne;
    Transmission _Transmission;
    Steering _Steering;
    BraKes _Brakes;

public:
    Car()
    {
        std::cout << "\n┌────────────────────────────────────────────┐\n";
        std::cout << "│               🚗 CAR SYSTEM                │\n";
        std::cout << "└────────────────────────────────────────────┘\n";
        std::cout << "✅ Car constructed successfully.\n";
    }

    ~Car()
    {
        std::cout << "\n🧹 Car resources cleaned up.\n";
        std::cout << "Car destructor called.\n";
    }

    void start()
    {
        std::cout << "\n🚦 Starting car...\n";
        _Enginne.start();
    }

    void accelerate(int speed)
    {
        std::cout << "\n🏎️  Accelerating car...\n";
        _Enginne.accelerate(speed);
    }

    void stop()
    {
        std::cout << "\n🛑 Stopping car...\n";
        _Enginne.stop();
    }

    void shift_gears_up()
    {
        std::cout << "\n🔼 Shifting gear up...\n";
        _Transmission.shift_gears_up();
    }

    void shift_gears_down()
    {
        std::cout << "\n🔽 Shifting gear down...\n";
        _Transmission.shift_gears_down();
    }

    void reverse()
    {
        std::cout << "\n↩️  Engaging reverse gear...\n";
        _Transmission.reverse();
    }

    void turn_wheel(int angle)
    {
        std::cout << "\n🌀 Turning wheel...\n";
        _Steering.turn_wheel(angle);
    }

    void straighten_wheels()
    {
        std::cout << "\n⚙️  Straightening wheels...\n";
        _Steering.straighten_wheels();
    }

    void apply_brake_force(int force)
    {
        std::cout << "\n⚡ Applying brake force...\n";
        _Brakes.apply_force_on_brakes(force);
    }

    void apply_emergency_brakes()
    {
        std::cout << "\n🚨 Activating emergency brakes...\n";
        _Brakes.apply_emergency_brakes();
    }
};
