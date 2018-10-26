/********************************************************************* 
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This implements the Bathroom class which inherits from 
** Space.
*********************************************************************/ 
#include "Bedroom.hpp"

Bedroom::Bedroom()
{
}

Bedroom::Bedroom(std::string name, int num)
    : Space(name, num)
{
}
