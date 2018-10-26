/********************************************************************* 
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This defines the PointOfInterest class which inherits from 
** Space.
*********************************************************************/ 
#ifndef POINTOFINTEREST_HPP
#define POINTOFINTEREST_HPP

#include "Space.hpp"

class PointOfInterest : public Space
{
    private:
    public:
        PointOfInterest(std::string);
        PointOfInterest(std::string, ITEM);
};

#endif
