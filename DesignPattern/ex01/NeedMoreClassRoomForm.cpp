#include "NeedMoreClassRoomForm.hpp"

#include <iostream>

NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(NeedMoreClassRoom)
{
}

void NeedMoreClassRoomForm::execute()
{
    if (this->isSigned())
        std::cout << "Executing: Need More Class Room." << std::endl;
    else
        std::cout << "Cannot execute: Form not signed." << std::endl;
}