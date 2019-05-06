#include <iostream>
#include <string>
#include "Menu.hpp"
#include "inputValidation.hpp"
#include "recursiveFunctions.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;


int startMenu()
{
    int selection = 0;
    cout << "--------------------------------------------------" << endl;
    cout << "What cool recursive thing would you like to do?" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "1. Reverse a string." << endl;
    cout << "2. Calculate a sum of integers." << endl;
    cout << "3. Calculate the triangular number of integer N." << endl;
    cout << "4. Quit program." << endl;
    selection = returnInt();

    while (!isInRange(selection, 1, 4))
    {
        cout << "Please enter an integer within range." << endl;
        selection = returnInt();
    }

    switch(selection)
    {
        case 1:
            mainMenu(selection);
            break;
        case 2:
            mainMenu(selection);
            break;
        case 3:
            mainMenu(selection);
            break;
        case 4:
            mainMenu(selection);
            break;
    }

    return 0;
}

int mainMenu(int choice)
{

    if (choice == 1)
    {
        cout << "Please enter the string you'd like to reverse!" << endl;
        string strInput;
        cout << ">> ";
        getline(cin, strInput);
        cout << "Your reversed string is " << endl;
        reverseString(strInput);
    }

    if (choice == 2)
    {
        cout << "Let's get a sum of an array." << endl;
        int size = 0;
        cout << "Please enter an integer for the size of your array." << endl;
        size = returnInt();
        while (!isInRange(size, 1, 100))
        {
            cout << "Please enter an integer with range." << endl;
            size = returnInt();
        }


        int arr[size];
        cout << "Please enter " << size << " numbers to fill the array." << endl;

        for (int i = 0; i < size; i++)
        {
            while (!arr[i])
            {
                arr[i] = returnInt();
            }
            cin >> arr[i];
        }

        int *arrPtr = &arr[size];

        cout << "Your array is: " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;



//        cout << "The sum of your array is: " << findSum(arrPtr, size) << endl;





    }
    if (choice == 3)
    {
        cout << "Please enter an integer, N, and I will calculate it's triangular number." << endl;
        int N = returnInt();
        while (!isInRange(N, 1, 500))
        {
            cout << "Please enter an integer between 1 and 500." << endl;
            N = returnInt();
        }
        cout << "The triangular number of N is: " << triangularNum(N) << endl;
    }
    if (choice == 4)
    {
        cout << "Thank you. Goodbye." << endl;
        return 0;
    }

    startMenu();
}

