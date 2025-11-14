#include    "Staff.hpp"
#include    <iostream>


Staff::Staff(std::string p_name) : Person(p_name)
{
}

void Staff::sign(Form *p_form)
{
    if (p_form)
    {
        std::cout << getName() << " is signing a form." << std::endl;
        p_form->sign();
    }
}
