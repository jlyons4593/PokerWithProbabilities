// PokerProbabilities.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"
#include "Deck.h"
#include "Poker.h"
#include "HandWonUI.h"
#include "AudioManager.h"
#include "PokerHandsUI.h"
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
//#include "PokerHand.h"





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
    // Poker poker;
    
}

//void runPokerHand() 
//{
//    
//    //  init Poker Hand
//    PokerHand pokerHand;
//    
//    //  loading the poker UI from the interface
//    pokerHand.loadUI();
//    
//   
//
//    
//
//}



int main()
{
    /*HandWonUI* display = new HandWonUI();
    while (display->isGameRunning) {
        display->update();
        display->render();

    }*/
    
    //std::cout << "game over sequence" << std::endl;
    runGame();
    //runPokerHand();



    //sf::SoundBuffer buffer;
    //if (!buffer.loadFromFile("resources/WinSound.ogg"))
    //{
    //    // error handling
    //}

    //// Create the audio device with a stereo channel configuration
    //sf::Sound sound;
    //sound.setBuffer(buffer);
    //sf::Sound::Status status = sound.getStatus();
    //if (status == sf::Sound::Stopped)
    //{
    //    sound.play();
    //}
   
    //AudioManager* audioManager = new AudioManager();
    //audioManager->playSound("dealCard1");
  
    //audioManager->playSound("youWin");
    
    return 0;
}

//#include <SFML/Graphics.hpp>
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Center Text Example");
//
//    sf::Font font;
//    sf::Text text;
//
//    // Load the default font by passing nullptr as the filename
//    font.loadFromFile("Fonts/Roboto-Black.ttf");
//
//    // Set the font and string for the text object
//    text.setFont(font);
//    text.setString("Hello, world!");
//    text.setCharacterSize(24);
//
//    // Set the origin to the center of the text
//    sf::FloatRect textRect = text.getLocalBounds();
//    text.setOrigin(textRect.left + textRect.width / 2.0f,
//        textRect.top + textRect.height / 2.0f);
//
//    // Position the text in the center of the screen
//    text.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear(sf::Color::Black);
//        window.draw(text);
//        window.display();
//    }
//
//    return 0;
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
