
#ifndef IPOKERHANDUI_CPP
#define IPOKERHANDUI_CPP
#include "IPokerHandUI.h"

IPokerHandUI::IPokerHandUI() {
    pokerHandUIInstance = new PokerHandUI();
}

IPokerHandUI::~IPokerHandUI() {
  
    delete pokerHandUIInstance;
}

IPokerHandUI& IPokerHandUI::getInstance() {
    static IPokerHandUI instance;
    return instance;
}

PokerHandUI* IPokerHandUI::getPokerHandUI() const {
    return pokerHandUIInstance;
}

#endif // IPOKERHANDUI_CPP