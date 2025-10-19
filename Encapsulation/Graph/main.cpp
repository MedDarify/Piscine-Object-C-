#include "Graph.hpp"

int main()
{
    Graph g(7, 4);
    g.addPoint(Vector2(0, 0));
    g.addPoint(Vector2(2, 2));
    g.addPoint(Vector2(4, 2));
    g.addPoint(Vector2(2, 4));
    g.display();
    return 0;
}
