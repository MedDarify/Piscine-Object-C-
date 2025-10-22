#pragma once
#include <iostream>

class Enginne
{
private:
    int _Speed;
    bool _isRunning;

public:
    Enginne() : _Speed(0), _isRunning(false)
    {
        std::cout << "\n┌──────────────────────────────────────────────┐\n";
        std::cout << "│        🚗 ENGINE SYSTEM INITIALIZED          │\n";
        std::cout << "└──────────────────────────────────────────────┘\n";
        std::cout << "🛠️  Engine constructor called.\n";
    }

    ~Enginne()
    {
        std::cout << "\n🧹 Engine resources cleaned up.\n";
    }

    void start()
    {
        std::cout << "\n┌──────────────────────────────────────────────┐\n";
        std::cout << "│              🔑 ENGINE START                │\n";
        std::cout << "└──────────────────────────────────────────────┘\n";
        if (!_isRunning)
        {
            _isRunning = true;
            std::cout << "✅ Engine started successfully.\n";
            std::cout << "💨 Ready to accelerate.\n";
        }
        else
        {
            std::cout << "⚠️  Engine is already running.\n";
        }
        std::cout << "───────────────────────────────────────────────\n";
    }

    void stop()
    {
        std::cout << "\n┌──────────────────────────────────────────────┐\n";
        std::cout << "│              🛑 ENGINE STOP                 │\n";
        std::cout << "└──────────────────────────────────────────────┘\n";
        if (_isRunning)
        {
            _isRunning = false;
            _Speed = 0;
            std::cout << "🧭 Engine stopped safely.\n";
            std::cout << "⚙️  Speed reset to " << _Speed << " km/h.\n";
        }
        else
        {
            std::cout << "⚠️  Engine is already stopped.\n";
        }
        std::cout << "───────────────────────────────────────────────\n";
    }

    void accelerate(int Speed)
    {
        std::cout << "\n┌──────────────────────────────────────────────┐\n";
        std::cout << "│              ⚡ ACCELERATION                 │\n";
        std::cout << "└──────────────────────────────────────────────┘\n";
        if (_isRunning)
        {
            _Speed += Speed;
            std::cout << "🚀 Accelerating...\n";
            std::cout << "🏎️  Current speed: " << _Speed << " km/h\n";
        }
        else
        {
            std::cout << "❌ Cannot accelerate. Engine is not running.\n";
        }
        std::cout << "───────────────────────────────────────────────\n";
    }
};
