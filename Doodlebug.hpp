#ifndef DOODLE_BUG_DOODLEBUG_HPP
#define DOODLE_BUG_DOODLEBUG_HPP

#include "Critter.hpp"


class Doodlebug : public Critter
{
public:
    Doodlebug();
    Doodlebug(const Doodlebug &obj);
    virtual void move();
    bool checkFull(int, int);
    bool checkDoodle(int, int);
    bool checkAnt(int, int);
    bool outBounds(int, int);
    void eatAnt(int, int);
    void survive(int, int, int);

private:
    int antCount = 0;

};


#endif //DOODLE_BUG_DOODLEBUG_H
