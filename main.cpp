// PokerProbabilities.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"







 




void runGame()
{
    Game game;
    while (game.isGameRunning())
    {
        //Update
        game.update();

        //Render
        game.render();
    }
    
}





int main()
{
    runGame();
    
    return 0;
}
