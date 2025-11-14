#include    "SubscriptionToCourseForm.hpp"
#include    <iostream>


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