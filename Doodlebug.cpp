//
// Created by Patrick Oh on 2019-05-07.
//

#include <random>
#include "Doodlebug.hpp"
#include "Critter.hpp"

#include <iostream>
using std::cout;
using std::endl;

Doodlebug::Doodlebug(): Critter(1, 0, 'X')
{
    antsEaten = 0;
}

Doodlebug::Doodlebug(const Doodlebug &obj):Critter(obj.age, obj.moved, obj.ascii)
{
    antsEaten = 0;
}

//void Doodlebug::move(int &tempI, int &tempJ)
void Doodlebug::move(Critter ***grid, int gridX, int gridY, int numRows, int numCols)
{
    int randNum = 0;

    std::random_device seed;	// Will be used to obtain a seed for the random
				// number engine
    std::mt19937 gen(seed());	// Standard mersenne_twister_engine seeded with seed()


    int bugX = gridX,
        bugY = gridY,
        count1 = 0,
        count2 = 0,
        count3 = 0,
        count4 = 0,
	loopCount = 0;
 
    // Now, see if neighboring cell is occupied or off the grid
    bool full = 0;	// Variable to see if cell is occupied.
    bool offBounds = 0;	// Variable to see if cell is off grid.
    bool antFound = 0;

    // Look at all directions around doodlebug and find a space that's not offgrid
    // and contains an Ant
    do	
    {
	// Check South if not offgrid and there is an Ant
	if(!isOffGrid(gridX+1, gridY, numRows, numCols))
	{
		if(isAnt(grid, gridX+1, gridY))
		{
			bugX = gridX + 1;
			bugY = gridY;
			antFound = 1;
			continue;
		}
		else
			loopCount++;
	}
	// Check East if not offgrid and there is an Ant
	if(!isOffGrid(gridX, gridY+1, numRows, numCols))
	{
		if(isAnt(grid, gridX, gridY+1))
		{
			bugX = gridX;
			bugY = gridY + 1;
			antFound = 1;
			continue;
		}
		else
			loopCount++;
	}
	// Check North if not offgrid and there is an Ant
	if(!isOffGrid(gridX-1, gridY, numRows, numCols))
	{
		if(isAnt(grid, gridX-1, gridY))
		{
			bugX = gridX - 1;
			bugY = gridY;
			antFound = 1;
			continue;	
		}
		else
			loopCount++;
	}
	// Check Wast if not offgrid and there is an Ant
	if(!isOffGrid(gridX, gridY-1, numRows, numCols))
	{
		if(isAnt(grid, gridX, gridY-1))
		{
			bugX = gridX;
			bugY = gridY - 1;
			antFound = 1;
			continue;
		}
		else
			loopCount++;
	}
     }
     while(!antFound && (loopCount < 4));

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

		// Now, see if neighboring cell is offgrid or occupied
		offBounds = isOffGrid(bugX, bugY, numRows, numCols);
		bool occupied = 0;	

		// If not offgrid, check if occupied
		if(!offBounds)
		{
			// Is there a Critter in coordinates?
			occupied = isOccupied(grid, bugX, bugY);
		}	
	
		// If not offgrid, have no adjacent critters, and haven't moved 
		// this day, then Doodlebug moves.
		if(!offBounds && !occupied && !(grid[gridX][gridY]->getMoved()))
		{
		    // Store new direction's pointer
		    Critter *tempPtr = grid[bugX][bugY];
		
		    // Swap pointer values
		    grid[bugX][bugY] = grid[gridX][gridY];
		    grid[gridX][gridY] = tempPtr;
		
		    // Set Critters' moved flag for the day
		    grid[bugX][bugY]->setMoved(1);
		}
	}
	// Else, an Ant has been found at bugX, bugY coordinates but only move
	// if Doodlebug hasn't moved already
	else
	{
		// See if Doodlebug hasn't moved
		if(!(grid[gridX][gridY]->getMoved()))
		{
			// Eat Ant
			eatAnt(grid, bugX, bugY);

			// Move Doodlebugs after having eaten	
			// Store new direction's pointer
			Critter *tempPtr = grid[bugX][bugY];
			
			// Swap pointer values
			grid[bugX][bugY] = grid[gridX][gridY];
			grid[gridX][gridY] = tempPtr;
			
			// Set Critters' moved flag for the day
			grid[bugX][bugY]->setMoved(1);
		}
	}
}
	/*
    count1 = (checkAnt(grid, gridX + 1, gridY));
    count2 = (checkAnt(grid, gridX - 1, gridY));
    count3 = (checkAnt(grid, gridX, gridY - 1));
    count4 = (checkAnt(grid, gridX, gridY + 1));
    if(antCount > 1)
    {
        int chance = 0;

        std::uniform_int_distribution<> dis (1, antCount);

        chance = dis(gen);

        if(chance == count1)
        {
            eatAnt(grid, gridX + 1, gridY);
            bugX = gridX + 1;
            bugY = gridY;
        }

        else if(chance == count2)
        {
            eatAnt(grid, gridX - 1, gridY);
            bugX = gridX - 1;
            bugY = gridY;
        }

        else if(chance == count3)
        {
            eatAnt(grid, gridX, gridY - 1);
            bugX = gridX;
            bugY = gridY - 1;
        }

        else if(chance == count4)
        {
            eatAnt(grid, gridX, gridY + 1);
            bugX = gridX;
            bugY = gridY + 1;
        }

        if(grid[bugX][bugY] == nullptr)
        {
            full = 0;
        }

        else
        {
            full = 1;
        }

        if(bugX >= numRows)
        {
            offBounds = 1;
        }

        else if(bugY >= numCols)
        {
            offBounds = 1;
        }

        else if(bugX < 0)
        {
            offBounds = 1;
        }

        else if(bugY < 0)
        {
            offBounds = 1;
        }

        else
        {
            offBounds = 0;
        }

        if(!full && !offBounds)
        {
            grid[bugX][bugY] = grid[gridX][gridY];

            grid[gridX][gridY] = nullptr;
        }
    }

    else if(antCount == 1)
    {
        if(checkAnt(grid, gridX + 1, gridY))
        {
            eatAnt(grid, gridX + 1, gridY);
            bugX = gridX + 1;
            bugY = gridY;
        }

        else if(checkAnt(grid, gridX - 1, gridY))
        {
            eatAnt(grid, gridX - 1, gridY);
            bugX = gridX - 1;
            bugY = gridY;
        }

        else if(checkAnt(grid, gridX, gridY + 1))
        {
            eatAnt(grid, gridX, gridY + 1);
            bugX = gridX;
            bugY = gridY + 1;
        }

        else if(checkAnt(grid, gridX, gridY - 1))
        {
            eatAnt(grid, gridX, gridY - 1);
            bugX = gridX;
            bugY = gridY - 1;
        }

        if(grid[bugX][bugY] == nullptr)
        {
            full = 0;
        }

        else
        {
            full = 1;
        }

        if(bugX >= numRows)
        {
            offBounds = 1;
        }

        else if(bugY >= numCols)
        {
            offBounds = 1;
        }

        else if(bugX < 0)
        {
            offBounds = 1;
        }

        else if(bugY < 0)
        {
            offBounds = 1;
        }

        else
        {
            offBounds = 0;
        }
        if(!full && !offBounds)
        {
            grid[bugX][bugY] = grid[gridX][gridY];

            grid[gridX][gridY] = nullptr;
        }
    }

    else
    {
        int randNum = 0;

        std::uniform_int_distribution<> dis(1, 4);

        randNum = dis(gen);	// Assign generated random number to variable
*/


bool Doodlebug::breed(Critter ***grid, int gridX, int gridY, int numRows, int numCols)
{
    // Check if Doodlebug can breed (age >= 8)
    if(grid[gridX][gridY]->getAge() >= 8)
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

        do
        {
            randNum = dis(gen);
		cout << "randnum: " << randNum << endl;
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
	    grid[gridX][gridY]->setAge(0);	// Reset age
	    return 1;
        }
	else // No Doodlebugs bred
	{
	    return 0;
	}
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
    if(antsEaten == 0 && age == 3)
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
