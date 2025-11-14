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

class Staff : public Person
{
public:
    Staff(std::string p_name);
	void sign(Form* p_form);
};

class Student : public Person
{
private:
	std::vector<Course*> _subscribedCourse;

public:
    Student(std::string p_name);

	void attendClass(Classroom* p_classroom);
	void exitClass();
	void graduate(Course* p_course);
};

class Headmaster : public Staff
{
private:
	std::vector<Form*> _formToValidate;
	
public:
    Headmaster(std::string p_name);
	void receiveForm(Form* p_form);
    void validateForms();
};

class Secretary : public Staff
{
private:

public:
    Secretary(std::string p_name);

	Form* createForm(FormType p_formType);
	void archiveForm();
};

class Professor : public Staff
{
private:
	Course* _currentCourse;

public:
    Professor(std::string p_name);

	void assignCourse(Course* p_course);
	void doClass();
	void closeCourse();
};

#endif