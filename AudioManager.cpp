#include "AudioManager.h"
#include <iostream>

AudioManager::AudioManager()
{
    // Load sound effects into memory
  

    m_soundBuffers["youWin"] = std::make_shared<sf::SoundBuffer>();
    if (!m_soundBuffers["youWin"]->loadFromFile("resources/WinSound.ogg")) 
    {
        std::cout << "Load failed" << std::endl;
        // Failed to load sound file
    }
    

    m_soundBuffers["youLose"] = std::make_shared<sf::SoundBuffer>();
    m_soundBuffers["youLose"]->loadFromFile("Resources/LoseSound.ogg");
    
    m_soundBuffers["dealCard1"] = std::make_shared<sf::SoundBuffer>();
    m_soundBuffers["dealCard1"]->loadFromFile("resources/cardSlide1.ogg");

    std::cout << "loading file" << std::endl;
    
    m_soundBuffers["dealCard2"] = std::make_shared<sf::SoundBuffer>();
    m_soundBuffers["dealCard2"]->loadFromFile("Resources/cardSlide2.ogg");

    m_soundBuffers["cardFan"] = std::make_shared<sf::SoundBuffer>();
    m_soundBuffers["cardFan"]->loadFromFile("Resources/cardFan1.ogg");
}

AudioManager::~AudioManager()
{
}

void AudioManager::playSound(const std::string& soundName)
{
    // Find the sound buffer corresponding to the sound name
    auto it = m_soundBuffers.find(soundName);
    if (it != m_soundBuffers.end())
    {
        std::cout << "playing sound" << std::endl;
        // Play the sound effect
        sf::Sound sound(*it->second);
        
        sound.play();
        sf::sleep(sf::milliseconds(500));
    }
}
