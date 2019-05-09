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
    int rows, cols, ants, doodlebugs, numRows, numCols, numAnts, numDoodlebugs,
    aRow, aCol, dRow, dCol, numSteps;
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