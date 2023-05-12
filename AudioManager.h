#pragma once
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <unordered_map>
class AudioManager
{
private:
	std::unordered_map<std::string, std::shared_ptr<sf::SoundBuffer>> m_soundBuffers;
public:
	AudioManager();
	~AudioManager();
	void playSound(const std::string& soundName);
   
       
   
};

