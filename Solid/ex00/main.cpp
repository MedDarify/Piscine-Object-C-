#include "car.hpp"
#include <iostream>

int main()
{
    std::cout << "\n==============================================\n";
    std::cout << "🚗 INITIALIZING CAR SIMULATION SYSTEM\n";
    std::cout << "==============================================\n";

    Car _Car;

    std::cout << "\n----------------------------------------------\n";
    std::cout << "▶️  Starting engine sequence...\n";
    std::cout << "----------------------------------------------\n";
    _Car.start();

    std::cout << "\n----------------------------------------------\n";
    std::cout << "⚡ Accelerating to 120 km/h...\n";
    std::cout << "----------------------------------------------\n";
    _Car.accelerate(120);

    std::cout << "\n----------------------------------------------\n";
    std::cout << "🛑 Stopping the car...\n";
    std::cout << "----------------------------------------------\n";
    _Car.stop();

    std::cout << "\n----------------------------------------------\n";
    std::cout << "⚙️  Testing acceleration and gear system...\n";
    std::cout << "----------------------------------------------\n";
    _Car.accelerate(25);
    _Car.shift_gears_up();
    _Car.shift_gears_up();
    _Car.shift_gears_down();
    _Car.reverse();

    std::cout << "\n----------------------------------------------\n";
    std::cout << "🌀 Steering and braking simulation...\n";
    std::cout << "----------------------------------------------\n";
    _Car.turn_wheel(30);
    _Car.turn_wheel(15);
    _Car.straighten_wheels();

    std::cout << "\n----------------------------------------------\n";
    std::cout << "🧱 Applying brakes...\n";
    std::cout << "----------------------------------------------\n";
    _Car.apply_brake_force(500);
    _Car.apply_emergency_brakes();

    std::cout << "\n----------------------------------------------\n";
    std::cout << "⛔ Final stop...\n";
    std::cout << "----------------------------------------------\n";
    _Car.stop();

    std::cout << "\n==============================================\n";
    std::cout << "✅ SIMULATION COMPLETE — THANK YOU FOR DRIVING!\n";
    std::cout << "==============================================\n";

    return 0;
}
