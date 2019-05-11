//
// Created by Patrick Oh on 2019-05-07.
//

#include <random>
#include "Doodlebug.hpp"
#include "Critter.hpp"

#include <iostream>
using std::cout;
using std::endl;

Doodlebug::Doodlebug(): Critter(0, 0, 'X')
{
    antsEaten = 0;
}

Doodlebug::Doodlebug(const Doodlebug &obj):Critter(obj.age, obj.moved, obj.ascii)
{
    antsEaten = 0;
}
/******************************************************************************
** Description: Function that moves Doodlebuges.
******************************************************************************/
bool Doodlebug::move(Critter ***grid, int gridX, int gridY, int numRows, int numCols)
{
	// Only move Doodlebug if Doodlebug hasn't already moved this turn
	if(!moved)
	{
		// To generate random number
		int randNum = 0;
		std::random_device seed;	// Will be used to obtain a seed for the random
					// number engine
		std::mt19937 gen(seed());	// Standard mersenne_twister_engine seeded with seed()

		int bugX = gridX,
		bugY = gridY,
		count1 = 0,
		count2 = 0,
		count3 = 0,
		count4 = 0;

		bool offBounds = 0;	// Variable to see if cell is off grid.
		bool antFound = 0;

		// Look at all directions around doodlebug and find a space that's not offgrid
		// and contains an Ant
		do	
		{
			// Check South if not offgrid and there is an Ant
			if(!isOffGrid(gridX+1, gridY, numRows, numCols) && (count1<1))
			{
				if(isAnt(grid, gridX+1, gridY))
				{
					bugX = gridX + 1;
					bugY = gridY;
					antFound = 1;
					count1++;
					break;
				}
				else
					count1++;
			}
			// Check East if not offgrid and there is an Ant
			if(!isOffGrid(gridX, gridY+1, numRows, numCols) && (count2<1))
			{
				if(isAnt(grid, gridX, gridY+1))
				{
					bugX = gridX;
					bugY = gridY + 1;
					antFound = 1;
					count2++;
					break;
				}
				else
					count2++;
			}
			// Check North if not offgrid and there is an Ant
			if(!isOffGrid(gridX-1, gridY, numRows, numCols) && (count3<1))
			{
				if(isAnt(grid, gridX-1, gridY))
				{
					bugX = gridX - 1;
					bugY = gridY;
					antFound = 1;
					count3++;
					break;
				}
				else
					count3++;
			}
			// Check Wast if not offgrid and there is an Ant
			if(!isOffGrid(gridX, gridY-1, numRows, numCols) && (count4<1))
			{
				if(isAnt(grid, gridX, gridY-1))
				{
					bugX = gridX;
					bugY = gridY - 1;
					antFound = 1;
					count4++;
					break;
				}
				else
					count4++;
			}
			else	// No Ants here
			{
				break;	
			}
		} // Loop until all possible directions have been explored
		while(!antFound && ((count1 < 1) || (count2 < 1) || (count3 < 1) || (count4 < 1)));

		// If no Ants found around Doodlebug, move like an Ant.
		if(!antFound)	
		{
			// Generate random number
			std::uniform_int_distribution<> dis(1, 4);
			randNum = dis(gen);	// Assign generated randNum to variable

			// Do not move Doodlebug yet. Assign temporary variables and check
			// neighboring cells.
			// If 1 = South
			if(randNum == 1)
			{
			    bugX = gridX + 1;
			    bugY = gridY;
			}
			// If 2 == East
			else if(randNum == 2)
			{
			    bugX = gridX;
			    bugY = gridY + 1;
			}
			// If 3 == North
			else if(randNum == 3)
			{
			    bugX = gridX - 1;
			    bugY = gridY;
			}
			// Else 4 == West
			else
			{
			    bugX = gridX;
			    bugY = gridY - 1;
			}

			// Now, see if neighboring cell is offBounds or occupied
			offBounds = isOffGrid(bugX, bugY, numRows, numCols);
			bool occupied = 0;	

			// If not offBounds, check if occupied
			if(!offBounds)
			{
				// Is there a Critter in coordinates?
				occupied = isOccupied(grid, bugX, bugY);
			
				// If not offgrid have no adjacent critters, 
				// then Doodlebug moves.
				if(!offBounds && !occupied)
				{
				    // Store new direction's pointer
				    Critter *tempPtr = grid[bugX][bugY];
				
				    // Swap pointer values
				    grid[bugX][bugY] = grid[gridX][gridY];
				    grid[gridX][gridY] = tempPtr;
			
				    grid[bugX][bugY]->setMoved(1);
						
				    return 0;	// no ant eaten	
				}
				else // Offbounds or occupied, doesn't move
				{
				    return 0; // no ant eaten
				}
			}
			else // Offbounds, doesn't move
			{
				return 0; // no ant eaten
			}
		}
		// Else, an Ant has been found at bugX, bugY coordinates
		else
		{
		
			// Eat Ant
			eatAnt(grid, bugX, bugY);

			// Move Doodlebugs after having eaten	
			// Store new direction's pointer
			Critter *tempPtr = grid[bugX][bugY];
			
			// Swap pointer values
			grid[bugX][bugY] = grid[gridX][gridY];
			grid[gridX][gridY] = tempPtr;
			
			grid[bugX][bugY]->setMoved(1);
			
			// Increment Ants eaten
			grid[bugX][bugY]->incrementAntsEaten();
			
			return 1; // ant eaten
		}
	}
	else	// Already moved this turn
	{
		return 0; // no ant eaten
	}	
}

/******************************************************************************
** Description: Function that breeds Doodlebugs.
******************************************************************************/
bool Doodlebug::breed(Critter ***grid, int gridX, int gridY, int numRows, int numCols)
{
    // Check if Doodlebug can breed (age >= 8)
    if(age >= 8)
    {
        int randNum = 0,
            bugX = 0,
            bugY = 0,
            count1 = 0, count2 = 0, count3 = 0, count4 = 0;

        bool occupied = 0; // Variable to see if cell is occupied.
        bool offGrid = 0; // Variable to see if cell is off grid.


        std::random_device seed;
        std::mt19937 gen(seed());
        std::uniform_int_distribution<> dis(1, 4);

	// Produce random number to determine direction to breed
        do
        {
            randNum = dis(gen);
            if(randNum == 1)
            {
                bugX = gridX + 1;
                bugY = gridY;

                count1++;
            }

            else if(randNum == 2)
            {
                bugX = gridX - 1;
                bugY = gridY;

                count2++;
            }

            else if(randNum == 3)
            {
                bugX = gridX;
                bugY = gridY - 1;

                count3++;
            }

            else if(randNum == 4)
            {
                bugX = gridX;
                bugY = gridY + 1;

                count4++;
            }

	    // Now, see if neighboring cell is off grid
	    offGrid = isOffGrid(bugX, bugY, numRows, numCols);

	    // If not offGrid, check to see if it's occupied
	    if(!offGrid)
	    {
		if(isOccupied(grid, bugX, bugY))
		{
			occupied = 1;
		}
		else
		{
			occupied = 0;
		}	
            }

        } // Loop until an available neighboring cell is found or ALL cells unavailable
	while((occupied || offGrid) && ((count1 < 1) || (count2 < 1) || (count3 < 1) || (count4 < 1)));

        if(!offGrid && !occupied)
        {
            grid[bugX][bugY] = new Doodlebug;	// Create new Doodlebug
	    setAge(0);	// Reset age of Doodlebug
	    return 1;
        }
	else // No Doodlebugs bred
	{
	    return 0;
	}
    }
    else // No Doodlebugs old enough
    {
	return 0;
    }	
}

int Doodlebug::checkAnt(Critter ***grid, int x, int y)
{
    if(grid[x][y] -> getAscii() == 'O')
    {
        antCount++;
    }

    return antCount;
}

void Doodlebug::eatAnt(Critter ***grid, int x, int y)
{
    Critter *tempPtr = nullptr;
    delete grid[x][y];
    grid[x][y] = tempPtr;

//    antsEaten++;
}

void Doodlebug::survive(Critter ***grid, int x, int y)
{
    if(antsEaten == 0 && age >= 3)
    {
        grid[x][y] = nullptr;
    }
}

/******************************************************************************
** Description: Function that determines if adjacent space is offgrid.
******************************************************************************/
bool Doodlebug::isOffGrid(int x, int y, int numRows, int numCols)
{
    // Check if neighboring cell is off the grid.
    // Moving clockwise
    // Are the coordinates at the East/Right edge of the grid?
    if(x >= numRows)
    {
	return 1;
    }
	// Are the coordinates at the South/Bottom edge of the grid?
    else if(y >= numCols)
    {
	return 1;
    }
	// Are the coordinates at the West/Left edge of the grid?
    else if(x < 0)
    {
	return 1;
    }
	// Are the coordinates the the North/Top edge of the grid?
    else if(y < 0)
    {
	return 1;
    }
	// Coordinates are within limits
    else
    {
	return 0;
    }
}

/******************************************************************************
** Description: Function that determines if adjacent space is an Ant.
******************************************************************************/
bool Doodlebug::isAnt(Critter ***grid, int x, int y)
{
	// Does the pointer point to a Critter?
	if(grid[x][y] != nullptr)
	{
		// Does the pointer point to an Ant?
		if(grid[x][y]->getAscii() == 'O')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else // Pointer points to nullptr
	{
		return 0;
	}	
}

/******************************************************************************
** Description: Function that determines if adjacent space has a Critter.
******************************************************************************/
bool Doodlebug::isOccupied(Critter ***grid, int x, int y)
{
	if(grid[x][y] != nullptr)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/******************************************************************************
** Description: Increment ants eaten.
******************************************************************************/
void Doodlebug::incrementAntsEaten()
{
	antsEaten++;
    antCount--;
}
