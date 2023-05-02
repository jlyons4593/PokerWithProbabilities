#ifndef IPOKERHANDUI_H
#define IPOKERHANDUI_H

#pragma once
#include "PokerHand.h"
#include "PokerHandUI.h"
class PokerHand;
class PokerHandUI;
class IPokerHandUI
{
public:
    // Public static method to get the instance of the IPokerHandUI
    static IPokerHandUI& getInstance();

    // Delete the copy constructor and the assignment operator
    IPokerHandUI(const IPokerHandUI&) = delete;
    IPokerHandUI& operator=(const IPokerHandUI&) = delete;

    // Public method to get a pointer to the PokerOfflineUi object
    PokerHandUI* getPokerHandUI() const;

    PokerHand* getPokerHand() const;

private:
    // Private constructor to prevent instantiation
    IPokerHandUI();

    // Private destructor to prevent deletion
    ~IPokerHandUI();

    // Private member variable to hold the pointer to the pokerHandUI object
    PokerHandUI* pokerHandUIInstance;

    // Private member variable to hold the pointer to the pokerHandUI object
    PokerHand* pokerHandInstance;
};
#endif // IPOKERHANDUI_H
