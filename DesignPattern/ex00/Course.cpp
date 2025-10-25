#include "Course.hpp"


Course::Course(std::string p_name) 
    : _name(p_name), _responsable(0), _numberOfClassToGraduate(10), _maximumNumberOfStudent(30)
{
}

void Course::assign(Professor* p_professor)
{
    _responsable = p_professor;
}

void Course::subscribe(Student* p_student)
{
    if (_students.size() < (unsigned int)_maximumNumberOfStudent)
    {
        _students.push_back(p_student);
    }
}

std::string Course::getName() const
{
    return _name;
}