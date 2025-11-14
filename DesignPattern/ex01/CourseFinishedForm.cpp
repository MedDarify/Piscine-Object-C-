#include    "CourseFinishedForm.hpp"
#include    <iostream>

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