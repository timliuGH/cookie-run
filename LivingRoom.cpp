/********************************************************************* 
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This implements the LivingRoom class which inherits from 
** Space.
*********************************************************************/ 
#include "LivingRoom.hpp"

LivingRoom::LivingRoom()
{
}

LivingRoom::LivingRoom(std::string name, int num)
    : Space(name, num)
{
}
