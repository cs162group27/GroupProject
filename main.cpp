//#include <iostream>
#include <cstdlib>	// Header file needed to use srand
#include <ctime>	// Header file needed to use stime

#include "menu.hpp"
//#include "Board.hpp"

int main()
{
	unsigned seed;	// Random generator seed

	// Uses time function to get a seed value for srand
	seed = time(0);
	srand(seed);

	startMenu();

	return 0;
}
