#include "Graph.hpp"

Graph::Graph(float width, float height)
    : _size(width, height)
{
}

void Graph::addPoint(const Vector2& p)
{
    _points.push_back(p);
}

void Graph::display() const
{
    for (int y = (int)_size.getY(); y >= 0; --y)
    {
        std::cout << ">& " << y << " ";
        for (int x = 0; x <= (int)_size.getX(); ++x)
        {
            bool found = false;
            for (std::vector<Vector2>::const_iterator it = _points.begin();
                 it != _points.end(); ++it)
            {
                if ((int)it->getX() == x && (int)it->getY() == y)
                {
                    found = true;
                    break;
                }
            }
            std::cout << (found ? "X " : ". ");
        }
        std::cout << std::endl;
    }

    std::cout << ">&   ";
    for (int x = 0; x <= (int)_size.getX(); ++x)
        std::cout << x << " ";
    std::cout << std::endl;
}
