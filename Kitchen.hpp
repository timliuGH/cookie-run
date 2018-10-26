/********************************************************************* 
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This defines the Kitchen class which inherits from 
** Space.
*********************************************************************/ 
#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include "Space.hpp"

class Kitchen : public Space
{
    private:
    public:
        Kitchen();
        Kitchen(std::string, int num);
};

#endif
