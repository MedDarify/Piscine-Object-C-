#include "Person.hpp"
#include "Room.hpp"
#include "Course.hpp"
#include <iostream>

Person::Person(std::string p_name) : _name(p_name), _currentRoom(0)
{
}

Person::~Person()
{
}

Room *Person::room()
{
    return (_currentRoom);
}

std::string Person::getName() const
{
    return _name;
}

void Person::setRoom(Room *p_room)
{
    _currentRoom = p_room;
}

