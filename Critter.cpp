/******************************************************************************
** Program name: Critter.cpp
** Author: April Castaneda
** Date: 05.05.2019
** Description: Critter.cpp is the Critter class implementation file.
******************************************************************************/
#include "Critter.hpp"

/******************************************************************************
** Description: Constructor with default values for protected variables.
******************************************************************************/
Critter::Critter(int age, char ascii)
{
	setXCoord(xCoord);
	setYCoord(yCoord);
	setAge(age);
	setAscii(ascii);
}

/******************************************************************************
** Description: Copy constructor.
******************************************************************************/
Critter::Critter(const Critter &obj)
{
	setXCoord(obj.xCoord);
	setYCoord(obj.yCoord);
	setAge(obj.age);
	setAscii(obj.ascii);
}

/******************************************************************************
** Description: Set Methods.
******************************************************************************/
void Critter::setXCoord(int xCoord)
{
	this->xCoord = xCoord;
}

void Critter::setYCoord(int yCoord)
{
	this->yCoord = yCoord;
}

void Critter::setAge(int age)
{
	this->age = age;
}

void Critter::setAscii(char ascii)
{
	this->ascii = ascii;
}

/******************************************************************************
** Description: Get Methods.
*******************************************************************************/
/*int Critter::getXCoord()
{
	return xCoord;
}

int Critter::getYCoord()
{
	return yCoord;
}
*/
int Critter::getAge()
{
	return age;
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
