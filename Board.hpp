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
    extern Critter *** board;
    int rows, cols, ants, doodlebugs, numRows, numCols, numAnts, numDoodlebugs,
    aRow, aCol, dRow, dCol;
    char currentSpace = ' ';
    char antSpace = 'O';
    char doodlebugSpace = 'X';
    bool dataGatherer = true;
    
public:
    int getRows();
    void setRows(int);
    int getCols();
    void setCols(int);
    int getAnts();
    void setAnts(int);
    int getDoodlebugs();
    void setDoodlebugs(int);
    void initialize();
    void display();
    void deleteBoard();
    void extraCredit();
};
#endif /* Board_hpp */
