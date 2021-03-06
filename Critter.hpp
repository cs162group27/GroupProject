/*********************************************************************
 ** Program name: Group Project
 ** Author: Group 27
 ** Date: 5/12/2019
 ** Description: Critter.hpp is the Critter class specification file.
**********************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP

// In order to use Board class pointer
class Board;

// Critter class declaration
class Critter
{
protected:
	int age;	// Critter age
	bool moved;
	char ascii;	// Critter character on board
public:
	// Constructor with default values for protected variables
	Critter(int age = 1, bool moved = 0, char ascii = ' ');

	// Copy constructor
	Critter(const Critter &obj);
    
    // Virtual destructor
    virtual ~Critter();

	// Setters
	void setAge(int age);
	void setMoved(bool moved);
	void setAscii(char ascii);

	// Getters
	int getAge();
	bool getMoved();
	char getAscii();

	// Function that increments age
	void incrementAge();

	// Function defined in derived classes - does nothing here
	// Function that checks if there are Ants in vicinity
	//virtual int checkAnt(Critter***, int, int) = 0;
	virtual bool move(Critter ***grid, int tempI, int tempJ, int numRows, int numCols) = 0;
	virtual bool breed(Critter ***grid, int tempI, int tempJ, int numRows, int numCols) = 0;
    virtual bool starve(Critter ***grid, int tempI, int tempJ) {return 1;};
	virtual void incrementAntsEaten() {};
};
#endif
