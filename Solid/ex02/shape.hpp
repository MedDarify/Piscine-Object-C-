#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>

class Shape {
public:
    virtual ~Shape() {
    }

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

#endif