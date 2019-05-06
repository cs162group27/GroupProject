/************************************************************************
** Program name:  Menu Function
** Author:        Patrick Oh
** Date:          04/02/19
** Description:   This file contains the function that prints out the
 *                menu that allows the user to navigate and execute
 *                the three different recursive functions. The menu also
 *                contains input validation.
*************************************************************************/
#include <iostream>
#include <string>
#include <limits>
#include "menuFunction.hpp"
#include "inputValidation.hpp"
#include "calcTriNum.hpp"
#include "reverseString.hpp"
#include "sumArray.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::numeric_limits;
using std::streamsize;

/*********************************************************************
** Description: This function prints out the menu for the user
**              to navigate through. It also reprints the menu
**              and allows the user to input a choice after
**              each previous choice.
*********************************************************************/
void menuFunction()
{
    while(true)
    {
        int userInput;

        cout << "Please choose one of the following options: " << endl
             << endl
             << "1. Function that will print out the reverse of what you type." << endl
             << endl
             << "2. Function that will print the sum of a series of integers you enter." << endl
             << endl
             << "3. Function that will print the triangle number of an integer you enter." << endl
             << endl
             << "4. Exit program" << endl
             << endl;

        userInput = choiceValidate();

        if(userInput == 1)
        {
            string inputSent;

            cout << "Please enter a sentence to reverse: " << endl << endl;

            getline(cin, inputSent);

            cout << endl
                 << "Your reversed string: " << endl << endl;

            printReverse(inputSent);

            cout << endl << endl;
        }

        else if(userInput == 2)
        {
            int numIntegers,
                total;

            cout << "How many integers would you like to enter?" << endl
                 << endl;

            numIntegers = choiceIntValidate();//input validation

            int *numArray = new int[numIntegers];

            for(int i = 0; i < numIntegers; i++)
            {
                numArray[i] = 0;
            }

            cout << "Please enter " << numIntegers << " integers you would like to sum: " << endl
                 << endl;

            for(int count = 0; count < numIntegers; count++)
            {
                numArray[count] = choiceNegPosValidate();//input validation
            }

            total = sumArray(numArray, numIntegers);

            cout << "Total of all the integers is: " << total << endl << endl;

            delete [] numArray;
        }

        else if(userInput == 3)
        {
            int triNum,
                sum;

            cout << "Enter an integer: " << endl;

            triNum = choiceIntValidate();//input validation

            if(triNum <= 100)
            {
                sum = calcTriNum(triNum);

                cout << "Triangular sum is: " << sum << endl << endl;
            }

            else
            {
                cout << "Number is too big enter again please." << endl << endl;
            }

        }

        else if(userInput == 4)
        {
            exit(0);
        }

        else
        {
            cout << "Please enter a valid option." << endl << endl;
        }
    }
}