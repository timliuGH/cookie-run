/********************************************************************* 
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This defines the Game class which sets up the rooms of
** the house, tracks player's movements, and processes player's inputs.
** It also has a timer and a map for the game, and will print win/lose
** messages.
*********************************************************************/ 
#ifndef GAME_HPP
#define GAME_HPP

#include "Bathroom.hpp"
#include "Bedroom.hpp"
#include "Hallway.hpp"
#include "Kitchen.hpp"
#include "LivingRoom.hpp"
#include "Player.hpp"

class Game
{
    private:
        Space *playersRoom;
        Space *hallway;
        Space *sistersRoom;
        Space *hallwayBath;
        Space *livingRoom;
        Space *parentsRoom;
        Space *parentsBath;
        Space *kitchen;
        Player player;
        Space *pLocation;       // Current location of player
        int timer;
    public:
        Game();
        ~Game();
        void empty(Space*);
        void play();
        void displayInitialOptions();
        void inspect();
        void inspect0();
        void inspect2(int);
        void inspect3(int);
        void movePlayer();
        void manageInventory();
        bool haveSpace(int, int);
        void clear();
        void map();
};

#endif
