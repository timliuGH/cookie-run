/********************************************************************* 
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This defines the Bathroom class which inherits from Space.
*********************************************************************/ 
#ifndef BEDROOM_HPP
#define BEDROOM_HPP

#include "Space.hpp"

class Bedroom : public Space
{
    private:
    public:
        Bedroom();
        Bedroom(std::string, int num);
};

#endif
