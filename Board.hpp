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
    int steps;
    int antCount, doodlebugCount;
    char currentSpace = ' ';
    char antSpace = 'O';
    char doodlebugSpace = 'X';
    bool dataGatherer = true;
    
public:
	// Constructor with default values
    Board(int s=1, int r=20, int c=20, int a=100, int d=5);
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
    int getAntCount();
    void setAntCount(int);
    int getDoodlebugCount();
    void setDoodlebugCount(int);
    void initialize();
    void display();
    void deleteBoard();
    void extraCredit();
    void run();
};
#endif /* Board_hpp */
