/********************************************************************* 
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This implements the Hallway class which inherits from 
** Space.
*********************************************************************/ 
#include "Hallway.hpp"

Hallway::Hallway()
{
}

Hallway::Hallway(std::string name, int num)
    : Space(name, num)
{
}
