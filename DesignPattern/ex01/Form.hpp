#ifndef FORM_HPP
#define FORM_HPP

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
    bool _isSigned;

public:
    Form(FormType p_formType);
    virtual ~Form();

    virtual void execute() = 0;
    void sign() { _isSigned = true; }
    bool isSigned() const { return _isSigned; }
};

class CourseFinishedForm : public Form
{
public:
    CourseFinishedForm();
    void execute();
};

class NeedMoreClassRoomForm : public Form
{
public:
    NeedMoreClassRoomForm();
    void execute();
};

class NeedCourseCreationForm : public Form
{
public:
    NeedCourseCreationForm();
    void execute();
};

class SubscriptionToCourseForm : public Form
{
public:
    SubscriptionToCourseForm();
    void execute();
};

#endif