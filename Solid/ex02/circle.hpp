#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

#ifndef PI
#define PI 3.14159265358979323846
#endif

class Circle : public Shape {
private:
    double _radius;

public:
    Circle(double radius) : _radius(radius) {
        std::cout << "Circle created." << std::endl;
    }
    
    virtual ~Circle() {
        std::cout << "Circle destroyed." << std::endl;
    }

    virtual double area() const {
        return PI * _radius * _radius;
    }

    virtual double perimeter() const {
        return 2 * PI * _radius;
    }
};

#endif