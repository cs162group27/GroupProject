/*********************************************************************
 ** Program name: Group Project
 ** Author: Group 27
 ** Date: 5/12/2019
 ** Description: This is the Board class implementation file.
 ********************************************************************/

#include "Board.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include "Critter.hpp"
#include "menu.hpp"
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::cin;

/******************************************************************************
** Description: Constructor with default values.
******************************************************************************/
Board::Board(int s, int r, int c, int a, int d)
{
    // Set initial values
    setSteps(s);
    setRows(r);
    setCols(c);
    setAnts(a);
    setDoodlebugs(d);
    setAntCount(0);
    setDoodlebugCount(0);	

    // Initialize board with Critters
    initialize();
}	

/******************************************************************************
** Description: Display Critters on board.
******************************************************************************/	
void Board::display()
{
	int antC = 0;
	int doodleC = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] == nullptr)
            {
                cout << ' ' << " ";
            }

            else 
            {
                cout << board[i][j] -> getAscii() << " ";
		
		if(board[i][j]->getAscii() == 'O')
			antC++;
		else
			doodleC++;
            }
        }
        cout << endl;
    }
}

/******************************************************************************
** Description: Setters and Getters.
******************************************************************************/

// Sets the number of rows for the Board.
void Board::setRows(int r)
{
    rows = r;
}

// Gets the number of rows for the Board.
int Board::getRows()
{
    return rows;
}

// Sets the number of columns for the Board.
void Board::setCols(int c)
{
    cols = c;
}

// Gets the number of columns for the Board.
int Board::getCols()
{
    return cols;
}

// Gets number of Ants.
int Board::getAnts()
{
    return ants;
}

// Sets number of Ants.
void Board::setAnts(int a)
{
    ants = a;
}

// Gets number of Doodlebugs.
int Board::getDoodlebugs()
{
    return doodlebugs;
}

// Returns number of Doodlebugs.
void Board::setDoodlebugs(int d)
{
    doodlebugs = d;
}

// Sets the number of steps.
void Board::setSteps(int s)
{
    steps = s;
}

// Gets the number of steps.
int Board::getSteps()
{
    return steps;
}

// Sets the Ant count.
void Board::setAntCount(int aCount)
{
    antCount = aCount;
}

// Gets the Ant count.
int Board::getAntCount()
{
    return antCount;
}

// Sets the Doodlebug count.
void Board::setDoodlebugCount(int dCount)
{
    doodlebugCount = dCount;
}

// Gets the Doodlebug count.
int Board::getDoodlebugCount()
{
    return doodlebugCount;
}

/* Initializes the Board to empty squares. Places Critters on Board.
Citation for implementation: https://stackoverflow.com/questions/27430523/2d-array-of-object-pointers-in-c */
void Board::initialize()
{
    board = new Critter ** [rows];

    for (int i = 0; i < rows; i++) {
        board[i] = new Critter *[cols];
    }

  for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board [i][j] = nullptr;
        }
    }

  // Create Ants until requisite number reached
  while(antCount < ants)
  {	
	aRow = rand()%rows;
        aCol = rand()%cols;
	
	// If ant doesn't already exist at location
	if(board[aRow][aCol] == nullptr)
        {
		board[aRow][aCol] = new Ant;
		antCount++;
	}
  }

  // Create doodleugs until required doodlebugs number reached
  while(doodlebugCount < doodlebugs)
  {
	dRow = rand()%rows;
        dCol = rand()%cols;
        
	// If doodlebug doesn't already exist at location
	if(board[dRow][dCol] == nullptr)
	{
		board[dRow][dCol] = new Doodlebug;
        	doodlebugCount++;
	}
  }
}

/******************************************************************************
** Description: Function that runs board. Displays board and runs Critter 
**		actions within user inputted time steps.
******************************************************************************/
void Board::run()
{
    // Display initialized board on Day 1
    display();
    cout << "Initialized Board. Day 1 Start." << endl;
 
    // Increment Critters' ages
    for(int i = 0; i < rows; i++)
	for(int j = 0; j < cols; j++)
		if(board[i][j] != nullptr)
			board[i][j]->incrementAge();
    
    /* Run Board. Doodlebugs move, Ant move, Doodlebug breed, Ant breed,
        Doodlebug starve, Increment Critters age, Display resulting board
                end of day. */
    for (int k = 0; k < steps; k++)
    {
	// Reset Critters' moved flag to 0
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			if(board[i][j] != nullptr)
				board[i][j]->setMoved(0);

	// STEP ONE: Move Critters (Doodlebugs move before Ants, requirement)
    // A: Move doodlebugs first
	for (int i = 0; i < rows; i++)
        {
           	for(int j = 0; j < cols; j++)
            	{
			// Does the pointer point to a Critter?
               	 	if(board[i][j] != nullptr)
                	{
				// Is the Critter a Doodlebug?
				if(board[i][j]->getAscii() == 'X')
				{
					// Move Doodlebug
					bool antEaten = 0; // returns if Ant was eaten

					antEaten = board[i][j]->move(board, i, j, rows, cols);

					// if antEaten, decrement antCount
					if(antEaten)
					{
						antCount--;
					}
				}
			}	
		}
	}

    // B: Move Ants next
	for (int i = 0; i < rows; i++)
        {
           	for(int j = 0; j < cols; j++)
            	{
			// Does the pointer point to a Critter?
               	 	if(board[i][j] != nullptr)
                	{
				// Is the Critter an Ant?
				if(board[i][j]->getAscii() == 'O')
				{
					// Move Ant
					board[i][j]->move(board, i, j, rows, cols);
				}
			}	
		}
	}

	// STEP TWO: Breed Critters (Doodlebugs breed before Ants, for consistency)
    // A. Breed Doodlebugs first
	for (int i = 0; i < rows; i++)
        {
           	for(int j = 0; j < cols; j++)
            	{
			// Only breed if there is space on the board
			if((doodlebugCount+antCount) < (rows*cols))
			{
				// Does the pointer point to a Critter?
				if(board[i][j] != nullptr)
				{
					// Is the Criter a Doodlebug?
					if(board[i][j]->getAscii() == 'X')
					{
						bool doodlebugBred = 0;
		
						// Breed Doodlebug
						doodlebugBred = board[i][j]->breed(board, i, j, rows, cols);

						// If Doodlebug bred, increment count
						if(doodlebugBred)
						{
							doodlebugCount++;
						}
					}
				}
			}	
		}
	}

	// B. Breed Ants next
	for (int i = 0; i < rows; i++)
        {
           	for(int j = 0; j < cols; j++)
            	{
                    // Only breed if there is space on the board
                    if((doodlebugCount+antCount) < (rows*cols))
                    {
                        // Does the pointer point to a Critter?
                        if(board[i][j] != nullptr)
                        {
                            // Is the Critter an Ant?
                            if(board[i][j]->getAscii() == 'O')
                            {
                                bool antBred = 0;

                                // Breed  Ant
                                antBred = board[i][j]->breed(board, i, j, rows, cols);
                                
                                // If Ant bred, increment count
                                if(antBred)
                                {
                                    antCount++;
                                }
                            }
                        }
                    }
                }
        }
	
	// STEP 3: Starve Doodlebugs who haven't eaten in three days
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			// Does the pointer point to a Critter?)
			if(board[i][j] != nullptr)
			{
				// Is the Critter a Doodlebug?
				if(board[i][j]->getAscii() == 'X')
				{
					bool starved = 0;
		
					// Starve Doodlebug
					starved = board[i][j]->starve(board, i, j);
		
					// If Doodlebug starved, decrement Doodlebug count
					if(starved)
					{
						doodlebugCount--;
					}
				}
			}
		}
	}

	// STEP 4: Increment Critters' ages
	// Increment Critters' ages
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			if(board[i][j] != nullptr)
				board[i][j]->incrementAge();

	// STEP 5: Display Board end of day - results of Critter actions.
	display();
	cout << "End of day " << k+1 << endl;
    }
    deleteBoard();
}

/******************************************************************************
** Description: Deletes objects.
******************************************************************************/
void Board::deleteBoard()
{
	// Delete objects in grid
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			if(board[i][j] != nullptr)
			{
				delete board[i][j];
			}
		}
		
		// Delete sub array
		delete []board[i];
	}

	// Delete outer array
	delete []board;
	board = nullptr;
}
