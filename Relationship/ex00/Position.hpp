#include <iostream>
#pragma once

typedef struct Position
{
    int x;
    int y;
    int z;

    Position(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {
		std::cout << "Position constructor called" << std::endl;
	}

	~Position() {
		std::cout << "Position destructor called" << std::endl;
	}

} t_position;