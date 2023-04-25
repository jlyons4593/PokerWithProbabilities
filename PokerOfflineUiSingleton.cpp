#include "PokerOfflineUiSingleton.h"

PokerOfflineUiSingleton::PokerOfflineUiSingleton() {
    pokerOfflineUiInstance = new PokerOfflineUi();
}

PokerOfflineUiSingleton::~PokerOfflineUiSingleton() {
    delete pokerOfflineUiInstance;
}

PokerOfflineUiSingleton& PokerOfflineUiSingleton::getInstance() {
    static PokerOfflineUiSingleton instance;
    return instance;
}

PokerOfflineUi* PokerOfflineUiSingleton::getPokerOfflineUi() const {
    return pokerOfflineUiInstance;
}
