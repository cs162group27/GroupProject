/*********************************************************************
 ** Program name: Group Project
 ** Author: Group 27
 ** Date: 5/12/2019
 ** Description: This is the Doodlebug class specification file.
 **********************************************************************/

#ifndef DOODLE_BUG_DOODLEBUG_HPP
#define DOODLE_BUG_DOODLEBUG_HPP

#include "Critter.hpp"
class Board;

class Doodlebug: public Critter
{
private:
    int antCount = 0, antsEaten, starveCount;
public:
    // Constructor
    Doodlebug();
   
    // Copy Constructor
    Doodlebug(const Doodlebug&);

    bool move(Critter***, int, int, int, int) override;
    bool breed(Critter***, int, int, int, int) override;
    bool starve(Critter***, int, int) override;
    int checkAnt(Critter***, int, int); //override;
    void eatAnt(Critter***, int, int);
    void survive(Critter***, int, int);
    bool isOffGrid(int x, int y, int numRows, int numCols);
    bool isAnt(Critter***, int x, int y);
    bool isOccupied(Critter***, int x, int y);
    void incrementAntsEaten() override;
};

#endif //DOODLE_BUG_DOODLEBUG_H
