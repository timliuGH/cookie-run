/********************************************************************* 
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This implements functions located in Utility.hpp.
*********************************************************************/ 
#include <iostream>
#include "Utility.hpp"

/********************************************************************* 
** Description: This function takes an int referring to an item and
** returns the description/name of the item.
*********************************************************************/ 
std::string displayItemName(int val)
{
    std::string result;
    switch (val)
    {
        case 0:
            result = "Fuzzy blanket";
            break;
        case 1:
            result = "Sammy the squid made of yarn";
            break;
        case 2:
            result = "Fluffy the unicorn";
            break;
        case 3:
            result = "Wagon missing one wheel";
            break;
        case 4:
            result = "Wooden block";
            break;
        case 5:
            result = "Wooden block";
            break;
        case 6:
            result = "Wooden block";
            break;
        case 7:
            result = "Propellor hat";
            break;
        case 8:
            result = "Fuzzy socks";
            break;
        case 9:
            result = "Mittens";
            break;
        case 10:
            result = "Room key";
            break;
        case 11:
            result = "Baby oil";
            break;
        case 12:
            result = "Non-squeaky wagon wheel";
            break;
        case 13:
            result = "Bib";
            break;
        case 14:
            result = "Diaper";
            break;
        case 15:
            result = "Empty bottle of baby oil";
            break;
        case 16:
            result = "Squeaky wagon with 4 wheels";
            break;
        case 17:
            result = "Cookies";
            break;
        case 18:
            result = "Squeaky wagon wheel";
            break;
        case 19:
            result = "Silent wagon";
            break;
        case 20:
            result = "Stairway of blocks";
            break;
    }
    return result;
}

/********************************************************************* 
** Description: This function takes 2 ints as limits and prompts the
** user for an int between those limits with input validation.
*********************************************************************/ 
int getInt(int lowerLimit, int upperLimit)
{
    int value;
    std::cin >> value;
    while (value < lowerLimit || value > upperLimit || std::cin.fail() || 
           std::cin.get() != '\n')
    {
        if (lowerLimit == INT_MIN && upperLimit == INT_MAX)
        {
            std::cout << "Please enter a valid integer: ";
        }
        else if (lowerLimit == 1 && upperLimit == INT_MAX)
        {
            std::cout << "Please enter a positive integer: ";
        }
        else if (lowerLimit == INT_MIN && upperLimit == -1)
        {
            std::cout << "Please enter a negative integer: ";
        }
        else
        {
            std::cout << "Please enter an integer from " << lowerLimit << 
                    " to " << upperLimit << ": ";
        }
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cin >> value;
    }

    return value;
}

/********************************************************************* 
** Description: This function prompts the user for Y/y or N/n for 
** yes-no questions.
*********************************************************************/ 
char getYesOrNo()
{
    char result;
    std::cin >> result;
    while ( (toupper(result) != 'Y' && toupper(result) != 'N') ||
            std::cin.fail() || std::cin.get() != '\n' )
    {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Please select Y for Yes or N for No: ";
        std::cin >> result;
    }
    return result;
}
