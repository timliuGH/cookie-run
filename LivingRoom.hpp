/********************************************************************* 
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This defines the LivingRoom class which inherits from 
** Space.
*********************************************************************/ 
#ifndef LIVINGROOM_HPP
#define LIVINGROOM_HPP

#include "Space.hpp"

class LivingRoom : public Space
{
    private:
    public:
        LivingRoom();
        LivingRoom(std::string, int num);
};

#endif
