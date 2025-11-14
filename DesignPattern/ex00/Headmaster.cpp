#include    "Headmaster.hpp"
#include    <iostream>

Headmaster::Headmaster(std::string p_name) : Staff(p_name)
{
}

void Headmaster::receiveForm(Form *p_form)
{
    if (p_form)
        _formToValidate.push_back(p_form);
}

void Headmaster::validateForms()
{
    std::cout << "Headmaster " << getName() 
        << " is validating forms." << std::endl;
    for (std::size_t i = 0; i < _formToValidate.size(); ++i)
    {
        sign(_formToValidate[i]);
        _formToValidate[i]->execute();
    }
    _formToValidate.clear();
}
