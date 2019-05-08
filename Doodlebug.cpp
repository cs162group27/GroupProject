//
// Created by Patrick Oh on 2019-05-07.
//

#include "Doodlebug.hpp"
#include "Critter.hpp"

#include <random>

Doodlebug::Doodlebug():Critter(0, 'O')
{
    antsEaten = 0;
}

Doodlebug::Doodlebug(const Doodlebug &obj):Critter(obj.age, obj.ascii)
{
}

void Doodlebug::move(Critter ***grid, int gridX, int gridY, int numRows, int numCols)
{
    std::random_device seed;
    std::mt19937 gen(seed());

    int bugX = 0,
        bugY = 0,
        count1 = 0,
        count2 = 0,
        count3 = 0,
        count4 = 0;

    count1 = (checkAnt(gridX + 1, gridY, antCount));
    count2 = (checkAnt(gridX - 1, gridY, antCount));
    count3 = (checkAnt(gridX, gridY - 1, antCount));
    count4 = (checkAnt(gridX, gridY + 1, antCount));

    if(antCount > 1)
    {
        int chance = 0;

        std::uniform_int_distribution<> dis (1, antCount);

        chance = dis(gen);

        if(chance == count1)
        {
            eatAnt(gridX + 1, gridY);
            bugX = gridX + 1;
            bugY = gridY;
        }

        else if(chance == count2)
        {
            eatAnt(gridX - 1, gridY);
            bugX = gridX - 1;
            bugY = gridY;
        }

        else if(chance == count3)
        {
            eatAnt(gridX, gridY - 1);
            bugX = gridX;
            bugY = gridY - 1;
        }

        else if(chance == count4)
        {
            eatAnt(gridX, gridY + 1);
            bugX = gridX;
            bugY = gridY + 1;
        }
    }

    else if(antCount == 1)
    {
        if(checkAnt(gridX + 1, gridY))
        {
            eatAnt(gridX + 1, gridY);
            bugX = gridX + 1;
            bugY = gridY;
        }

        else if(checkAnt(gridX - 1, gridY))
        {
            eatAnt(gridX - 1, gridY);
            bugX = gridX - 1;
            bugY = gridY;
        }

        else if(checkAnt(gridX, gridY + 1))
        {
            eatAnt(gridX, gridY + 1);
            bugX = gridX;
            bugY = gridY + 1;
        }

        else if(checkAnt(gridX, gridY - 1))
        {
            eatAnt(gridX, gridY - 1);
            bugX = gridX;
            bugY = gridY - 1;
        }
    }

    else
    {
        int randNum = 0;

        std::uniform_int_distribution<> dis(1, 4);

        randNum = dis(gen);	// Assign generated random number to variable

        // Do not move Ant yet. Assign temporary variables and check
        // neighboring cells.
        // If 1 = East/Right
        if(randNum == 1)
        {
            bugX = gridX + 1;
            bugY = gridY;
        }
            // If 2 == South/Down
        else if(randNum == 2)
        {
            bugX = gridX;
            bugY = gridY + 1;
        }
            // If 3 == West/Left
        else if(randNum == 3)
        {
            bugX = gridX - 1;
            bugY = gridY;
        }
            // Else 4 == North/Up
        else
        {
            bugX = gridX;
            bugY = gridY - 1;
        }

        // Now, see if neighboring cell is occupied or off the grid
        bool full = 0;	// Variable to see if cell is occupied.
        bool offBounds = 0;	// Variable to see if cell is off grid.

        if(grid[bugX][bugY] == nullptr)
        {
            full = 0;
        }

        else
        {
            full = 1;
        }

        if(bugX >= numRows)
        {
            offBounds = 1;
        }

        else if(bugY >= numCols)
        {
            offBounds = 1;
        }

        else if(bugX < 0)
        {
            offBounds = 1;
        }

        else if(bugY < 0)
        {
            offBounds = 1;
        }

        else
        {
            offBounds = 0;
        }

        if(!full && !offBounds)
        {
            grid[bugX][bugY] = grid[gridX][gridY];

            grid[gridX][gridY] = nullptr;
        }
    }
}

void Doodlebug::breed(Critter ***grid, int gridX, int gridY, int numRows, int numCols)
{
    if(age > 8)
    {
        int randNum = 0,
            bugX = 0,
            bugY = 0,
            count = 0;

        std::random_device seed;
        std::mt19937 gen(seed());
        std::uniform_int_distribution<> dis(1, 4);

        do
        {
            randNum = dis(gen);

            if(randNum == 1)
            {
                bugX = gridX + 1;
                bugY = gridY;

                count++;
            }

            else if(randNum == 2)
            {
                bugX = gridX - 1;
                bugY = gridY;

                count++;
            }

            else if(randNum == 3)
            {
                bugX = gridX;
                bugY = gridY - 1;

                count++;
            }

            else if(randNum == 4)
            {
                bugX = gridX;
                bugY = gridY + 1;

                count++;
            }

            bool occupied = 0; // Variable to see if cell is occupied.
            bool offGrid = 0; // Variable to see if cell is off grid.

            // Check to see if neighboring cell is occupied
            // Is there no Ant or Doodlebug in coordinates?
            if(grid[tempX][tempY] == NULL)
            {
                occupied = 0;
            }
            else // There is an Ant or Doodlebug
            {
                occupied = 1;
            }

            // Check if neighboring cell is off the grid.
            // Moving clockwise
            // Are the coordinates at the East/Right edge of the grid?
            if(bugX >= numRows)
            {
                offGrid = 1;
            }
                // Are the coordinates at the South/Bottom edge of the grid?
            else if(bugY >= numCols)
            {
                offGrid = 1;
            }
                // Are the coordinates at the West/Left edge of the grid?
            else if(bugX < 0)
            {
                offGrid = 1;
            }
                // Are the coordinates the the North/Top edge of the grid?
            else if(bugY < 0)
            {
                offGrid = 1;
            }
                // Coordinates are within limits
            else
            {
                offGrid = 0;
            }

            //  If the loop has gone through all rand numbers and found no avail space
            if(count > 1)
            {
                // Reset temp variables
                bugX = gridX;
                bugY = gridY;
            }
        }while((occupied || offGrid) && (count < 1));

        if((bugX != gridX) || (bugY != gridY))
        {
            grid[bugX][bugY] = new Doodlebug;
        }
    }
}

int Doodlebug::checkAnt(int x, int y)
{
    if((grid[x][y] -> ascii) == 'O')
    {
        antCount++;
        return antCount;
    }
}

void Doodlebug::eatAnt(int x, int y)
{
    grid[x][y] = nullptr;

    antsEaten++;
}

void Doodlebug::survive(int x, int y)
{
    if(antsEaten == 0 && age == 3)
    {
        grid[x][y] = nullptr;
    }
}

