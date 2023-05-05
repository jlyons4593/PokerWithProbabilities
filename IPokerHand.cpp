#ifndef IPOKERHANDUI_CPP
#define IPOKERHANDUI_CPP
#include "IPokerHand.h"

IPokerHand::IPokerHand() 
{
    pokerHandInstance = new PokerHand();
}

IPokerHand::~IPokerHand() 
{
    delete pokerHandInstance;
}

IPokerHand& IPokerHand::getInstance() {
    static IPokerHand instance;
    return instance;
}

PokerHand* IPokerHand::getPokerHand() const 
{
    return pokerHandInstance;
}

#endif // IPOKERHANDUI_CPP