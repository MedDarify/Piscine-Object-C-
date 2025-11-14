#ifndef ROOM_HPP
#define ROOM_HPP

#include <vector>
#include <string>

class Person;

class Room
{
private:
    long long ID;
    std::vector<Person *> _occupants;
    static long long _nextId; 

public:
    Room();
    virtual ~Room();

    bool canEnter(Person *p_person);
    void enter(Person *p_person);
    void exit(Person *p_person);

    void printOccupant();
    long long getId() const { return ID; }
};

class Classroom : public Room
{
private:
    class Course *_currentRoom;

public:
    Classroom();
    void assignCourse(class Course *p_course);
};

class SecretarialOffice : public Room
{
private:
    std::vector<class Form *> _archivedForms;

public:
    SecretarialOffice();
};

class HeadmasterOffice : public Room
{
public:
    HeadmasterOffice();
};

class StaffRestRoom : public Room
{
public:
    StaffRestRoom();
};

class Courtyard : public Room
{
public:
    Courtyard();
};

#endif