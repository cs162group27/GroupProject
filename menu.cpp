/*********************************************************************
** Program name: Group Project
** Author: Group 27
** Date: 5/12/2019
** Description: Menu functions for the Group Project.
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

    // While user's selection is less than 0 and greater than 2
    while (selection <= 0 || selection > 3) {
        cout << "ERR. Please enter an valid input." << endl;
        selection = returnInt();
    }
    
    // User chooses to start with default values
    if (selection == 1)
    {
        cout << "Let's start the simulation ..." << endl;
        cout << "Please enter the number of steps." << endl;
        int steps = returnInt();
        while (steps <= 0 || steps > 15000) // arbirtary max of 15000 steps
        {
            cout << "Error. Please enter a valid integer between 1 and 15000." << endl;
			steps = returnInt();
        }
        
	    Board bd(steps, 20, 20, 100, 5); // Default values of 20x20 board,
                                                // 100 ants, 5 doodlebugs

        bd.run();
    }
    
    // User chooses to quit
    else if (selection == 2)
    {
        cout << "You decided to quit the program. Thanks for playing!" << endl;
    }
    
    // User chooses to enter their own values
    else if (selection == 3)
    {
        cout << "You selected the Extra Credit option!" << endl;
		int steps = getStartInfo("Please enter an integer to represent the total number of steps.", 1, 15000);
		int row = getStartInfo("Please enter an integer to represent the number of rows for the board.", 2, 2000);
		int col = getStartInfo("Please enter an integer to represent the number of cols for the board.", 2, 2000);
		int maxAnt = (row * col)/2; 
		cout << "max num of ants is : " << maxAnt << endl;
		int numAnts = getStartInfo("Please enter an integer to represent the number of ants.", 1, maxAnt);
		int numDoodleBugs = getStartInfo("Please enter an integer to represent the number of Doodlebugs.", 1, (maxAnt - 1));
		Board bd(steps, row, col, numAnts, numDoodleBugs);
		bd.run();
	}
    return selection;
}

/******************************************************************************
 ** Description: Function that gets the starting values.
 ******************************************************************************/
int getStartInfo(std::string displayMessage, int start, int end)
{
	cout << displayMessage << endl;
	int val = returnInt();
	while(!(isInRange(val, start, end)))
	{
		cout << "Error. Please enter an integer between " << start << " and " << end << endl;
		val = returnInt();
	}
	return val;
}
