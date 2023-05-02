
#ifndef IPOKERHANDUI_CPP
#define IPOKERHANDUI_CPP
#include "IPokerHandUI.h"

IPokerHandUI::IPokerHandUI() {
    pokerHandUIInstance = new PokerHandUI();
    pokerHandInstance = new PokerHand();
}

IPokerHandUI::~IPokerHandUI() {
    delete pokerHandInstance;
    delete pokerHandUIInstance;
}

IPokerHandUI& IPokerHandUI::getInstance() {
    static IPokerHandUI instance;
    return instance;
}

PokerHandUI* IPokerHandUI::getPokerHandUI() const {
    return pokerHandUIInstance;
}
PokerHand* IPokerHandUI::getPokerHand() const {
    return pokerHandInstance;
}
#endif // IPOKERHANDUI_CPP