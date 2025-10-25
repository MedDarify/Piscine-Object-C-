#include "Form.hpp"
#include <iostream>

Form::Form(FormType p_formType) : _formType(p_formType), _isSigned(false)
{
}

Form::~Form()
{
}

CourseFinishedForm::CourseFinishedForm() : Form(CourseFinished)
{
}

void CourseFinishedForm::execute()
{
    if (this->isSigned())
        std::cout << "Executing: Course Finished." << std::endl;
    else
        std::cout << "Cannot execute: Form not signed." << std::endl;
}

NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(NeedMoreClassRoom)
{
}

void NeedMoreClassRoomForm::execute()
{
    if (this->isSigned())
        std::cout << "Executing: Need More Class Room." << std::endl;
    else
        std::cout << "Cannot execute: Form not signed." << std::endl;
}

NeedCourseCreationForm::NeedCourseCreationForm() : Form(NeedCourseCreation)
{
}

void NeedCourseCreationForm::execute()
{
    if (this->isSigned())
        std::cout << "Executing: Need Course Creation." << std::endl;
    else
        std::cout << "Cannot execute: Form not signed." << std::endl;
}

SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(SubscriptionToCourse)
{
}

void SubscriptionToCourseForm::execute()
{
    if (this->isSigned())
        std::cout << "Executing: Subscription To Course." << std::endl;
    else
        std::cout << "Cannot execute: Form not signed." << std::endl;
}