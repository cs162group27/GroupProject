/******************************************************************************
** Program name: Critter.hpp
** Author: April Castaneda
** Date: 05.05.2019
** Description: Critter.hpp is the Critter class specification file.
******************************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP

// Critter class declaration
class Critter
{
protected:
	int xCoord, 	
		yCoord;	// Critter coordinates
	int age;	// Critter age
	char ascii;	// Critter character on board
public:
	// Constructor with default values for protected variables
	Critter(int xCoord = 0, int yCoord = 0, int age = 1, char ascii = ' ');

	// Copy constructor
	Critter(const Critter &obj);

	// Setteres
	void setXCoord(int xCoord);
	void setYCoord(int yCoord);
	void setAge(int age);
	void setAscii(char ascii);

	// Getters
	int getXCoord();
	int getYCoord();
	int getAge();
	char getAscii();

	// Function defined in derived classes - does nothing here
	virtual void move() {};
	
	// Function defined in derived classes
	virtual void breed() {};
};
#endif
