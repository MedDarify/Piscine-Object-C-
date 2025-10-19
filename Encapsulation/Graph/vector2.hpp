#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2
{
private:
    float _x;
    float _y;

public:
    Vector2(float x = 0, float y = 0) : _x(x), _y(y) {}
    float getX() const { return _x; }
    float getY() const { return _y; }

    void set(float x, float y)
    {
        _x = x;
        _y = y;
    }
};

#endif
