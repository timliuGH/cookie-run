/********************************************************************* 
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This defines the interface for the Space abstract class
** which has pointers to adjacent spaces, a name, a <list> of items, 
** and a state/condition that needs to be resolved by the player using
** certain ITEMs defined in Utility.hpp.
*********************************************************************/ 
#ifndef SPACE_HPP
#define SPACE_HPP

#include <list>
#include <string>
#include <vector>
#include "Utility.hpp"

class Space
{
    protected:
        std::string name;
        int numNeighbors;
        std::list<int> items;
        bool state;
        ITEM solution;
        std::string passMsg;
        std::string failMsg;
    public:
        Space *top;
        Space *bottom;
        Space *bottom2;
        Space *left;
        Space *right;
        Space *right2;
        Space();
        Space(std::string);
        Space(std::string, int);
        Space(std::string, ITEM);
        virtual ~Space() = 0;
        std::string getName();
        int getNumNeighbors();
        void listConnectedSpaces();
        void addItem(ITEM);
        void removeItem(ITEM);
        int getItem(int index);
        void listItems();
        int getNumItems();
        std::vector<Space*> POI;    // Points Of Interest
        void setState(bool);
        bool getState();
        void setSolution(ITEM);
        int getSolution();
        void setPassMsg(std::string);
        void printPassMsg();
        void setFailMsg(std::string);
        void printFailMsg();
};

#endif
