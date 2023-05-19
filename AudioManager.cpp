#pragma once
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <unordered_map>
#include <memory>

class AudioManager
{
private:
    std::unordered_map<std::string, std::shared_ptr<sf::SoundBuffer>> m_soundBuffers;

    AudioManager() // Private constructor
    {
        volume = 10;
        // Load sound effects into memory
        m_soundBuffers["youWin"] = std::make_shared<sf::SoundBuffer>();
        if (!m_soundBuffers["youWin"]->loadFromFile("resources/WinSound.ogg"))
        {
            std::cout << "Load failed" << std::endl;
            // Failed to load sound file
        }

        m_soundBuffers["youLose"] = std::make_shared<sf::SoundBuffer>();
        m_soundBuffers["youLose"]->loadFromFile("resources/LoseSound.ogg");

        m_soundBuffers["dealCard1"] = std::make_shared<sf::SoundBuffer>();
        m_soundBuffers["dealCard1"]->loadFromFile("resources/cardSlide1.ogg");

        std::cout << "loading file" << std::endl;

        m_soundBuffers["dealCard2"] = std::make_shared<sf::SoundBuffer>();
        m_soundBuffers["dealCard2"]->loadFromFile("resources/cardSlide2.ogg");

        m_soundBuffers["menuNoise"] = std::make_shared<sf::SoundBuffer>();
        m_soundBuffers["menuNoise"]->loadFromFile("resources/chipsHandle1.ogg");

        //m_soundBuffers["cardFan"] = std::make_shared<sf::SoundBuffer>();
        //m_soundBuffers["cardFan"]->loadFromFile("resources/cardFan1.ogg");
    }

public:
    static AudioManager& getInstance()
    {
        static AudioManager instance;
        return instance;
    }
    
    AudioManager(AudioManager const&) = delete; // Delete copy constructor
    void operator=(AudioManager const&) = delete; // Delete assignment operator

    ~AudioManager() {}

    int volume = 100;

    void setVolume(int newVolume) {
        volume = newVolume*10;
    }

    void playSound(const std::string& soundName)
    {
        // Find the sound buffer corresponding to the sound name
        auto it = m_soundBuffers.find(soundName);
        if (it != m_soundBuffers.end())
        {
            std::cout << "playing sound" << std::endl;
            // Play the sound effect
            sf::Sound sound(*it->second);
            sound.setVolume(volume);

            sound.play();
            sf::sleep(sf::milliseconds(500));
        }
    }
    void playMenuNoise() 
    {
        auto it = m_soundBuffers.find("menuNoise");
        if (it != m_soundBuffers.end())
        {
       
            // Play the sound effect
            sf::Sound sound(*it->second);
            sound.setVolume(volume);

            sound.play();
            sf::sleep(sf::milliseconds(200));
        }
    }
};

