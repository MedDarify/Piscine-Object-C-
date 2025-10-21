#include "Hammer.hpp"

Hammer::Hammer()
{
	std::cout << "Hammer constructor called" << std::endl;
}

Hammer::~Hammer()
{
	std::cout << "Hammer destructor called" << std::endl;
}

void Hammer::use()
{
	this->numberOfUses++;
	std::cout << "A hammer is being used! (Total uses: " << this->numberOfUses << ")" << std::endl;
}