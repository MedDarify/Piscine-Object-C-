#include "Room.hpp"
#include "Person.hpp"
#include "Course.hpp"
#include <iostream>
#include <algorithm>
long long Room::_nextId = 0;

Room::Room()
{
    ID = _nextId++;
}

Room::~Room()
{
}

bool Room::canEnter(Person *p_person)
{
    (void)p_person;
    return true;
}

void Room::enter(Person *p_person)
{
    _occupants.push_back(p_person);
}

void Room::exit(Person *p_person)
{
    std::vector<Person *>::iterator it = std::find(_occupants.begin(), _occupants.end(), p_person);
    if (it != _occupants.end())
    {
        _occupants.erase(it);
    }
}

void Room::printOccupant()
{
    std::cout << "Room " << ID << " occupants:" << std::endl;
    for (std::size_t i = 0; i < _occupants.size(); ++i)
    {
        std::cout << " - " << _occupants[i]->getName() << std::endl;
    }
}

Classroom::Classroom() : Room(), _currentRoom(0)
{
}

void Classroom::assignCourse(Course *p_course)
{
    _currentRoom = p_course;
}

SecretarialOffice::SecretarialOffice() : Room()
{
}

HeadmasterOffice::HeadmasterOffice() : Room()
{
}

StaffRestRoom::StaffRestRoom() : Room()
{
}

Courtyard::Courtyard() : Room()
{
}