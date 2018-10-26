/********************************************************************* 
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This implements the Kitchen class which inherits from 
** Space.
*********************************************************************/ 
#include "Kitchen.hpp"

Kitchen::Kitchen()
{
}

Kitchen::Kitchen(std::string name, int num)
    : Space(name, num)
{
}
