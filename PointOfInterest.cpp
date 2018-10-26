/********************************************************************* 
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This implements the PointOfInterest class which inherits 
** from Space.
*********************************************************************/ 
#include "PointOfInterest.hpp"

PointOfInterest::PointOfInterest(std::string name)
    : Space(name)
{
}

PointOfInterest::PointOfInterest(std::string name, ITEM solution)
    : Space(name, solution)
{
}
