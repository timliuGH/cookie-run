/********************************************************************* 
** Author: Timothy Liu 
** Date: Mar 16, 2018
** Description: This implements the Game class which sets up the rooms of
** the house, tracks player's movements, and processes player's inputs.
** It also has a timer and a map for the game, and will print win/lose
** messages.
*********************************************************************/ 
#include <algorithm>
#include <cctype>
#include <iostream>
#include "Game.hpp"
#include "PointOfInterest.hpp"
#include "Utility.hpp"

/********************************************************************* 
** Description: This default constructor prints the introduction
** message, sets up the house rooms, connects the rooms, sets the
** player's location to starting room, and sets the timer to 25.
*********************************************************************/ 
Game::Game()
{
    clear();
    std::cout << "Welcome to Cookie Run!\n" << std::endl;
    std::cout << "You are a baby. The babysitter has just placed you in\n"
        << "your room for a nap, but you're not sleepy! You're hungry!\n"
        << "Hungry for cookies! You note the creaking wooden floor of\n"
        << "the living room as the sitter heads to the couch for a nap.\n"
        << "\nTime to start planning. You know the cookies are on the\n"
        << "kitchen counter, too high for you to reach.\n"
        << "Find items around the house to help you before the sitter\n"
        << "wakes up.\n\n"
        << "Every movement to another room is 1 time unit. Every act of \n"
        << "inspection is 1 time unit. You have 30 time units before \n"
        << "the babysitter wakes up.\n" << std::endl;


    // Create rooms
    playersRoom = new Bedroom("My room", 1);
    hallway = new Hallway("Hallway", 5);
    sistersRoom = new Bedroom("Little sister's room", 1);
    hallwayBath = new Bathroom("Hallway bathroom", 1);
    livingRoom = new LivingRoom("Living room", 2);
    parentsRoom = new Bedroom("Parents' room", 2);
    parentsBath = new Bathroom("Parents' bathroom", 1);
    kitchen = new Kitchen("Kitchen", 1);

    // Connect rooms
    playersRoom->top = hallway;
    hallway->top = hallwayBath;
    hallway->right = livingRoom;
    hallway->bottom2 = sistersRoom;
    hallway->bottom = playersRoom;
    hallway->left = parentsRoom;
    sistersRoom->top = hallway;
    hallwayBath->bottom = hallway;
    livingRoom->top = kitchen;
    livingRoom->left = hallway;
    kitchen->bottom = livingRoom;
    parentsRoom->right = parentsBath;
    parentsRoom->right2 = hallway;
    parentsBath->left = parentsRoom;

    // Set up Player's room with points of interest (POIs) and ITEMs
    Space* pCrib = new PointOfInterest("My crib");
    pCrib->addItem(BLANKET);
    pCrib->addItem(SQUID);
    pCrib->addItem(UNICORN);
    Space* pCloset = new PointOfInterest("My closet");
    pCloset->addItem(WAGON3);
    pCloset->addItem(BLOCK_A);
    Space* pDrawer = new PointOfInterest("My drawer");
    pDrawer->addItem(HAT);
    pDrawer->addItem(SOCKS);
    pDrawer->addItem(MITTENS);
    playersRoom->POI.push_back(pCrib);
    playersRoom->POI.push_back(pCloset);
    playersRoom->POI.push_back(pDrawer);

    // Set up hallway bathroom with POIs and ITEMs
    Space* hSink = new PointOfInterest("Sink");
    Space* hShower = new PointOfInterest("Shower");
    Space* hCabinet = new PointOfInterest("Cabinet under the sink");
    hCabinet->addItem(BOTTLE);
    hallwayBath->POI.push_back(hSink);
    hallwayBath->POI.push_back(hShower);
    hallwayBath->POI.push_back(hCabinet);

    // Set up hallway state
    hallway->setState(false);
    hallway->setSolution(WAGON4);
    hallway->setFailMsg("Your squeaky wagon woke up the babysitter!");

    // Set up living room with POIs and ITEMs and state
    livingRoom->setState(false);
    livingRoom->setSolution(SOCKS);
    livingRoom->setPassMsg(
            "Your fuzzy socks make you a silent ninja baby!\n"
            "The wooden floor does not creak.");
    livingRoom->setFailMsg(
       "Your bare feet on the squeaky wooden floor woke the babysitter!");
    Space* cat = new PointOfInterest("Cat with key ring", SQUID);
    cat->setPassMsg("You trade Sammy the squid for a key.");
    cat->setFailMsg(
         "The cat ignores you. Find some yarn to get its attention.");
    cat->addItem(KEY);
    Space* sitter = new PointOfInterest("Babysitter sleeping on couch");
    livingRoom->POI.push_back(cat);
    livingRoom->POI.push_back(sitter);

    // Set up kitchen with POIs and ITEMs and state
    Space* counter = new PointOfInterest("Kitchen counter", BLOCK3);
    counter->setPassMsg(
            "Your stairway of wooden blocks gets you to the cookies!");
    counter->setFailMsg(
        "You see the cookies way up on the counter. So close yet so far.");
    counter->addItem(COOKIES);
    kitchen->POI.push_back(counter);

    // Set up sister's room with POIs and ITEMs and state
    sistersRoom->setState(false);
    sistersRoom->setSolution(UNICORN);
    sistersRoom->setPassMsg(
                 "You give your little sister Fluffy the unicorn.\n"
                 "She lets you in her room.");
    sistersRoom->setFailMsg(
         "Your little sister wants a fluffy toy before she lets you in.");
    Space* sCrib = new PointOfInterest("Little sister's crib");
    sCrib->addItem(SQUEAKY);
    sCrib->addItem(BLOCK_B);
    Space* sDrawer = new PointOfInterest("Little sister's drawer");
    sDrawer->addItem(BIB);
    sDrawer->addItem(DIAPER);
    sistersRoom->POI.push_back(sCrib);
    sistersRoom->POI.push_back(sDrawer);

    // Set up parents' room with POIs and ITEMs and state
    parentsRoom->setState(false);
    parentsRoom->setSolution(KEY);
    parentsRoom->setFailMsg("The door is locked!");
    parentsRoom->setPassMsg("You open the door with the key.");
    Space* bed = new PointOfInterest("Parents' bed");
    Space* closet = new PointOfInterest("Parents' closet");
    closet->addItem(BLOCK_C);
    parentsRoom->POI.push_back(bed);
    parentsRoom->POI.push_back(closet);

    // Set up parents' bathroom with POIs and ITEMs
    Space* pSink = new PointOfInterest("Sink");
    Space* pShower = new PointOfInterest("Shower");
    Space* pCabinet = new PointOfInterest("Cabinet under the sink");
    pCabinet->addItem(OIL);
    parentsBath->POI.push_back(pSink);
    parentsBath->POI.push_back(pShower);
    parentsBath->POI.push_back(pCabinet);

    // Set player's starting location
    pLocation = playersRoom;

    timer = 30;
}

/********************************************************************* 
** Description: This destructor sets each Space's pointers to NULL,
** deletes each room pointed to by Space pointers, and sets each
** pointer to NULL.
*********************************************************************/ 
Game::~Game()
{
    empty(playersRoom);
    playersRoom->top = NULL;
    empty(hallway);
    hallway->top = NULL;
    hallway->right = NULL;
    hallway->bottom2 = NULL;
    hallway->bottom = NULL;
    hallway->left = NULL;
    empty(sistersRoom);
    sistersRoom->top = NULL;
    empty(hallwayBath);
    hallwayBath->bottom = NULL;
    empty(livingRoom);
    livingRoom->top = NULL;
    livingRoom->left = NULL;
    empty(kitchen);
    kitchen->bottom = NULL;
    empty(parentsRoom);
    parentsRoom->right = NULL;
    parentsRoom->right2 = NULL;
    empty(parentsBath);
    parentsBath->left = NULL;
    delete playersRoom;
    playersRoom = NULL;
    delete hallway;
    hallway = NULL;
    delete sistersRoom;
    sistersRoom = NULL;
    delete hallwayBath;
    hallwayBath = NULL;
    delete livingRoom;
    livingRoom = NULL;
    delete parentsRoom;
    parentsRoom = NULL;
    delete parentsBath;
    parentsBath = NULL;
    delete kitchen;
    kitchen = NULL;

    pLocation = NULL;
}

/********************************************************************* 
** Description: This function clears each room of Spaces that are in
** the Space pointer passed to the function.
*********************************************************************/ 
void Game::empty(Space* space)
{
    for (int i = 0, j = space->POI.size(); i < j; i++)
    {
        if (space->POI[i] != NULL)
        {
            delete space->POI[i];
            space->POI[i] = NULL;
        }
    }
}

/********************************************************************* 
** Description: This function runs the game until timer runs out or 
** cookies are obtained.
*********************************************************************/ 
void Game::play()
{
    clear();
    while (timer > 0 && player.getHasCookies() == false)
    {
        displayInitialOptions();
    }
    // Print game lost message if cookies were not obtained at end of timer
    if (player.getHasCookies() == false)
    {
        std::cout << "Game over. No cookies for you! Back to bed!" 
                  << std::endl;
    }
    // Print game won message once cookies are obtained
    else
    {
        std::cout << "Good work you little cookie monster!" << std::endl;
        std::cout << " ____     ____     ____\n"
            << "/  . \\   /.  .\\   / .  \\\n"
            << "|.  .|   |  . |   |.  .|\n"
            << "\\__._/   \\.__./   \\_.__/\n";
    }
}

/********************************************************************* 
** Description: This function displays the general game menu and 
** prompts the player to either inspect the area, move to another,
** or manage player's inventory.
*********************************************************************/ 
void Game::displayInitialOptions()
{
    // Display map of the room with player's current location
    map();
    std::cout << "Current location: " << pLocation->getName() << std::endl;
    std::cout << "Space available in inventory: "
              << player.getCap() - player.getItemCount() << std::endl;
    std::cout << "\nWhat would you like to do? (Select a number)\n";
    std::cout << "1. Inspect the area\n";
    std::cout << "2. Go to another area\n";
    std::cout << "3. Manage my inventory\n";
    
    int option = getInt(1, 3);
    switch (option)
    {
        case 1:
            clear();
            inspect();
            break;
        case 2:
            clear();
            map();
            movePlayer();
            break;
        case 3:
            // Check if player has items in inventory
            if (player.items.empty())
            {
                std::cout << "You're not carrying anything." << std::endl;
                std::cout << "Press Enter to continue." << std::endl;
                std::cin.ignore();
                clear();
            }
            else
            {
                clear();
                manageInventory();
            }
            break;
    }
}

/********************************************************************* 
** Description: This function is the first inspect function in a series
** of inspect functions. This one calls inspect0 if items were dropped
** in the current area and calls inspect2 otherwise.
*********************************************************************/ 
void Game::inspect()
{
    // Call inspect0 if items were previously dropped in current area
    if (pLocation->getNumItems() != 0)
    {
        inspect0();
    }

    // Check if area has any points of interest worth inspecting
    int max = pLocation->POI.size();
    if (max == 0)
    {
        std::cout << "\nNothing to inspect here." << std::endl;
        std::cout << "Press Enter to continue." << std::endl;
        std::cin.ignore();
        clear();
    }
    else
    {
        // List points of interest worth inspecting
        std::cout << "What would you like to inspect? (Select a number)\n";
        for (int i = 0; i < max; i++)
        {
            std::cout << i+1 << ". " << pLocation->POI[i]->getName() 
                << '\n';
        }
        // Print an additional Cancel option
        std::cout << (max + 1) << ". Cancel" << std::endl;

        int inspectThis = getInt(1, max + 1);
        if (inspectThis != max + 1)
        {
            // Call inspect2 to process user input
            inspect2(inspectThis - 1);
        }
        else
        {
            clear();
        }
    }
}

/********************************************************************* 
** Description: This function is called by inspect when player is 
** inspecting a room that previously had items dropped in it. The 
** function asks user if any of those items are now wanted.
*********************************************************************/ 
void Game::inspect0()
{
    std::cout << "You dropped stuff here earlier." << std::endl;
    std::cout << "Would you like to take anything? (Select a number)\n";
    int max;              // Holds max number of items available
    int choice;           // Holds user's selection
    int object;           // Holds converted object from choice
    ITEM eObject;         // Holds converted ITEM from object
    char user = 'Y';      // Holds user's yes or no response

    do
    {
        // List items that were dropped here earlier
        pLocation->listItems();

        // Add option to not take anything
        max = pLocation->getNumItems();
        std::cout << (max + 1) << ". Not now" << std::endl;

        // Prompt user for selection
        choice = getInt(1, max + 1);

        // If user did not select cancel
        if (choice != max + 1)
        {
            // Convert selection to item's int 
            object = pLocation->getItem(choice - 1);

            // Check if player has space for item
            if (haveSpace(choice, object))
            {
                // Convert selection to ITEM
                eObject = static_cast<ITEM>(object);

                // Remove from location and add to user's inventory
                pLocation->removeItem(eObject);
                player.items.push_back(object);
                player.updateItems(object, true);
            }
            else
            {
                std::cout << "You don't have enough space for that!" 
                          << std::endl;
                user = 'N';
                std::cout << "Press Enter to continue.";
                std::cin.ignore();
            }
            if (user != 'N')
            {
                // Check if location has any items left
                if (pLocation->getNumItems() == 0)
                {
                    std::cout << "No more items available." << std::endl;
                    std::cout << "Press Enter to continue." << std::endl;
                    std::cin.ignore();
                    user = 'N';
                    clear();
                }
                else
                {
                    std::cout << "Anything else? (y/n): ";
                    user = getYesOrNo();
                    clear();
                }
            }
        }
        else
        {
            user = 'N';
            clear();
        }
    }
    while (toupper(user) == 'Y');
}

/********************************************************************* 
** Description: This function is called by inspect if no items were
** previously dropped in the current area. It first checks if the area
** has a state that needs to be resolved first.
*********************************************************************/ 
void Game::inspect2(int val)
{
    if (pLocation->POI[val]->getState() == false)
    {
        // Check if player has ITEM that resolves the area's state
        std::list<int>::iterator it = 
                                 find(player.items.begin(), 
                                      player.items.end(),
                                      pLocation->POI[val]->getSolution());
        // Handles if player has the ITEM solution
        if (it != player.items.end())
        {
            // Print success message
            pLocation->POI[val]->printPassMsg();
            timer--;
            std::cout << "Press Enter to continue." << std::endl;
            std::cin.ignore();
            clear();

            // Remove item from player's inventory
            player.updateItems(*it, false);
            player.items.erase(it);

            // Handle if POI is cat
            if (pLocation->POI[val]->getName() == "Cat with key ring")
            {
                player.items.push_back(KEY);
                player.updateItems(KEY, true);
            }
            // Handle if POI is kitchen counter
            if (pLocation->POI[val]->getName() == "Kitchen counter")
            {
                player.setHasCookies(true);
            }
        }
        else
        {
            // Print fail message
            pLocation->POI[val]->printFailMsg();
            std::cout << "Press Enter to continue." << std::endl;
            std::cin.ignore();
            clear();
        }
    }
    // If no state to resolve and items are available, call inspect3
    else
    {
        if (pLocation->POI[val]->getNumItems() == 0)
        {
            std::cout << "\nNo items here." << std::endl;
            timer--;
            std::cout << "Press Enter to continue." << std::endl;
            std::cin.ignore();
            clear();
        }
        else
        {
            inspect3(val);
            timer--;
        }
    }
}

/********************************************************************* 
** Description: This function is called by inspect2 if the area's 
** state is resolved and there are items available for taking.
*********************************************************************/ 
void Game::inspect3(int val)
{
    int max;              // Holds max number of items available
    int choice;           // Holds user's selection
    int object;           // Holds converted object from choice
    ITEM eObject;         // Holds converted ITEM from object
    char user = 'Y';      // Holds user's yes or no response

    do
    {
        // List items available for taking
        std::cout << "What would you like to take? (Select a number)\n";
        pLocation->POI[val]->listItems();
        
        // Add option to not take anything
        int max = pLocation->POI[val]->getNumItems();
        std::cout << (max + 1) << ". Nothing" << std::endl;

        // Prompt user for selection
        choice = getInt(1, max + 1);

        // If user did not select cancel
        if (choice != max + 1)
        {
            // Convert selection to item's int 
            object = pLocation->POI[val]->getItem(choice - 1);

            // Check if player has space for item
            if (haveSpace(choice, object))
            {
                // Convert selection to ITEM
                eObject = static_cast<ITEM>(object);

                // Remove from location and add to user's inventory
                pLocation->POI[val]->removeItem(eObject);
                player.items.push_back(object);
                player.updateItems(object, true);
            }
            else
            {
                std::cout << "You don't have enough space for that!" 
                          << std::endl;
                std::cout << "Press Enter to continue.";
                std::cin.ignore();
                user = 'N';
                clear();
            }
            if (user != 'N')
            {
                // Check if location has any items left
                if (pLocation->POI[val]->getNumItems() == 0)
                {
                    std::cout << "No more items available." << std::endl;
                    std::cout << "Press Enter to continue." << std::endl;
                    std::cin.ignore();
                    user = 'N';
                    clear();
                }
                else
                {
                    std::cout << "Anything else? (y/n): ";
                    user = getYesOrNo();
                    clear();
                }
            }
        }
        else
        {
            user = 'N';
            clear();
        }
    }
    while (toupper(user) == 'Y');
}

/********************************************************************* 
** Description: This function moves the player to an available adjacent
** Space.
*********************************************************************/ 
void Game::movePlayer()
{
    // Used in case new Space has state that is unresolved and Player
    // cannot move there
    Space* temp = pLocation;

    std::cout << "\nWhere would you like to go? (Select a number)\n";
    pLocation->listConnectedSpaces();

    // Add Cancel option
    int max = pLocation->getNumNeighbors();
    std::cout << (max + 1) << ". Cancel" << std::endl;

    int moveTo = getInt(1, max + 1);

    // Check adjacent Spaces and count each Space that is not NULL until
    // matcher matches moveTo, then change pLocation to new Space
    int matcher = 0;
    bool found = false;
    while (!found)
    {
        // Handle if user chose to cancel
        if (moveTo == (max + 1))
        {
            found = true;
            clear();
        }
        if (pLocation->top != NULL)
        {
            matcher++;
            if (matcher == moveTo)
            {
                pLocation = pLocation->top;
                found = true;
            }
        }
        if (pLocation->right != NULL)
        {
            matcher++;
            if (matcher == moveTo)
            {
                pLocation = pLocation->right;
                found = true;
            }
        }
        if (pLocation->right2 != NULL)
        {
            matcher++;
            if (matcher == moveTo)
            {
                pLocation = pLocation->right2;
                found = true;
            }
        }
        if (pLocation->bottom2 != NULL)
        {
            matcher++;
            if (matcher == moveTo)
            {
                pLocation = pLocation->bottom2;
                found = true;
            }
        }
        if (pLocation->bottom != NULL)
        {
            matcher++;
            if (matcher == moveTo)
            {
                pLocation = pLocation->bottom;
                found = true;
            }
        }
        if (pLocation->left != NULL)
        {
            matcher++;
            if (matcher == moveTo)
            {
                pLocation = pLocation->left;
                found = true;
            }
        }
    }
    // Checks new area for state and if player has ITEM to resolve it
    if (pLocation->getState() == false)
    {
        std::list<int>::iterator it = find(player.items.begin(), 
                                           player.items.end(),
                                           pLocation->getSolution());
        // Handles if player has solution in inventory
        if (it != player.items.end())
        {
            // Handles if new area is the hallway
            if (pLocation->getName() == "Hallway")
            {
                pLocation->printFailMsg();
                std::cout << "Press Enter to continue." << std::endl;
                std::cin.ignore();
                clear();
                timer = 0;
            }
            else
            {
                pLocation->printPassMsg();
                std::cout << "Press Enter to continue." << std::endl;
                std::cin.ignore();
                clear();
                pLocation->setState(true);
                player.updateItems(*it, false);
                player.items.erase(it);
            }
        }
        // Handles if player does not have solution in inventory
        else
        {
            // Handles if new area is the hallway
            if (pLocation->getName() != "Hallway")
            {
                pLocation->printFailMsg();
                std::cout << "Press Enter to continue." << std::endl;
                std::cin.ignore();
                clear();
                if (pLocation->getName() == "Living room")
                {
                    timer = 0;
                }
                pLocation = temp;
            }
        }
    }
    // Count timer down 1 if player successfully moved locations
    if (pLocation != temp)
    {
        timer--;
        clear();
    }
    temp = NULL;
}

/********************************************************************* 
** Description: This function allows the player to drop items.
*********************************************************************/ 
void Game::manageInventory()
{
    // List items in player's inventory
    std::cout << "What would you like to drop? (Select a number)\n";
    player.listItems();

    // Add option to not drop anything
    int max = player.items.size();
    std::cout << (max + 1) << ". Nothing" << std::endl;

    int choice = getInt(1, max + 1);
    clear();
    while (choice != max + 1)
    {
        int object = player.getItem(choice - 1);
        ITEM eObject = static_cast<ITEM>(object);
        player.items.remove(eObject);
        player.updateItems(object, false);
        pLocation->addItem(eObject);
    
        std::cout << "Anything else? (Select a number)\n";
        player.listItems();

        // Add option to not take anything
        max = player.items.size();
        std::cout << (max + 1) << ". That's it" << std::endl;

        choice = getInt(1, max + 1);
        clear();
    }
}

/********************************************************************* 
** Description: This function checks to make sure the player has space
** to take an item.
*********************************************************************/ 
bool Game::haveSpace(int user, int obj)
{
    bool result = true;
    // Handles if item is a wooden block, which is size 3
    if (obj == BLOCK_A || obj == BLOCK_B || obj == BLOCK_C)
    {
        if (player.getCap() - player.getItemCount() < 3)
        {
            result = false;
        }
    }
    // Handles if item is wearable or wagon, which don't add to inventory
    else if ( (obj != HAT && obj != SOCKS && obj != MITTENS && 
               obj != BIB && obj != WAGON3 && obj != WAGON4 && 
               obj != WAGON5) )
    {
        if (player.getItemCount() >= player.getCap()) 
        {
            result = false;
        }
    }
    else if (obj == HAT || obj == SOCKS || obj == MITTENS || obj == BIB)
    {
        std::cout << "You put on " << displayItemName(obj) << ".\n";
        std::cout << "This does not count towards your inventory.\n";
    }
    return result;
}

/********************************************************************* 
** Description: This function "clears" the terminal screen by adding
** 100 newlines.
*********************************************************************/ 
void Game::clear()
{
    for (int i = 0; i < 100; i++)
    {
        std::cout << '\n';
    }
}

/********************************************************************* 
** Description: This function prints a map of the house indicating
** entrances and the player's current location.
*********************************************************************/ 
void Game::map()
{
    // 48 x 11 size house
    int cols = 48;
    int rows = 11;

    char array[rows][cols];
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            array[row][col] = ' ';
            if (row == 4 && col > 12)
            {
                array[row][col] = '-';
            }
            if (row == 6 && col > 12 && col <= 32)
            {
                array[row][col] = '-';
            }
            if (col == 12)
            {
                array[row][col] = '|';
            }
            if ((col == 22 || col == 32)&& (row < 4 || row > 6))
            {
                array[row][col] = '|';
            }
            if (row == 0 || row == rows - 1)
            {
                array[row][col] = '-';
            }
            else if (col == 0 || col == cols - 1)
            {
                array[row][col] = '|';
            }
        }
    }

    // Add entrances
    array[5][12] = array[2][12] = array[6][17] = array[6][27] = 'o';
    array[4][27] = array[5][32] = array[4][39] = 'o';

    // Add 'X' to mark player's current location
    if (pLocation->getName() == "My room")
    {
        array[8][17] = 'X';
    }
    else if (pLocation->getName() == "Little sister's room")
    {
        array[8][27] = 'X';
    }
    else if (pLocation->getName() == "Hallway")
    {
        array[5][22] = 'X';
    }
    else if (pLocation->getName() == "Parents' room")
    {
        array[5][6] = 'X';
    }
    else if (pLocation->getName() == "Parents' bathroom")
    {
        array[2][17] = 'X';
    }
    else if (pLocation->getName() == "Hallway bathroom")
    {
        array[2][27] = 'X';
    }
    else if (pLocation->getName() == "Living room")
    {
        array[7][39] = 'X';
    }
    else if (pLocation->getName() == "Kitchen")
    {
        array[2][39] = 'X';
    }

    // Print out the map
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            std::cout << array[row][col];
        }
        std::cout << std::endl;
    }
}
