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
protected:
    FormType _formType;
    bool _isSigned;

public:
    Form(FormType p_formType);
    virtual ~Form();

    virtual void execute() = 0;
    void sign() { _isSigned = true; }
    bool isSigned() const { return _isSigned; }
    
};









#endif