#ifndef STAFF_HPP
#define STAFF_HPP

#include    "Person.hpp"


class Staff : public Person
{
public:
    Staff(std::string p_name);
	void sign(Form* p_form);
};

#endif