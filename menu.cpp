/*********************************************************************
** Program name: Group Project
** Author: Katie Stutts
** Date: 5/6/2019
** Description:
*********************************************************************/

#include <iostream>
#include "menu.hpp"
#include "Board.hpp"
#include "inputValidation.hpp"

using std::cout;
using std::endl;

int startMenu()
{
    // declare and initialize user's selection to 0
    int selection = 0;

    cout << "****************************************************************************" << endl;
    cout << "Welcome to the Predator-Prey Game!\nPlease indicate what you would like to do, "
            "based on the following options.\n"
            "1. Start Predator-Prey Game Simulator." << '\n' << "2. Quit." << '\n' <<
            "3. **EXTRA CREDIT** Set up your own game board!!!" << endl;
    cout << "****************************************************************************" << endl;

    selection = returnInt();

    // while user's selection is less than 0 and greater than 2
    while (selection <= 0 || selection > 3) {
        cout << "ERR. Please enter an valid input." << endl;
        selection = returnInt();
    }

    if (selection == 1)
    {
        cout << "Let's start the simulation ..." << endl;
        cout << "Please enter the number of steps." << endl;
        int steps = returnInt();
        while (steps <= 0 || steps > 500) // arbirtary max of 500 steps
        {
            steps = returnInt();
        }

        Board bd(steps);

        bd.display();
        cout << bd.getAnts() << endl;
        cout << bd.getDoodlebugs() << endl;

    }
    else if (selection == 2)
    {
        cout << "You decided to quit the program. Thanks for playing!" << endl;
    }
    else if (selection == 3)
    {
        cout << "Alright, let's make it random! ;)" << endl;
    }

    return selection;
}
// placeholder code for extra credit. will be implemented in main game/simulation class.

/*
int row, col, steps, startRow, startCol, stepCount, numAnts, numDoodleBugs = 0;

if (randStart == 0)
{
row = getStartInfo("Enter an integer to represent the number of rows for the board.", 2, 100);
col = getStartInfo("Enter an integer to represent the number of columns for the board.", 2, 100);
steps = getStartInfo("Enter an integer to represent the total number of steps.", 1, 1000);
numAnts = getStartInfo("Enter an integer to represent the total number of ants.", 1, 100);
numDoodleBugs = getStartInfo("Enter an integer to represent the total number of doodle bugs.", 1, 100);
startRow = getStartInfo("Enter an integer to represent the starting row of the ant.", 1, row - 1);
startCol = getStartInfo("Enter an integer to represent the starting column of the ant.", 1, col - 1);
}
else
{
row = getStartInfo("Enter an integer to represent the number of rows for the board.", 2, 100);
col = getStartInfo("Enter an integer to represent the number of columns for the board.", 2, 100);
steps = getStartInfo("Enter an integer to represent the total number of steps.", 1, 1000);

srand(time(0));
startRow = (rand() % row - 1) + 1;
startCol = (rand() % col - 1) + 1;
}
 */