//
// Created by Patrick Oh on 2019-05-07.
//

#ifndef DOODLE_BUG_DOODLEBUG_HPP
#define DOODLE_BUG_DOODLEBUG_HPP

#include "Critter.hpp"


class Doodlebug : public Critter
{
public:
    Doodlebug();
    Doodlebug(const Doodlebug&);
    virtual void move(Critter***, int, int, int, int) override;
    virtual void breed(Critter***, int, int, int, int) override;
    int checkAnt(int, int);
    void eatAnt(int, int);
    void survive(int, int);

private:
    int antCount, antsEaten = 0;
};


#endif //DOODLE_BUG_DOODLEBUG_H
