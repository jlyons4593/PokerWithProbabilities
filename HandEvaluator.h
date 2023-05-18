#ifndef HANDEVALUATOR_H
#define HANDEVALUATOR_H
#pragma once
#include <vector>
#include <algorithm>
#include "Deck.h"
#include <iostream>


namespace HandEvaluator {

    bool isFourOfAKind(const std::vector<Card>& playerCards, const std::vector<Card>& communityCards) {
        std::vector<Card> cards = playerCards;
        cards.insert(cards.end(), communityCards.begin(), communityCards.end());

        ////function to return card hand ranks
        auto compareByValue = [](const Card& a, const Card& b) {return a.value < b.value;};

        //// sort
        std::sort(cards.begin(), cards.end(), compareByValue);

        //// Check for four of a kind
        for (size_t i = 0; i <= cards.size() - 4; i++) {
            //compare all cards to cards next to it
            if (cards[i].value == cards[i + 1].value && cards[i + 1].value == cards[i + 2].value
                && cards[i + 2].value == cards[i + 3].value) {
                return true;
            }
        }

        return false;
    }

    bool isFullHouse(const std::vector<Card>& playerCards, const std::vector<Card>& communityCards) {

        std::vector<Card> cards = playerCards;
        cards.insert(cards.end(), communityCards.begin(), communityCards.end());

        // Check for full house
        std::map<CardValue, int> cardValueCount;

        // adding each card rank to map and
        // increasing the value everytime a new card is entered
        for (const auto& card : cards) {
            ++cardValueCount[card.value];
        }

        // map would look like
        //{2:0,3:1,4:3,2:3}
        // full house because 3 of one card 2 of another.

        bool hasThreeOfAKind = false;
        bool hasPair = false;
        for (const auto& [cardValue, count] : cardValueCount) {
            if (count == 3) {
                hasThreeOfAKind = true;
            }
            else if (count == 2) {
                hasPair = true;
            }
        }

        return hasThreeOfAKind && hasPair;
    }

    bool isFlush(const std::vector<Card>& playerCards, const std::vector<Card>& communityCards) {
        std::vector<Card> cards = playerCards;
        cards.insert(cards.end(), communityCards.begin(), communityCards.end());

        // Check for flush
        std::map<Suit, int> suitCount;
        // adding each card suit to map and
        // increasing the value everytime a new card is entered
        for (const auto& card : cards) {
            suitCount[card.suit]++;
        }
        // map would look like
        //{1:0,2:0,3:5,2:2}
        // full house because 3 of one card 2 of another.
        for (const auto& suit : suitCount) {
            if (suit.second >= 5) {

                return true;
            }
        }
        return false;
    }

    bool isStraight(const std::vector<Card>& playerCards, const std::vector<Card>& communityCards) {
        std::vector<Card> cards = playerCards;
        cards.insert(cards.end(), communityCards.begin(), communityCards.end());

        auto compareByValue = [](const Card& a, const Card& b) {
            return a.value < b.value;
        };

        //sort
        std::sort(cards.begin(), cards.end(), compareByValue);

        int count = 0;
        //looping and checking if any of the handranks come one
        //after another for 4 cards straight
        for (int i = 0; i < cards.size() - 1; i++) {
            if (int(cards[i + 1].value) - int(cards[i].value) == 1) {
                count++;
                if (count == 4) {
                    return true;
                }
            }
            else {
                count = 0;
            }
        }
        return false;
    }

    bool isThreeOfAKind(const std::vector<Card>& playerCards, const std::vector<Card>& communityCards) {
        std::vector<Card> cards = playerCards;
        cards.insert(cards.end(), communityCards.begin(), communityCards.end());

        auto compareByValue = [](const Card& a, const Card& b) {
            return a.value < b.value;
        };

        // Sort the cards
        std::sort(cards.begin(), cards.end(), compareByValue);

        // Check for three of a kind
        for (size_t i = 0; i <= cards.size() - 3; i++) {
            if (cards[i].value == cards[i + 1].value && cards[i + 1].value == cards[i + 2].value) {
                return true;
            }
        }

        return false;
    }

    bool isTwoPair(const std::vector<Card>& playerCards, const std::vector<Card>& communityCards) {
        std::vector<Card> cards = playerCards;
        cards.insert(cards.end(), communityCards.begin(), communityCards.end());

        auto compareByValue = [](const Card& a, const Card& b) {
            return a.value < b.value;
        };

        // Sort the cards
        std::sort(cards.begin(), cards.end(), compareByValue);

        int numPairs = 0;
        // Go through and check for pairs, once we find one pair we increment numPairs and check for the second
        CardValue firstPairValue = CardValue::Two;  // arbitrary initial value
        for (size_t i = 0; i < cards.size() - 1; i++) {
            if (cards[i].value == cards[i + 1].value) {
                if (numPairs == 0) {
                    firstPairValue = cards[i].value;
                    numPairs++;
                }
                else if (cards[i].value != firstPairValue) {
                    // Two pairs of different card values found
                    return true;
                }
                i++;  // Skip over second card in pair
            }
        }

        return false;
    }

    bool isPair(const std::vector<Card>& playerCards, const std::vector<Card>& communityCards) {
        std::vector<Card> cards = playerCards;
        cards.insert(cards.end(), communityCards.begin(), communityCards.end());

        auto compareByValue = [](const Card& a, const Card& b) {
            return a.value < b.value;
        };
        // Sort the cards
        std::sort(cards.begin(), cards.end(), compareByValue);

        // Check for a pair
        for (size_t i = 0; i <= cards.size() - 2; i++) {
            if (cards[i].value == cards[i + 1].value) {
                return true;
            }
        }

        return false;
    }

    bool isStraightFlush(const std::vector<Card>& playerCards, const std::vector<Card>& communityCards) {
        std::vector<Card> cards = playerCards;
        cards.insert(cards.end(), communityCards.begin(), communityCards.end());

        if (HandEvaluator::isStraight(playerCards, communityCards) && HandEvaluator::isFlush(playerCards, communityCards)) {
            return true;
        }
        return false;
    }
}
#endif //HANDEVALUATOR_H