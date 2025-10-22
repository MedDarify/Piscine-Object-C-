#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"
// #include <cmath>

// We implement a Right-Angled Triangle for simplicity
class Triangle : public Shape
{
private:
    double _base;
    double _height;

public:
    Triangle(double base, double height) : _base(base), _height(height)
    {
        std::cout << "Triangle created." << std::endl;
    }

    double ft_sqrt(double number) const
    {
        if (number < 0)
        {
            std::cerr << "Error: Negative input to sqrt\n";
            return -1.0; 
        }
        if (number == 0 || number == 1)
            return number;

        double guess = number / 2.0;
        double epsilon = 1e-7; 

        while (true)
        {
            double next = 0.5 * (guess + number / guess);
            if (guess - next < epsilon && guess - next > -epsilon)
                break;
            guess = next;
        }

        return guess;
    }

    virtual ~Triangle()
    {
        std::cout << "Triangle destroyed." << std::endl;
    }

    virtual double area() const
    {
        return 0.5 * _base * _height;
    }

    virtual double perimeter() const
    {
        double Hypotenuse = ft_sqrt(_base * _base + _height * _height);
        return _base + _height + Hypotenuse;
    }
};

#endif