#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape {
private:
    double _width;
    double _height;

public:
    Rectangle(double width, double height) : _width(width), _height(height) {
           std::cout << "Rectangle created." << std::endl;
    }
    
    virtual ~Rectangle() {
        std::cout << "Rectangle destructor called." << std::endl;
    }

    virtual double area() const {
        return _width * _height;
    }

    virtual double perimeter() const {
        return 2 * (_width + _height);
    }
};

#endif