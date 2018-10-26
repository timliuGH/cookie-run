/********************************************************************* 
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This defines the Player class which has a <list> of
** items, an item capacity, and flags to indicate which items were
** obtained.
*********************************************************************/ 
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <list>

class Player
{
    private:
        int itemCount;
        int cap;
        int numBlocks;
        bool hasWagon;
        bool hasWheel;
        bool hasOil;
        bool hasSqueaky;
        bool hasCookies;
        bool cap10Msg;      // Flag for getting squeaky 4-wheeled wagon
        bool oilMsg;        // Flag for oiling squeaky wheel
        bool wag5Msg;       // Flag for getting oiled 4-wheeled wagon
    public:
        Player();
        int getItemCount();
        void setCap(int);
        int getCap();
        std::list<int> items;
        int getItem(int index);
        void listItems();
        void updateItems(int, bool);
        void setHasCookies(bool);
        bool getHasCookies();
};

#endif
