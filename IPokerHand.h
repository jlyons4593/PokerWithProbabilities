
#ifndef IPOKERHANDUI_H
#define IPOKERHANDUI_H

#pragma once
#include "PokerHand.h"
#include "PokerHandUI.h"
 
    class IPokerHand
    {
    public:
        // Public static method to get the instance of the IPokerHandUI
        static IPokerHand& getInstance();

        // Delete the copy constructor and the assignment operator
        IPokerHand(const IPokerHand&) = delete;
        IPokerHand& operator=(const IPokerHand&) = delete;

        // Public method to get a pointer to the PokerOfflineUi object
        PokerHand* getPokerHand() const;


    private:
        // Private constructor to prevent instantiation
        IPokerHand();

        // Private destructor to prevent deletion
        ~IPokerHand();


        // Private member variable to hold the pointer to the pokerHandUI object
        PokerHand* pokerHandInstance;
    };
#endif // IPOKERHANDUI_H



