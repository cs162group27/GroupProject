/*********************************************************************
 ** Program name: Group Project
 ** Author: Group 27
 ** Date: 5/12/2019
 ** Description: Main function for the Group Project.
 *********************************************************************/

#include <cstdlib>	// Header file needed to use srand
#include <ctime>	// Header file needed to use stime

#include "menu.hpp"

int main()
{
	unsigned seed;	// Random generator seed

	// Uses time function to get a seed value for srand
	seed = time(0);
	srand(seed);

	startMenu();

	return 0;
}
