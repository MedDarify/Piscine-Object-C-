#include    "Secretary.hpp"
#include    "CourseFinishedForm.hpp"
#include    <iostream>
#include    "NeedCourseCreationForm.hpp"
#include    "NeedMoreClassRoomForm.hpp"
#include    "SubscriptionToCourseForm.hpp"


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