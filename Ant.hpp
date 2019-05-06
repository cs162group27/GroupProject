/******************************************************************************
** Program name: Ant.hpp
** Author: April Castaneda
** Date: 05.05.2019
** Description: Ant.hpp is the Ant class specification file.
******************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

// Ant class declaration
class Ant : public Critter
{
public:
	// Constructor with default values for xCoord and yCoord
	Ant(int xCoord = 0, int yCoord = 0);
	
	// Copy constructor
	Ant(const Ant &obj);

	// Setters & Getters are in Base class

	// Functions that set Ant movement
	virtual move();
	bool checkOccupied(int x, int y);
	bool checkOffGrid(int x, int y);

	// Function that sets Ant's breeding
	virtual breed();
};
#endif
	
