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
    cout << "Board constructor called." << endl;
    cout << "number of steps is: " << s << endl;
   
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
//    srand(9);		// srand in main to allow seeding with time
    board = new Critter ** [rows];

    for (int i = 0; i < rows; i++) {
        board[i] = new Critter *[cols];
    }
/*	Not creating a Critter object for every block in board
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                board[i][j] = new Critter;
            }
        }
*/
  for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board [i][j] = nullptr;
        }
    }

//    for (int i = 0; i < ants; i++) {
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
void Board::run()
{
    // Display initialized board on Day 1
    display();

    // Run Board. Doodlebugs move, Ant move, Doodlebug breed, Ant breed, 
    // Doodlebug starve, Increment Critters age, Display resulting board 
    // end of day. 
    for (int k = 0; k < steps; k++)
    {
	// Let user know day/time step
	cout << "Day " << k+1 << ":" << endl;

	// Reset Critters' moved flag to 0
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			if(board[i][j] != nullptr)
				board[i][j]->setMoved(0);

	// STEP ONE: Move Critters (Doodlebugs move before Ants, requirement)
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
					board[i][j]->move(board, i, j, rows, cols);	
				}
				// Is the Critter an Ant?
				else if(board[i][j]->getAscii() == 'O')
				{
					// Move Ant
					board[i][j]->move(board, i, j, rows, cols);
				}
			}	
		}
	
	}

	// STEP TWO: Breed Critters (Doodlebugs breed before Ants, for consistency)
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
					// Is the Critter an Ant?
					else if(board[i][j]->getAscii() == 'O')
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

	cout << "End of day " << k+1 << endl;
	display();

	// Increment Critters' ages
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			if(board[i][j] != nullptr)
				board[i][j]->incrementAge();
     }
}
		/*
                    if (board[i][j] -> getAge() > 3)
                    {
                        board[i][j] -> breed(board, i, j, rows, cols);
                        board[i][j] -> setAge(0);
                    }
                    else if (board[i][j] -> getAge() > 8)
                    {
                        board[i][j] -> breed(board, i, j, rows, cols);
                        board[i][j] -> setAge(0);
                    }
                    if(board[i][j] == nullptr)
                    {
                        occupied = 0;
                    }

                    else
                    {
                        occupied = 1;
                    }

                    if(i >= rows)
                    {
                        offGrid = 1;
                    }

                    else if(j >= cols)
                    {
                        offGrid = 1;
                    }

                    else if(i < 0)
                    {
                        offGrid = 1;
                    }

                    else if(j < 0)
                    {
                        offGrid = 1;
                    }

                    else
                    {
                        offGrid = 0;
                    }

                    if(offGrid && occupied)
                    {
                        board[i][j]->move(board, i, j, rows, cols);
                        // move should be a function within Critter class, not Board
                    }
		
                    board[i][j]->incrementAge();
                    // increment age is a function within Critter class, not Board
                }
            }
        }

        display();

        int totalAnts = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                totalAnts += board[i][j]->checkAnt(board, i, j);
            }
        }

        cout << totalAnts;

        cout << endl;
    }
*/

