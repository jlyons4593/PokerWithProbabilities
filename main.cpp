// PokerProbabilities.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"




// Initialise the game engine

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
//#include <SFML/Graphics.hpp>
//
//void handleEvents(sf::RenderWindow& window)
//{
//    sf::Event event;
//    while (window.pollEvent(event))
//    {
//        if (event.type == sf::Event::Closed)
//            window.close();
//    }
//}
//
//void drawMenu(sf::RenderWindow& window)
//{
//    sf::Font font;
//    if (!font.loadFromFile("Fonts/Roboto-Black.ttf"))
//    {
//        // error handling
//    }
//
//    sf::Text text("Game Menu", font, 50);
//    text.setFillColor(sf::Color::White);
//    text.setPosition(100, 100);
//
//    window.draw(text);
//}
//
//void runGame()
//{
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Game Menu");
//
//    while (window.isOpen())
//    {
//        handleEvents(window);
//        window.clear(sf::Color::Black);
//        drawMenu(window);
//        window.display();
//    }
//}

int main()
{
    runGame();
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
