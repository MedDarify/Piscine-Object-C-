#ifndef SECRETARY_HPP
#define SECRETARY_HPP

#include    "Staff.hpp"
#include    "CourseFinishedForm.hpp"

class CourseFinishedForm;
class Secretary : public Staff
{
private:

public:
    Secretary(std::string p_name);

	Form* createForm(FormType p_formType);
	void archiveForm();
};


#endif