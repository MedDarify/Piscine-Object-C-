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

Staff::Staff(std::string p_name) : Person(p_name)
{
}

void Staff::sign(Form *p_form)
{
    if (p_form)
    {
        std::cout << getName() << " is signing a form." << std::endl;
        p_form->sign();
    }
}

Student::Student(std::string p_name) : Person(p_name)
{
}

void Student::attendClass(Classroom *p_classroom)
{
    (void)p_classroom;
}

void Student::exitClass()
{
}

void Student::graduate(Course *p_course)
{
    (void)p_course;
}

Headmaster::Headmaster(std::string p_name) : Staff(p_name)
{
}

void Headmaster::receiveForm(Form *p_form)
{
    if (p_form)
        _formToValidate.push_back(p_form);
}

void Headmaster::validateForms()
{
    std::cout << "Headmaster " << getName() << " is validating forms." << std::endl;
    for (std::size_t i = 0; i < _formToValidate.size(); ++i)
    {
        sign(_formToValidate[i]);
        _formToValidate[i]->execute();
    }
    _formToValidate.clear();
}

Secretary::Secretary(std::string p_name) : Staff(p_name)
{
}

Form *Secretary::createForm(FormType p_formType)
{
    Form *newForm = 0;
    if (p_formType == CourseFinished)
        newForm = new CourseFinishedForm();
    else if (p_formType == NeedMoreClassRoom)
        newForm = new NeedMoreClassRoomForm();
    else if (p_formType == NeedCourseCreation)
        newForm = new NeedCourseCreationForm();
    else if (p_formType == SubscriptionToCourse)
        newForm = new SubscriptionToCourseForm();

    std::cout << "Secretary " << getName() << " created a form." << std::endl;
    return newForm;
}


void Secretary::archiveForm()
{
}

Professor::Professor(std::string p_name) : Staff(p_name), _currentCourse(0)
{
}

void Professor::assignCourse(Course *p_course)
{
    _currentCourse = p_course;
}

void Professor::doClass()
{
}

void Professor::closeCourse()
{
}