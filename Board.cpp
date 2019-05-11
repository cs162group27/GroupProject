/*******************************************************************************
 ** Author:       Victoria Fisher
 ** Date:         5/12/2019
 ** Description:  This class sets up the Board, initializes as an array of
 **               pointers, contains extraCredit() function to set up the Board.
 *******************************************************************************/

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
                cout << '.' << " ";
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
	// Debugging display. Counts how many ants and doodlebugs are actually
	// on the board, regardless what count says. Can delete once program
	// works
	cout << "ants: " << antC << endl;
	cout << "doodlebugs: " << doodleC << endl;
}



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


void Board::setSteps(int s)
{
    steps = s;
}

//// Gets the number of steps to take.
int Board::getSteps()
{
    return steps;
}

void Board::setAntCount(int aCount)
{
    antCount = aCount;
}

int Board::getAntCount()
{
    return antCount;
}

void Board::setDoodlebugCount(int dCount)
{
    doodlebugCount = dCount;
}

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

   // Create ants until required ants number reached
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
  //  }

//    for (int i = 0; i < doodlebugs; i++) {
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
  //  }
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
    
    // Run Board. Doodlebugs move, Ant move, Doodlebug breed, Ant breed, 
    // Doodlebug starve, Increment Critters age, Display resulting board 
    // end of day. 
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
				//	cout << "Are we in move doodlebug?" << endl;
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
				//	cout << "Are we in move Ant?" << endl;
					// Move Ant
					board[i][j]->move(board, i, j, rows, cols);
				}
			}	
		}
	
	}

	// STEP TWO: Breed Critters (Doodlebugs breed before Ants, for consistency)
      	// A. Breed Doodlebugs first and see if they starve or not
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

						// If Doodlebug bred, increment count and reset age
						if(doodlebugBred)
						{
				//			cout << "Did we breed Doodlebug?" << endl;
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
                                
                                // If Ant bred, increment count and reset Ant age
                                if(antBred)
                                {
                                    antCount++;
                                }
                            }
                        }
                    }
                }
        }	
	
	// STEP 3: Increment Critters' ages
	// Increment Critters' ages
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			if(board[i][j] != nullptr)
				board[i][j]->incrementAge();
	
	// STEP 4: Display Board end of day - results of Critter actions.
	display();
	cout << "End of day " << k+1 << endl;
        }
    }

