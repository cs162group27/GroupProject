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

Board::Board(int steps)
{
    cout << "Board constructor called." << endl;
    cout << "number of steps is: " << steps << endl;

    srand(9);
    board = new Critter ** [rows];

    for (int i = 0; i < rows; i++)
    {
        board[i] = new Critter * [cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            board [i][j] = nullptr;
        }
    }

    for (int i = 0; i < ants; i++)
    {
        aRow = rand()%rows;
        aCol = rand()%cols;
        board[aRow][aCol] = new Ant;
    }

    for (int i = 0; i < doodlebugs; i++)
    {
        dRow = rand()%rows;
        dCol = rand()%cols;
        board[dRow][dCol] = new Doodlebug;
    }
}


void Board::display()
{
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
            }
        }

        cout << endl;
    }
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


/* Initializes the Board to empty squares. Places Critters on Board.
Citation for implementation: https://stackoverflow.com/questions/27430523/2d-array-of-object-pointers-in-c */
void Board::initialize()
{
    srand(9);
    board = new Critter ** [rows];

    for (int i = 0; i < rows; i++) {
        board[i] = new Critter *[cols];
    }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                board[i][j] = new Critter();
            }
        }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board [i][j] = nullptr;
        }
    }

    for (int i = 0; i < ants; i++) {
        aRow = rand()%rows;
        aCol = rand()%cols;
        board[aRow][aCol] = new Ant;
    }

    for (int i = 0; i < doodlebugs; i++) {
        dRow = rand()%rows;
        dCol = rand()%cols;
        board[dRow][dCol] = new Doodlebug;
    }
}

