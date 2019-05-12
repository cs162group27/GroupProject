//
// Created by Patrick Oh on 2019-05-09.
//

// Prompts user to set up the Board.
void Board::extraCredit()
{
//    /* THIS IS A LOOP TO ACQUIRE THE NUMBER OF ROWS FOR THE BOARD
//    The bool dataGatherer is only used in all following loops to provide an
//    easy instance of true or false for the purposes of input validation. */
    while (dataGatherer == true)
    {
        cout << "Please choose the number of rows for your board." << endl;

        std::cin >> numRows;
        if (numRows > 0 && numRows <= 100)
        {
            setRows(numRows);
            dataGatherer = false;
        }
        else {
            cout << "That is not a valid input. Please try again." << endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
//    // THIS IS A LOOP TO ACQUIRE THE NUMBER OF COLUMNS FOR THE BOARD
    while (dataGatherer == false)
    {
        std::cout << "Please choose the number of columns for your board." << std::endl;
        std::cin >> numCols;
        if (numCols > 0 && numCols <= 100)
        {
            setCols(numCols);
            dataGatherer = true;
        }
        else {
            std::cout << "That is not a valid input. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
//    // THIS IS A LOOP TO GET THE NUMBER OF ANTS
    while (dataGatherer == true)
    {
        std::cout << "Please choose the number of ants for your board." << std::endl;
        std::cin >> numAnts;
        if (numAnts > 0 && (numAnts < numRows || numAnts < numCols))
        {
            setAnts(numAnts);
            dataGatherer = false;
        }
        else {
            std::cout << "That is way too many ants! Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
//    // THIS IS A LOOP TO GET THE NUMBER OF DOODLEBUGS
    while (dataGatherer == false)
    {
        std::cout << "Please choose the number of doodlebugs for your board." << std::endl;
        std::cin >> numDoodlebugs;
        if (numDoodlebugs > 0 && numDoodlebugs < numAnts)
        {
            setDoodlebugs(numDoodlebugs);
            dataGatherer = true;
        }
        else {
            std::cout << "That is way too many doodlebugs! Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
//    // THIS IS A LOOP TO GET THE NUMBER OF TIME STEPS
    while (dataGatherer == true)
    {
        std::cout << "Please choose the number of time steps you would like -- "
                     "e.g. 10, 100, 1000, 10000..." << std::endl;
        std::cin >> steps;

        if (steps > 0 && steps <= 15000)
        {
            dataGatherer = false;
        }
        else {
            std::cout << "That is not a valid input. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
}

// Runs the game. Displays the Board after each step.
void Board::run()
{
    for (int k = 0; k < steps; k++)
    {
        for (int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(board[i][j] != NULL)
                {
                    if (ant.getAge() > 3)
                    {
                        ant.breed();
                        ant.setAge(0);
                    }
                    if (doodlebug.getAge() > 8)
                    {
                        doodlebug.breed();
                        doodlebug.setAge(0);
                    }
                    if(checkOffGrid() && checkOccupied())
                    {
                        board[i][j]->move();
                        // move should be a function within Critter class, not Board
                    }
                    board[i][j]->incrementAge();
                    // increment age is a function within Critter class, not Board
                }
            }
        }
        display();
        cout << endl;
    }
}
