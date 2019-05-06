/*********************************************************************
** Program name: Group Project
** Author: Katie Stutts
** Date: 5/6/2019
** Description:
*********************************************************************/

#include <iostream>
#include "menu.hpp"
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
