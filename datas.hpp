#ifndef DATAS_HPP
#define DATAS_HPP

#include <string>
#include <vector>
#include <iostream>

class Student;
class Professor;
class Person;
class Course;
class Room;
class Form;
class Classroom;


class Course
{
private:
	std::string _name;
	Professor* _responsable;
	std::vector<Student*> _students;
	int _numberOfClassToGraduate;
	int _maximumNumberOfStudent;

public:
	Course(std::string p_name) : _name(p_name), _responsable(0) {} 
	void assign(Professor* p_professor) { _responsable = p_professor; }
	void subscribe(Student* p_student) { _students.push_back(p_student); }
    std::string getName() const { return _name; }
};

class Room
{
private:
	long long ID;
	std::vector<Person*> _occupants;
    static long long _nextId; 

public:
	Room() { ID = _nextId++; }
    virtual ~Room() {}
	bool canEnter(Person*) { return true; }
	void enter(Person* p) { _occupants.push_back(p); }
	void exit(Person* p) {  }
	void printOccupant() { }
    long long getId() const { return ID; }
};

long long Room::_nextId = 0;


class Classroom : public Room {};
class SecretarialOffice: public Room {};
class HeadmasterOffice : public Room {};
class StaffRestRoom : public Room {};
class Courtyard : public Room {};

class Person
{
private:
	std::string _name;
	Room* _currentRoom;
public:
	Person(std::string p_name) : _name(p_name), _currentRoom(0) {}
    virtual ~Person() {}
	Room* room() { return (_currentRoom); }
    std::string getName() const { return _name; }
};

class Staff : public Person
{
public:
    Staff(std::string p_name) : Person(p_name) {}
	void sign(Form* p_form) {  }
};

enum FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

class Form
{
private:
	FormType _formType;
public:
	Form(FormType p_formType) : _formType(p_formType) {}
    virtual ~Form() {} 
	virtual void execute() = 0;
};

class CourseFinishedForm : public Form
{
public:
    CourseFinishedForm() : Form(CourseFinished) {}
	void execute() { std::cout << "Executing CourseFinishedForm" << std::endl; }
};

class NeedMoreClassRoomForm : public Form
{
public:
    NeedMoreClassRoomForm() : Form(NeedMoreClassRoom) {}
	void execute() { std::cout << "Executing NeedMoreClassRoomForm" << std::endl; }
};

class NeedCourseCreationForm : public Form
{
public:
    NeedCourseCreationForm() : Form(NeedCourseCreation) {}
	void execute() { std::cout << "Executing NeedCourseCreationForm" << std::endl; }
};

class SubscriptionToCourseForm : public Form
{
public:
    SubscriptionToCourseForm() : Form(SubscriptionToCourse) {}
	void execute() { std::cout << "Executing SubscriptionToCourseForm" << std::endl; }
};

class Student : public Person
{
private:
	std::vector<Course*> _subscribedCourse;
public:
    Student(std::string p_name) : Person(p_name) {}
	void attendClass(Classroom* p_classroom) {}
	void exitClass() {}
	void graduate(Course* p_course) {}
};

class Headmaster : public Staff
{
private:
	std::vector<Form*> _formToValidate;
public:
    Headmaster(std::string p_name) : Staff(p_name) {}
	void receiveForm(Form* p_form) { _formToValidate.push_back(p_form); }
};

class Secretary : public Staff
{
public:
    Secretary(std::string p_name) : Staff(p_name) {}
	Form* createForm(FormType p_formType) {  return 0; }
	void archiveForm() {}
};

class Professor : public Staff
{
private:
	Course* _currentCourse;
public:
    Professor(std::string p_name) : Staff(p_name) {}
	void assignCourse(Course* p_course) { _currentCourse = p_course; }
	void doClass() {}
	void closeCourse() {}
};



#endif 