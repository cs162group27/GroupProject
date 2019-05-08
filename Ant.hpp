/******************************************************************************
** Program name: Ant.hpp
** Author: April Castaneda
** Date: 05.05.2019
** Description: Ant.hpp is the Ant class specification file.
******************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"
class Board;	// In order to use Board pointers

// Ant class declaration
class Ant : public Critter
{
public:
	// Constructor with default values for xCoord and yCoord
	Ant();
	
	// Copy constructor
	Ant(const Ant &obj);

	// Setters & Getters are in Base class

	// Functions that set Ant movement
	virtual void move(Critter ***grid, int tempI, int tempJ, int numRows, int numCols);

	// Function that sets Ant's breeding
	virtual void breed(Critter ***grid, int tempI, int tempJ, int numRows, int numCols);
};
#endif
	
