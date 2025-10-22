#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

#include <iostream>
#include <vector>

void printShapeDetails(Shape *shape)
{
    if (!shape)
        return;

    std::cout << "--------------------" << std::endl;
    std::cout << "Processing a shape..." << std::endl;
    std::cout << "Area: " << shape->area() << std::endl;
    std::cout << "Perimeter: " << shape->perimeter() << std::endl;
    std::cout << "--------------------" << std::endl;
}

int main()
{
    std::vector<Shape *> shapes;

    shapes.push_back(new Rectangle(10.0, 5.0));
    shapes.push_back(new Circle(7.0));
    shapes.push_back(new Triangle(3.0, 4.0));

    std::cout << "--- Iterating and printing shapes polymorphically ---" << std::endl;

    for (size_t i = 0; i < shapes.size(); ++i)
    {
        printShapeDetails(shapes[i]);
    }

    std::cout << "\n--- Cleaning up ---" << std::endl;
    for (size_t i = 0; i < shapes.size(); ++i)
    {
        delete shapes[i];
    }
    shapes.clear();

    return 0;
}