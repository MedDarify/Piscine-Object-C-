#include    "NeedCourseCreationForm.hpp"

#include    <iostream>

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