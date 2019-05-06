/*********************************************************************
** Program name: Lab 5
** Author: Katie Stutts
** Date: 5/5/2019
** Description: Header file for input validation functions. Checks
if user input is a valid integer, and is a valid integer between a
given range.
*********************************************************************/
#ifndef GROUP_PROJECT_INPUTVALIDATION_HPP
#define GROUP_PROJECT_INPUTVALIDATION_HPP


#include <string>

int returnInt();
bool isInt (std::string input);
bool isInRange(int num, int min, int max);




#endif //GROUP_PROJECT_INPUTVALIDATION_HPP
