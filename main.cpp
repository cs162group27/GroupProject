/*******************************************************************************
 ** Author:       Victoria Fisher
 ** Date:         5/12/2019
 ** Description:  Runs Board setup.
 *******************************************************************************/

#include <iostream>
#include "Board.hpp"
Board bd;
int main() {
    bd.extraCredit();
    bd.initialize();
    bd.display();
    
    return 0;
}
