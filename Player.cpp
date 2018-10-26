/********************************************************************* 
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This implements the Player class which has a <list> of
** items, an item capacity, and flags to indicate which items were
** obtained.
*********************************************************************/ 
#include <iostream>
#include "Player.hpp"
#include "Utility.hpp"

/********************************************************************* 
** Description: This default constructor sets the player's stats to
** defaults.
*********************************************************************/ 
Player::Player()
{
    itemCount = 0;
    cap = 2;
    numBlocks = 0;
    hasWagon = hasWheel = hasOil = hasSqueaky = hasCookies = false;
    cap10Msg = oilMsg = wag5Msg = false;
}

int Player::getItemCount()
{
    return itemCount;
}

void Player::setCap(int cap)
{
    this->cap = cap;
}

int Player::getCap()
{
    return cap;
}

/********************************************************************* 
** Description: This function takes an int from the user's input and
** returns an int referring to the item.
*********************************************************************/ 
int Player::getItem(int index)
{
    std::list<int>::iterator it = items.begin();
    advance(it, index);
    return *it;
}

/********************************************************************* 
** Description: This function lists the items in the player's inventory.
*********************************************************************/ 
void Player::listItems()
{
    std::list<int>::iterator it = items.begin();
    for (int i = 0; it != items.end(); i++, it++)
    {
        std::cout << i+1 << ". " << displayItemName(*it) << std::endl;
    }
}

/********************************************************************* 
** Description: This function takes an int user input and bool referring
** to adding or removing and updates the user's inventory. Special
** items affect which flags are set to true/false.
*********************************************************************/ 
void Player::updateItems(int val, bool add)
{
    // Increment itemCount if not a wearable item and not wagon
    if (val != HAT && val != SOCKS && val != MITTENS && val != BIB &&
        val != WAGON3 && val != WAGON4 && val != WAGON5)
    {
        if (add)
        {
            // Wooden blocks count as 3 items
            if (val == BLOCK_A || val == BLOCK_B || val == BLOCK_C)
            {
                itemCount += 3;
            }
            else
            {
                itemCount++;
            }
        }
        else
        {
            // Wooden blocks count as 3 items
            if (val == BLOCK_A || val == BLOCK_B || val == BLOCK_C)
            {
                itemCount -= 3;
            }
            else
            {
                itemCount--;
            }
        }
    }

    // Update flags depending on possession of special items
    if (val == WAGON3)
    {
        if (add)
        {
            hasWagon = true;
            std::cout << "Inventory capacity increased to 5!" << std::endl;
            cap = 5;
        }
        else
        {
            hasWagon = false;
            cap = 2;
        }
    }
    else if (val == SQUEAKY)
    {
        if (add)
        {
            hasSqueaky = true;
        }
        else
        {
            hasSqueaky = false;
        }
    }
    else if (val == OIL)
    {
        if (add)
        {
            hasOil = true;
        }
        else
        {
            hasOil = false;
        }
    }
    else if (val == BLOCK_A || val == BLOCK_B || val == BLOCK_C)
    {
        if (add)
        {
            numBlocks++;
        }
        else
        {
            numBlocks--;
        }
        if (numBlocks == 3)
        {
            items.push_back(BLOCK3);
            items.remove(BLOCK_A);
            items.remove(BLOCK_B);
            items.remove(BLOCK_C);
        }
    }
    if (hasSqueaky && hasOil && !oilMsg)
    {
        items.remove(SQUEAKY);
        items.push_back(WHEEL);
        hasWheel = true;
        std::cout << "You oiled the squeaky wheel! No more squeaks!\n";
        oilMsg = true;
        updateItems(val, add);
        itemCount--;
    }
    if (hasSqueaky && hasWagon && !cap10Msg)
    {
        itemCount--;
        items.remove(SQUEAKY);
        items.remove(WAGON3);
        items.push_back(WAGON4);
        std::cout << "You put the wheel on the wagon." << std::endl;
        std::cout << "Inventory capacity increased to 10!" << std::endl;
        cap = 10;
        cap10Msg = true;
    }
    if (hasWheel && hasWagon && !wag5Msg)
    {
        items.remove(WAGON4);
        items.push_back(WAGON5);
        std::cout << "Your wagon is super silent." << std::endl;
        wag5Msg = true;
    }
}

void Player::setHasCookies(bool status)
{
    hasCookies = status;
}

bool Player::getHasCookies()
{
    return hasCookies;
}
