/*******************************************************************************
 ** Author:       Victoria Fisher
 ** Date:         5/12/2019
 ** Description:  This class sets up the Board, initializes as an array of
 **               pointers, contains extraCredit() function to set up the Board.
 *******************************************************************************/

#include "Board.hpp"
#include "Ant.hpp"
//#include "Doodlebug.hpp"
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
    /*
    for (int j = 0; j < cols; j++) {
        board[i][j] = new Critter();
    }
    */
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            board [i][j] = NULL;
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
//        board[dRow][dCol] = new Doodlebug;
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


// Sets number of steps.
//void setSteps(int s)
//{
//    steps = s;
//}
//
//// Gets the number of steps to take.
//int getSteps()
//{
//    return steps;
//}


/* Initializes the Board to empty squares. Places Critters on Board.
Citation for implementation: https://stackoverflow.com/questions/27430523/2d-array-of-object-pointers-in-c */
//void Board::initialize()
//{
//    srand(9);
//    board = new Critter ** [rows];
//
//    for (int i = 0; i < rows; i++) {
//        board[i] = new Critter * [cols];
//    }
//    /*
//    for (int j = 0; j < cols; j++) {
//        board[i][j] = new Critter();
//    }
//    */
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            board [i][j] = NULL;
//        }
//    }
//
//    for (int i = 0; i < ants; i++) {
//        aRow = rand()%rows;
//        aCol = rand()%cols;
//        board[aRow][aCol] = new Ant;
//    }
//
//    for (int i = 0; i < doodlebugs; i++) {
//        dRow = rand()%rows;
//        dCol = rand()%cols;
////        board[dRow][dCol] = new Doodlebug;
//    }
//}

// Displays the Board.
//void Board::display()
//{
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            if (board[i][j] == NULL)
//                cout << ' ';
//            else
//                cout << board[i][j]->cri.getAscii();
//        }
//        cout << endl;
//    }
//}

// Prompts user to set up the Board.
//void Board::extraCredit()
//{
//    /* THIS IS A LOOP TO ACQUIRE THE NUMBER OF ROWS FOR THE BOARD
//    The bool dataGatherer is only used in all following loops to provide an
//    easy instance of true or false for the purposes of input validation. */
//    while (dataGatherer == true)
//    {
//        cout << "Please choose the number of rows for your board." << endl;
//        std::cin >> numRows;
//        if (numRows > 0 && numRows <= 100)
//        {
//            setRows(numRows);
//            dataGatherer = false;
//        }
//        else {
//            cout << "That is not a valid input. Please try again." << endl;
//            std::cin.clear();
//            std::cin.ignore();
//        }
//    }
//    // THIS IS A LOOP TO ACQUIRE THE NUMBER OF COLUMNS FOR THE BOARD
//    while (dataGatherer == false)
//    {
//        std::cout << "Please choose the number of columns for your board." << std::endl;
//        std::cin >> numCols;
//        if (numCols > 0 && numCols <= 100)
//        {
//            setCols(numCols);
//            dataGatherer = true;
//        }
//        else {
//            std::cout << "That is not a valid input. Please try again." << std::endl;
//            std::cin.clear();
//            std::cin.ignore();
//        }
//    }
//    // THIS IS A LOOP TO GET THE NUMBER OF ANTS
//    while (dataGatherer == true)
//    {
//        std::cout << "Please choose the number of ants for your board." << std::endl;
//        std::cin >> numAnts;
//        if (numAnts > 0 && (numAnts < numRows || numAnts < numCols))
//        {
//            setAnts(numAnts);
//            dataGatherer = false;
//        }
//        else {
//            std::cout << "That is way too many ants! Please try again." << std::endl;
//            std::cin.clear();
//            std::cin.ignore();
//        }
//    }
//    // THIS IS A LOOP TO GET THE NUMBER OF DOODLEBUGS
//    while (dataGatherer == false)
//    {
//        std::cout << "Please choose the number of doodlebugs for your board." << std::endl;
//        std::cin >> numDoodlebugs;
//        if (numDoodlebugs > 0 && numDoodlebugs < numAnts)
//        {
//            setDoodlebugs(numDoodlebugs);
//            dataGatherer = true;
//        }
//        else {
//            std::cout << "That is way too many doodlebugs! Please try again." << std::endl;
//            std::cin.clear();
//            std::cin.ignore();
//        }
//    }
//    // THIS IS A LOOP TO GET THE NUMBER OF TIME STEPS
//    while (dataGatherer == true)
//    {
//        std::cout << "Please choose the number of time steps you would like -- "
//                            "e.g. 10, 100, 1000, 10000..." << std::endl;
//        std::cin >> steps;
//
//        if (steps > 0 && steps <= 15000)
//        {
//            dataGatherer = false;
//        }
//        else {
//            std::cout << "That is not a valid input. Please try again." << std::endl;
//            std::cin.clear();
//            std::cin.ignore();
//        }
//    }
//}

// Runs the game. Displays the Board after each step.
//void Board::run()
//{
//    for (int k = 0; k < steps; k++)
//    {
//         for (int i = 0; i < rows; i++)
//         {
//            for(int j = 0; j < cols; j++)
//            {
//                if(board[i][j] != NULL)
//                {
//                    if (ant.getAge() > 3)
//                    {
//                       ant.breed();
//                       ant.setAge(0);
//                    }
//                    if (doodlebug.getAge() > 8)
//                    {
//                        doodlebug.breed();
//                        doodlebug.setAge(0);
//                    }
//                    if(checkOffGrid() && checkOccupied())
//                    {
////                        board[i][j]->move();
//                          // move should be a function within Critter class, not Board
//                    }
////                    board[i][j]->incrementAge();
//                     // increment age is a function within Critter class, not Board
//                }
//            }
//        }
//	    display();
//        cout << endl;
//    }
//}
