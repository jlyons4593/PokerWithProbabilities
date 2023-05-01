#pragma once

#include "PokerOfflineUi.h"

class PokerOfflineUiSingleton {
public:
    // Public static method to get the instance of the PokerOfflineUiSingleton
    static PokerOfflineUiSingleton& getInstance();

    // Delete the copy constructor and the assignment operator
    PokerOfflineUiSingleton(const PokerOfflineUiSingleton&) = delete;
    PokerOfflineUiSingleton& operator=(const PokerOfflineUiSingleton&) = delete;

    // Public method to get a pointer to the PokerOfflineUi object
    PokerOfflineUi* getPokerOfflineUi() const;

private:
    // Private constructor to prevent instantiation
    PokerOfflineUiSingleton();

    // Private destructor to prevent deletion
    ~PokerOfflineUiSingleton();

    // Private member variable to hold the pointer to the PokerOfflineUi object
    PokerOfflineUi* pokerOfflineUiInstance;
};