#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <vector>
#include "Form.hpp" 
class Room;
class Course;
class Classroom;

class Person
{
private:
	std::string _name;
	Room* _currentRoom;
public:
	Person(std::string p_name); 
	virtual ~Person();

	Room* room();
    std::string getName() const;
    void setRoom(Room* p_room);
};


#endif