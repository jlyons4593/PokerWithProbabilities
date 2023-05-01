#include "pokerHand.h"

void PokerHand::initVariables()
{
    
    /*this->moneyPerPlayer = 1500;
    this->blindCounter = 0;
    this->playersAreReady = false;
    this->m_numOfPlayers = 4;
    this->m_currentDeck.shuffleDeck();*/
}

void PokerHand::loadUI()
{
    PokerHandUI ui;
    while (ui.isGameRunning) {

        ui.update();

        ui.render();
    }
}

void PokerHand::beginGame()
{
}

PokerHand::PokerHand()
{

}

PokerHand::~PokerHand()
{

}
