////
//// Created by Patrick Oh on 2019-05-07.
////
//
//#include "Doodlebug.hpp"
//#include "Critter.hpp"
//#include <random>
//
//Doodlebug::Doodlebug(const Doodlebug &obj) : Critter(obj.age, obj.ascii)
//{
//
//}
//
//void Doodlebug::move()
//{
//    std::random_device seed;
//    std::mt19937 gen(seed());
//
//    int bugX = 0;
//    int bugY = 0;
//
//    checkAnt(xCoord + 1, yCoord);
//    checkAnt(xCoord - 1, yCoord);
//    checkAnt(xCoord, yCoord - 1);
//    checkAnt(xCoord, yCoord + 1);
//
//    if(antCount > 1)
//    {
//        int chance = 0;
//
//        std::uniform_int_distribution<> dis (1, antCount);
//
//        chance = dis(gen);
//
//        if(chance == (checkAnt(xCoord + 1, yCoord)))
//        {
//            eatAnt(xCoord + 1, yCoord);
//            bugX = xCoord + 1;
//            bugY = yCoord;
//        }
//
//        else if(chance == (checkAnt(xCoord - 1, yCoord)))
//        {
//            eatAnt(xCoord - 1, yCoord);
//            bugX = xCoord - 1;
//            bugY = yCoord;
//        }
//
//        else if(chance == (checkAnt(xCoord, yCoord + 1)))
//        {
//            eatAnt(xCoord, yCoord + 1);
//            bugX = xCoord;
//            bugY = yCoord + 1;
//        }
//
//        else if(chance == (checkAnt(xCoord, yCoord - 1)))
//        {
//            eatAnt(xCoord, yCoord - 1);
//            bugX = xCoord;
//            bugY = yCoord - 1;
//        }
//    }
//
//    else if(antCount == 1)
//    {
//        if(checkAnt(xCoord + 1, yCoord))
//        {
//            eatAnt(xCoord + 1, yCoord);
//            bugX = xCoord + 1;
//            bugY = yCoord;
//        }
//
//        else if(checkAnt(xCoord - 1, yCoord))
//        {
//            eatAnt(xCoord - 1, yCoord);
//            bugX = xCoord - 1;
//            bugY = yCoord;
//        }
//
//        else if(checkAnt(xCoord, yCoord + 1))
//        {
//            eatAnt(xCoord, yCoord + 1);
//            bugX = xCoord;
//            bugY = yCoord + 1;
//        }
//
//        else if(checkAnt(xCoord, yCoord - 1))
//        {
//            eatAnt(xCoord, yCoord - 1);
//            bugX = xCoord;
//            bugY = yCoord - 1;
//        }
//    }
//
//    else
//    {
//        int randNum = 0;
//
//        std::uniform_int_distribution<> dis(1, 4);
//
//        randNum = dis(gen);	// Assign generated random number to variable
//
//        // Do not move Ant yet. Assign temporary variables and check
//        // neighboring cells.
//        // If 1 = East/Right
//        if(randNum == 1)
//        {
//            bugX = xCoord + 1;
//            bugY = yCoord;
//        }
//            // If 2 == South/Down
//        else if(randNum == 2)
//        {
//            bugX = xCoord;
//            bugY = yCoord + 1;
//        }
//            // If 3 == West/Left
//        else if(randNum == 3)
//        {
//            bugX = xCoord - 1;
//            bugY = yCoord;
//        }
//            // Else 4 == North/Up
//        else
//        {
//            bugX = xCoord;
//            bugY = yCoord - 1;
//        }
//
//        // Now, see if neighboring cell is occupied or off the grid
//        bool full = 0;	// Variable to see if cell is occupied.
//        bool offBounds = 0;	// Variable to see if cell is off grid.
//
//        // Check if neighboring cell is occupied.
//        full = checkDoodle(bugX, bugY);
//
//        // Check if neighboring cell is off the grid.
//        offBounds = outBounds(bugX, bugY);
//
//        // Now see if we can move Ant
//        // If unable to move,
//        if(occupied || offGrid)
//        {
//            return;	// Ant stays in current cell
//        }
//        else 	// Else, able to move - so Move Ant
//        {
//            // First, assign pointer at new direction to the value
//            // of the pointer for the currect Ant position
//            grid[bugX][bugY] = *grid[xCoord][yCoord];
//
//            // Then assign current position pointer to NULL
//            grid[xCoord][yCoord] = NULL;
//        }
//    }
//
//    survive(bugX, bugY, antCount);
//
//}
//
//void Doodlebug::checkAnt(int x, int y)
//{
//    if((grid[x][y] -> ascii) == 'O')
//    {
//        antCount++;
//        return antCount;
//    }
//}
//
//bool Doodlebug::checkDoodle(int x, int y)
//{
//    if((grid[x][y] -> ascii) == 'X')
//    {
//        return 1;
//    }
//
//    else
//    {
//        return 0;
//    }
//}
//
//bool Doodlebug::outBounds(int x, int y)
//{
//    // Are coordinates off grid?
//    // Moving clockwise
//    // Are the coordinates at the East/Right edge of the grid?
//    if(x >= rowSize)
//    {
//        return 1;
//    }
//        // Are the coordinates at the South/Bottom edge of the grid?
//    else if(y >= columnSize)
//    {
//        return 1;
//    }
//        // Are the coordinates at the West/Left edge of the grid?
//    else if(x < 0)
//    {
//        return 1;
//    }
//        // Are the coordinates the the North/Top edge of the grid?
//    else if(y < 0)
//    {
//        return 1;
//    }
//}
//
//void Doodlebug::eatAnt(int x, int y)
//{
//    grid[x][y] = nullptr;
//}
//
//void Doodlebug::survive(int x, int y, int numAnt)
//{
//    if(numAnt == 0 && age == 3)
//    {
//        grid[x][y] = nullptr;
//    }
//}
//
