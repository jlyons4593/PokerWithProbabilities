#pragma once
#include <SFML/Graphics.hpp>
#include "UI.h"
class PokerHandUI : public UI
{
private:
	

	//  Startup Functions
	void initVariables();
	void initWindow();

	
	


public:

	bool isGameRunning;

	void update() override;
	void render() override;

	PokerHandUI();
	~PokerHandUI();
};

