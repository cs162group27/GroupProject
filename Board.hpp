/*******************************************************************************
 ** Author:       Victoria Fisher
 ** Date:         5/12/2019
 ** Description:  Header file for Board.cpp.
 *******************************************************************************/

#ifndef Board_hpp
#define Board_hpp
#include "Critter.hpp"

class Board {
private:
    Critter *** board;
    int rows = 20, cols = 20, ants = 100, doodlebugs = 5, numRows, numCols, numAnts, numDoodlebugs,
    aRow, aCol, dRow, dCol, numSteps;
    int steps;
    char currentSpace = ' ';
    char antSpace = 'O';
    char doodlebugSpace = 'X';
    bool dataGatherer = true;
    
public:
    Board(int);
    int getRows();
    void setRows(int);
    int getCols();
    void setCols(int);
    int getAnts();
    void setAnts(int);
    int getSteps();
    void setSteps(int);
    int getDoodlebugs();
    void setDoodlebugs(int);
    void initialize();
    void display();
    void deleteBoard();
    void extraCredit();
    void run();
};
#endif /* Board_hpp */
