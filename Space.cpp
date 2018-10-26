/********************************************************************* 
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This implements the Space abstract class which has 
** pointers to adjacent spaces, a name, a <list> of items, and a 
** state/condition that needs to be resolved by the player using
** certain ITEMs defined in Utility.hpp.
*********************************************************************/ 
#include <iostream>
#include "Space.hpp"
#include "Utility.hpp"

/********************************************************************* 
** Description: This default constructor sets the Space pointers to
** NULL and the state to true.
*********************************************************************/ 
Space::Space()
{
    top = NULL;
    bottom = NULL;
    bottom2 = NULL;
    left = NULL;
    right = NULL;
    right2 = NULL;
    state = true;
}

/********************************************************************* 
** Description: This constructor takes a name and sets the Space
** pointers to NULL, sets the name, and sets the state to true.
*********************************************************************/ 
Space::Space(std::string name)
{
    top = NULL;
    bottom = NULL;
    bottom2 = NULL;
    left = NULL;
    right = NULL;
    right2 = NULL;
    this->name = name;
    state = true;
}

/********************************************************************* 
** Description: This constructor takes a string and an int and sets the
** Space pointers to NULL, sets the name and numNeighbors, and sets
** the state to true.
*********************************************************************/ 
Space::Space(std::string name, int num)
{
    top = NULL;
    bottom = NULL;
    bottom2 = NULL;
    left = NULL;
    right = NULL;
    right2 = NULL;
    this->name = name;
    numNeighbors = num;
    state = true;
}

/********************************************************************* 
** Description: This constructor takes a string and an ITEM and sets
** the Space pointers to NULL, sets the name, sets the state to false,
** and sets the solution to make the state true.
*********************************************************************/ 
Space::Space(std::string name, ITEM solution)
{
    top = NULL;
    bottom = NULL;
    bottom2 = NULL;
    left = NULL;
    right = NULL;
    right2 = NULL;
    this->name = name;
    this->solution = solution;
    state = false;
}

/********************************************************************* 
** Description: The destructor is made virtual void to make the class
** abstract.
*********************************************************************/ 
Space::~Space()
{
}

std::string Space::getName()
{
    return name;
}

int Space::getNumNeighbors()
{
    return numNeighbors;
}

/********************************************************************* 
** Description: This function lists all spaces that are connected to 
** the current player's space.
*********************************************************************/ 
void Space::listConnectedSpaces()
{
    // The counter is used to number the spaces for user input purposes
    int counter = 0;
    if (top != NULL)
    {
        counter++;
        std::cout << counter << ". " << top->getName() << std::endl;
    }
    if (right != NULL)
    {
        counter++;
        std::cout << counter << ". " << right->getName() << std::endl;
    }
    if (right2 != NULL)
    {
        counter++;
        std::cout << counter << ". " << right2->getName() << std::endl;
    }
    if (bottom2 != NULL)
    {
        counter++;
        std::cout << counter << ". " << bottom2->getName() << std::endl;
    }
    if (bottom != NULL)
    {
        counter++;
        std::cout << counter << ". " << bottom->getName() << std::endl;
    }
    if (left != NULL)
    {
        counter++;
        std::cout << counter << ". " << left->getName() << std::endl;
    }
}

/********************************************************************* 
** Description: This function takes an ITEM and adds it to the Space's
** <list> of items.
*********************************************************************/ 
void Space::addItem(ITEM val)
{
    items.push_back(val);
}

/********************************************************************* 
** Description: This function takes an int from user input and returns
** an int that refers to the item chosen by the user.
*********************************************************************/ 
int Space::getItem(int index)
{
    // Use an iterator to return the item in <list>
    std::list<int>::iterator it = items.begin();
    advance(it, index);
    return *it;
}

/********************************************************************* 
** Description: This function takes an ITEM and removes it from the
** Space's <list> of items.
*********************************************************************/ 
void Space::removeItem(ITEM val)
{
    items.remove(val);
    //std::list<int>::iterator it = items.begin();
    //advance(it, val - 1);
    //items.erase(it);
}

/********************************************************************* 
** Description: This function lists the items available in the Space.
*********************************************************************/ 
void Space::listItems()
{
    if (!items.empty())
    {
        std::list<int>::iterator it = items.begin(); 
        for (int i = 0; it != items.end(); i++, it++)
        {
            std::cout << i+1 << ". " << displayItemName(*it) << std::endl;
        }
    }
}

int Space::getNumItems()
{
    return items.size();
}

void Space::setState(bool state)
{
    this->state = state;
}

bool Space::getState()
{
    return state;
}

void Space::setSolution(ITEM solution)
{
    this->solution = solution;
}

int Space::getSolution()
{
    return static_cast<int>(solution);
}

void Space::setPassMsg(std::string msg)
{
    passMsg = msg;
}

void Space::printPassMsg()
{
    std::cout << '\n' << passMsg << '\n' << std::endl;
}

void Space::setFailMsg(std::string msg)
{
    failMsg = msg;
}

void Space::printFailMsg()
{
    std::cout << '\n' << failMsg << '\n' << std::endl;
}
