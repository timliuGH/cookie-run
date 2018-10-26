/********************************************************************* 
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This defines the Hallway class which inherits from Space.
*********************************************************************/ 
#ifndef HALLWAY_HPP
#define HALLWAY_HPP

#include "Space.hpp"

class Hallway : public Space
{
    private:
    public:
        Hallway();
        Hallway(std::string, int num);
};

#endif
