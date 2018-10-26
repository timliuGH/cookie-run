/********************************************************************* 
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This defines the interface for the Bathroom class
** which inherits from Space.
*********************************************************************/ 
#ifndef BATHROOM_HPP
#define BATHROOM_HPP

#include "Space.hpp"

class Bathroom : public Space
{
    private:
    public:
        Bathroom();
        Bathroom(std::string name, int num);
};

#endif
