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
    void move(Critter***, int, int, int, int) override;
    void breed(Critter***, int, int, int, int) override;
    int checkAnt(Critter***, int, int) override;
    void eatAnt(Critter***, int, int);
    void survive(Critter***, int, int);

private:
    int antCount = 0,
        antsEaten;
};


#endif //DOODLE_BUG_DOODLEBUG_H
