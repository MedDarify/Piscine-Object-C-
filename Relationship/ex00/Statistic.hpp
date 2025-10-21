#ifndef STATISTIC_HPP
#define STATISTIC_HPP

#include <iostream>

typedef struct Statistic
{
	int level;
	int exp;

	Statistic(int level = 1, int exp = 0) : level(level), exp(exp)
	{
		std::cout << "Statistic constructor called" << std::endl;
	}

	~Statistic()
	{
		std::cout << "Statistic destructor called" << std::endl;
	}
} t_statictic;

#endif