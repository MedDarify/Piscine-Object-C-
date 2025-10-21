#include "Shovel.hpp"

Shovel::Shovel()
{
    std::cout << "Shovel constructor called" << std::endl;
}

Shovel::~Shovel()
{
    std::cout << "Shovel destructor called" << std::endl;
}

void Shovel::use()
{
    this->numberOfUses++;
    std::cout << "A shovel is being used! (Total uses: " << this->numberOfUses << ")" << std::endl;
}