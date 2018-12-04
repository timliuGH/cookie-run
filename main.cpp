/********************************************************************* 
** Program name: Cookie_Run
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This program runs Cookie Run where the player must
** get items around a house to reach cookies on the kitchen counter
** before the babysitter wakes up.
*********************************************************************/ 
#include <cctype>
#include <iostream>
#include "Game.hpp"

int main()
{
    // For user input
    int start;
    char user;

    // Run game once and prompt for re-play
    do {
        Game game;
        std::cout << "Press 1 to Start or 2 to Exit" << std::endl;
        start = getInt(1, 2);
        if (start == 1) {
            game.clear();
            std::cout << "Here's a map that you drew.\n"
                      << "The o marks an entrance.\n"
                      << "The X is where you are." << std::endl;
            game.map();
            std::cout << "Press Enter to continue." << std::endl;
            std::cin.ignore();
            game.play();
            std::cout << "\nWould you like to play again? (y/n): ";
            user = getYesOrNo();
        } else {
            std::cout << "\nEnding program.." << std::endl;
            user = 'N';
        }
    } while (toupper(user) == 'Y');

    return 0;
}
