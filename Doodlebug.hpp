//
// Created by Patrick Oh on 2019-05-07.
//

#ifndef DOODLE_BUG_DOODLEBUG_HPP
#define DOODLE_BUG_DOODLEBUG_HPP

#include "Critter.hpp"
class Board;


class Doodlebug:public Critter
{
public:
    Doodlebug();
    Doodlebug(const Doodlebug&);
//    void move(int &tempI, int &tempJ);
    bool move(Critter***, int, int, int, int) override;
    bool breed(Critter***, int, int, int, int) override;
    int checkAnt(Critter***, int, int); //override;
    void eatAnt(Critter***, int, int);
    void survive(Critter***, int, int);
    bool isOffGrid(int x, int y, int numRows, int numCols);
    bool isAnt(Critter***, int x, int y);
    bool isOccupied(Critter***, int x, int y);
    void incrementAntsEaten() override;
private:
    int antCount = 0,
        antsEaten,
        starveCount;
};


#endif //DOODLE_BUG_DOODLEBUG_H
