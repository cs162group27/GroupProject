/*********************************************************************
 ** Program name: Group Project
 ** Author: Group 27
 ** Date: 5/12/2019
 ** Description: Ant.hpp is the Ant class specification file.
**********************************************************************/
#ifndef ANT_HPP
#define ANT_HPP
#include "Critter.hpp"

// In order to use Board pointers
class Board;

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
	bool move(Critter ***grid, int tempI, int tempJ, int numRows, int numCols) override;

	// Function that sets Ant's breeding
	bool breed(Critter ***grid, int tempI, int tempJ, int numRows, int numCols) override;
};
#endif
	
