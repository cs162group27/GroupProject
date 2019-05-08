//
// Created by Patrick Oh on 2019-05-07.
//

#ifndef DOODLE_BUG_DOODLEBUG_HPP
#define DOODLE_BUG_DOODLEBUG_HPP

#include "Critter.hpp"


class Doodlebug:public Critter
{
public:
    Doodlebug();
    Doodlebug(const Doodlebug&);
    virtual move(Critter***, int, int, int, int) override;
    virtual breed(Critter***, int, int, int, int) override;
    int checkAnt(int, int);
    void eatAnt(int, int);
    void survive(int, int);

private:
    int antCount = 0;
        antsEaten;
};


#endif //DOODLE_BUG_DOODLEBUG_H
