/******************************************************************************
** Program name: Ant.cpp
** Author: April Castaneda
** Date: 05.05.2019
** Description: Ant.cpp is the Ant class implementation file.
******************************************************************************/
#include "Ant.cpp"

/******************************************************************************
** Description: Constructor with default values for xCoord, yCoord. Loads these
**		values to Critter class as well as 1 for age and 'O' for Ant 
**		char ascii.
******************************************************************************/
Ant::Ant(int xCoord, int yCoord) : Critter(xCoord, yCoord, 1, 'O') 
{
}

/******************************************************************************
** Description: Copy constructor.
******************************************************************************/
Ant::Ant(const Ant &obj) : Critter(obj.xCoord, obj.yCoord, obj.age, obj.ascii)
{
}

/******************************************************************************
** Description: Function that sets Ant movements. For every time step, Ants
**		randomly move up, down, left, right. If neighboring cell in 
**		selected direction is occupied or would move Ant off the grid,
**		then Ant stays in current cell.
******************************************************************************/
void Ant::move()
{
	int randNum = 0;
	int tempX = 0;	// Variables to hold xCoord and yCoord
	int tempY = 0;

	std::random_device seed; // Will be used to obtain a seed for
				 // the random number engine
	std::mt19937 gen(seed()); // Standard mersenne_twister_engine seeded
				  // with seed()
	std::uniform_int_distribution<> dis(1, 4);

	randNum = dis(gen);	// Assign generated random number to variable

	// Do not move Ant yet. Assign temporary variables and check
	// neighboring cells.
	// If 1 = East/Right
	if(randNum == 1)
	{
		tempX = xCoord + 1;
		tempY = yCoord;
	}
	// If 2 == South/Down
	else if(randNum == 2)
	{
		tempX = xCoord;
		tempY = yCoord + 1;
	}
	// If 3 == West/Left
	else if(randNum == 3)
	{
		tempX = xCoord - 1;
		tempY = yCoord;
	}
	// Else 4 == North/Up
	else
	{
		tempX = xCoord;
		tempY = yCoord - 1;
	}

	// Now, see if neighboring cell is occupied or off the grid
	bool occupied = 0;	// Variable to see if cell is occupied.
	bool offGrid = 0;	// Variable to see if cell is off grid.

	// Check if neighboring cell is occupied.
	occupied = checkOccupied(tempX, tempY);	
		
	// Check if neighboring cell is off the grid.
	offGrid = checkOffGrid(tempX, tempY);
		
	// Now see if we can move Ant
	// If unable to move,
	if(occupied || offGrid)
	{
		return;	// Ant stays in current cell
	}
	else 	// Else, able to move - so Move Ant
	{
		// First, assign pointer at new direction to the value
		// of the pointer for the currect Ant position
		grid[tempX][tempY] = *grid[xCoord][yCoord];

		// Then assign current position pointer to NULL
		grid[xCoord][yCoord] = NULL;
	}
}

/******************************************************************************
** Description: Function that checks if move() direction is occupied.
******************************************************************************/
bool Ant::checkOccupied(int x, int y)
{
	// Is there an Ant or Doodlebug in coordinates?
	if(((grid[x][y]->ascii) == 'O') || ((grid[x][y]->ascii) == 'X'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/******************************************************************************
** Description: Function that checks if move() direction is off the grid.
******************************************************************************/
bool Ant::checkOffGrid(int x, int y)
{
	// Are coordinates off grid?
	// Moving clockwise
	// Are the coordinates at the East/Right edge of the grid?
	if(x >= rowSize)
	{
		return 1;
	}
	// Are the coordinates at the South/Bottom edge of the grid?
	else if(y >= columnSize)
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
void Ant::breed()
{
	// Check if Ant can breed (age > 3)
	if(this->age > 3)
	{
		// Next


		// Generate random direction 1=East/Right, 2=South/Down, 
		// 3=West/Left, 4=North/Up
		int randNum = 0;
		int tempX = 0;	// Variables to hold xCoord and yCoord
		int tempY = 0;
	
		// Variables that counts how many times 1 or 2 or 3 or 4 are
		// generated by the random number generator. 
		int count1, count2, count3, count4;
		count1 = count2 = count3 = count4 = 0;

		std::random_device seed; // Will be used to obtain a seed for
					 // the random number engine
		std::mt19937 gen(seed()); // Standard mersenne_twister_engine seeded
					  // with seed()
		std::uniform_int_distribution<> dis(1, 4);

		// Enter do/while loop to keep generating random numbers until 
		// either an unoccupied neighboring cell is found or all 
		// neighboring cells are determined to be occupied.
		do
		{
			randNum = dis(gen);	// Assign generated random 
						// number to variable
		
			// Do not breed Ant yet. Assign temporary variables and check
			// neighboring cells.
			// If 1 = East/Right
			if(randNum == 1)
			{
				tempX = xCoord + 1;
				tempY = yCoord;
				count1++;	// increment random number counter
			}
			// If 2 == South/Down
			else if(randNum == 2)
			{
				tempX = xCoord;
				tempY = yCoord + 1;
				count2++;	// increment random number counter
			}
			// If 3 == West/Left
			else if(randNum == 3)
			{
				tempX = xCoord - 1;
				tempY = yCoord;
				count3++;	// increment random number counter
			}
			// Else 4 == North/Up
			else
			{
				tempX = xCoord;
				tempY = yCoord - 1;	
				count4++;	// increment random number counter
			}

			// Now, see if neighboring cell is occupied or off the grid
			bool occupied = 0; // Variable to see if cell is occupied.
			bool offGrid = 0; // Variable to see if cell is off grid.

			// Check if neighboring cell is occupied.
			occupied = checkOccupied(tempX, tempY);	
				
			// Check if neighboring cell is off the grid.
			offGrid = checkOffGrid(tempX, tempY);
		
		// Loop until an available neighboring cell is found OR all
		// neighboring cells are determined to be unavailable.
		}
		while((occupied || offGrid) && ((count1 < 1) && (count2 < 1) && (count3 < 1) && (count4 < 1)));
		
		// If tempX and tempY are unchanged from original xCoord and
		// yCoord values, then Ant cannot breed. Leave function.
		if((tempX == xCoord) && (tempY == yCoord))
		{
			return;	// Ant does not breed.
		}
		else 	// Else, able to breed - so breed Ant
		{
			// First, assign pointer at new direction to the value
			// of the pointer for the currect Ant position
			grid[tempX][tempY] = new Ant(tempX, tempY);
		}
	}
}


