/*********************************************************************
 ** Program name: Group Project
 ** Author: Group 27
 ** Date: 5/12/2019
** Description: Critter.cpp is the Critter class implementation file.
**********************************************************************/
#include "Critter.hpp"

/******************************************************************************
** Description: Constructor with default values for protected variables.
******************************************************************************/
Critter::Critter(int age, bool moved, char ascii)
{
	setAge(age);
	setMoved(moved);
	setAscii(ascii);
}

/******************************************************************************
** Description: Copy constructor.
******************************************************************************/
Critter::Critter(const Critter &obj)
{
	setAge(obj.age);
	setMoved(obj.moved);
	setAscii(obj.ascii);
}

/******************************************************************************
 ** Description: Virtual destructor.
 ******************************************************************************/
Critter::~Critter() {
    
}

/******************************************************************************
** Description: Set Methods.
******************************************************************************/
void Critter::setAge(int age)
{
	this->age = age;
}

void Critter::setMoved(bool moved)
{
	this->moved = moved;
}

void Critter::setAscii(char ascii)
{
	this->ascii = ascii;
}

/******************************************************************************
** Description: Get Methods.
*******************************************************************************/
int Critter::getAge()
{
	return age;
}

bool Critter::getMoved()
{
	return moved;
}

char Critter::getAscii()
{
	return ascii;
}

/******************************************************************************
** Description: Function that increments age.
******************************************************************************/
void Critter::incrementAge()
{
	age++;
}
