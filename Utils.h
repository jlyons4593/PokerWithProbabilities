#pragma once
enum class HandRank {
    HIGH_CARD = 0,
    ONE_PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH
};
enum class GameState {
    InitialState,
    Preflop,
    Flop,
    Turn,
    River,
    Showdown
};