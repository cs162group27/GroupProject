/*********************************************************************
 ** Program name: Group Project
 ** Author: Group 27
 ** Date: 5/12/2019
 ** Description: Ant.cpp is the Ant class implementation file.
**********************************************************************/
#include "Ant.hpp"
#include <random>
#include <iostream>
using std::cout;
using std::endl;
/******************************************************************************
** Description: Constructor with default values for xCoord, yCoord. Loads these
**		values to Critter class as well as 1 for age and 'O' for Ant 
**		char ascii.
******************************************************************************/
Ant::Ant() : Critter(0, 0, 'O') 
{
}

/******************************************************************************
** Description: Copy constructor.
******************************************************************************/
Ant::Ant (const Ant &obj) : Critter(obj.age, obj.moved, obj.ascii)
{

}

/******************************************************************************
** Description: Function that sets Ant movements. For every time step, Ants
**		randomly move up, down, left, right. If neighboring cell in 
**		selected direction is occupied or would move Ant off the grid,
**		then Ant stays in current cell.
******************************************************************************/
bool Ant::move (Critter ***grid, int tempI, int tempJ, int numRows, int numCols)
{
	// Only move Ant if Ant hasn't already moved this turn
	if(!moved)
	{
		int randNum = 0;
		int tempX = 0;	                // Variables to hold xCoord and yCoord
		int tempY = 0;

		std::random_device seed;        // Will be used to obtain a seed for
                                                    // the random number engine
		std::mt19937 gen(seed());       // Standard mersenne_twister_engine seeded
                                                            // with seed()
		std::uniform_int_distribution<> dis(1, 4);

		randNum = dis(gen);	            // Assign generated random number to variable


		// Do not move Ant yet. Assign temporary variables and check neighboring cells.
		// If 1 = East/Right
		if(randNum == 1)
		{
			tempX = tempI + 1;
			tempY = tempJ;
		}
		// If 2 == South/Down
		else if(randNum == 2)
		{
			tempX = tempI;
			tempY = tempJ + 1;
		}
		// If 3 == West/Left
		else if(randNum == 3)
		{
			tempX = tempI - 1;
			tempY = tempJ;
		}
		// Else 4 == North/Up
		else
		{
			tempX = tempI;
			tempY = tempJ - 1;
		}

		// Now, see if neighboring cell is occupied or off the grid
		bool occupied = 0;	            // Variable to see if cell is occupied.
		bool offGrid = 0;	            // Variable to see if cell is off grid.

		// Check if neighboring cell is off the grid.
		// Moving clockwise
		// Are the coordinates at the East/Right edge of the grid?
		if(tempX >= numRows)
		{
			offGrid = 1;
		}
		// Are the coordinates at the South/Bottom edge of the grid?
		else if(tempY >= numCols)
		{
			offGrid = 1;
		}
		// Are the coordinates at the West/Left edge of the grid?
		else if(tempX < 0)
		{
			offGrid = 1;
		}
		// Are the coordinates the the North/Top edge of the grid?
		else if(tempY < 0) 
		{
			offGrid = 1;
		}
		// Coordinates are within limits 
		else
		{
			offGrid = 0;
		}
		
		// If not offgrid, check if occupied
		if(!offGrid)
		{
			// Is there no Ant or Doodlebug in coordinates?
			if(grid[tempX][tempY] == nullptr)
			{
				occupied = 0;
			}
			else 
			{ // There is an Ant or Doodlebug
				occupied = 1;
			}
			
			// If not offgrid, have no adjacent critters, and 
			// hasn't moved this day, then Ant moves
			if(!offGrid && !occupied)
			{
				// Store new direction's pointer
				Critter *tempPtr = grid[tempX][tempY];
				
				// Swap pointer values
				grid[tempX][tempY] = grid[tempI][tempJ];	
				grid[tempI][tempJ] = tempPtr;
			
				grid[tempX][tempY]->setMoved(1);
	
				return 1;	
			}
			else // offGrid or occupied, doesn't move
			{
				return 0;
			}
		}
		else // offGrid, doesn't move
		{
			return 0;
		}
	}
	else // Already moved this turn, so doesn't move
	{
		return 0;
	}
}

/******************************************************************************
** Description: Function that breeds Ant. If Ant survives for three time steps,
**		at the end of the time step (after moving), Ant breeds. This is
**		simulated by creating a new Ant in an adjacent (up, down, left
**		right) cell that is empty randomly. If the cell that is picked
**		is not empty, randomly attempt to pick another one. If there is
**		no empty cell available, no breeding occurs. Once an offspring
**		is produced, an Ant cannot produce an offspring again until it
**		has survived three more steps.
******************************************************************************/
bool Ant::breed(Critter ***grid, int tempI, int tempJ, int numRows, int numCols)
{
	// Check if Ant can breed (age >= 3)
	if (age >= 3)
	{
		// Generate random direction 1=East/Right, 2=South/Down,
		// 3=West/Left, 4=North/Up
		int randNum = 0;
		int tempX = 0;	        // Variables to hold xCoord and yCoord
		int tempY = 0;
		bool occupied = 0;      // Variable to see if cell is occupied.
		bool offGrid = 0;       // Variable to see if cell is off grid.

		// Variables that counts how many times 1 or 2 or 3 or 4 are
		// generated by the random number generator.
		int count1, count2, count3, count4;
		count1 = count2 = count3 = count4 = 0;

		std::random_device seed; // Will be used to obtain a seed for
					                    // the random number engine
		std::mt19937 gen(seed()); // Standard mersenne_twister_engine seeded
                                        // with seed()
		std::uniform_int_distribution<> dis(1, 4);

		/* Enter do/while loop to keep generating random numbers until
            either an unoccupied neighboring cell is found or all
                neighboring cells are determined to be occupied. */
		do
		{
			randNum = dis(gen);	// Assign generated random
                                        // number to variable
			
			// Do not breed Ant yet. Assign temporary variables and check
			// neighboring cells.
			// If 1 = East/Right
			if(randNum == 1)
			{
				tempX = tempI + 1;
				tempY = tempJ;
				count1++;	// increment random number counter
			}
			// If 2 == South/Down
			else if(randNum == 2)
			{
				tempX = tempI;
				tempY = tempJ + 1;
				count2++;	// increment random number counter
			}
			// If 3 == West/Left
			else if(randNum == 3)
			{
				tempX = tempI - 1;
				tempY = tempJ;
				count3++;	// increment random number counter
			}
			// Else 4 == North/Up
			else
			{
				tempX = tempI;
				tempY = tempJ - 1;
				count4++;	// increment random number counter
			}

			// Now, see if neighboring cell is occupied or off the grid
			// Check if neighboring cell is off the grid.
			// Moving clockwise
			// Are the coordinates at the East/Right edge of the grid?
			if(tempX >= numRows)
			{
				offGrid = 1;
			}
			// Are the coordinates at the South/Bottom edge of the grid?
			else if(tempY >= numCols)
			{
				offGrid = 1;
			}
			// Are the coordinates at the West/Left edge of the grid?
			else if(tempX < 0)
			{
				offGrid = 1;
			}
			// Are the coordinates the the North/Top edge of the grid?
			else if(tempY < 0)
			{
				offGrid = 1;
			}
			// Coordinates are within limits
			else
			{
				offGrid = 0;
			}
			
			if(!offGrid)
			{
				// Check to see if neighboring cell is occupied
				// Is there no Ant or Doodlebug in coordinates?
				if(grid[tempX][tempY] == NULL)
				{
					occupied = 0;
				}
				else // There is an Ant or Doodlebug
				{
					occupied = 1;
				}
			}

		// Loop until an available neighboring cell is found OR all
		// neighboring cells are determined to be unavailable.
		}
		while((offGrid || occupied) && ((count1 < 1) || (count2 < 1) || (count3 < 1) || (count4 < 1)));

		if(!offGrid && !occupied)
		{
			grid[tempX][tempY] = new Ant;	// Create new Ant at tempI and tempJ
			setAge(0);	                    // Reset age of Ant
			return 1;
		}
		else	// No Ants bred
		{
			return 0;
		}
	}
	else	// Not old enough to breed
	{
		return 0;
	}
}




