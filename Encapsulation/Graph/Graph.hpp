#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>
#include "vector2.hpp"

class Graph
{
private:
    Vector2 _size;
    std::vector<Vector2> _points;

public:
    Graph(float width, float height);
    void addPoint(const Vector2& p);
    void display() const;
};

#endif
