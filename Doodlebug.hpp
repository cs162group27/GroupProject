//
// Created by Patrick Oh on 2019-05-07.
//

#ifndef DOODLE_BUG_DOODLEBUG_HPP
#define DOODLE_BUG_DOODLEBUG_HPP

#include "Critter.hpp"


class Doodlebug:public Critter
{
public:
    Doodlebug(const Doodlebug&);
    virtual move();
    bool checkFull(int, int);
    bool outBounds(int, int);
    void eatAnt(int, int);
    void survive(int, int, int);

private:
    int antCount = 0;

};


#endif //DOODLE_BUG_DOODLEBUG_H
