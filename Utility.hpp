/********************************************************************* 
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This defines the interface for Utility, which holds
** enum ITEM and function headers.
*********************************************************************/ 
#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <climits>
#include <string>

enum ITEM { BLANKET, SQUID, UNICORN, WAGON3, BLOCK_A, BLOCK_B, BLOCK_C, HAT,
            SOCKS, MITTENS, KEY, OIL, WHEEL, BIB, DIAPER, BOTTLE, WAGON4,
            COOKIES, SQUEAKY, WAGON5, BLOCK3 };

std::string displayItemName(int val);

int getInt(int lowerLimit = INT_MIN, int upperLimit = INT_MAX);

char getYesOrNo();

#endif
