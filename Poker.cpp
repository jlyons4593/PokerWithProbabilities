#include "Poker.h"
#include "PlayerBase.h"
#include "AI.h"
#include "HandWonUI.h"
#include "HandLostUI.h"
#include "Strategy.h"
#include "SimpleStrategies.h"
#include <algorithm>
#include <thread>

#include <chrono>
#include <iostream>


void Poker::initializeVariables()
{
    

   
    this->blindCounter=0;
    this->playersAreReady = false;
    this->m_numOfPlayers = 3;
    this->currentBetAmount = 0;
    this->m_currentDeck.shuffleDeck();

    this->currentState = GameState::GameStart;
   

}
void Poker::setCommunityCards()
{
    this->communityCard1 = this->m_currentDeck.drawCard();
    this->communityCards.push_back(this->communityCard1);
    this->communityCard2 = this->m_currentDeck.drawCard();
    this->communityCards.push_back(this->communityCard2);
    this->communityCard3 = this->m_currentDeck.drawCard();
    this->communityCards.push_back(this->communityCard3);
    this->communityCard4 = this->m_currentDeck.drawCard();
    this->communityCards.push_back(this->communityCard4);
    this->communityCard5 = this->m_currentDeck.drawCard();
    this->communityCards.push_back(this->communityCard5);
}

void Poker::initializePlayers(){
    
    // create player objects and add them to the players vector
    std::cout<<"here"<<std::endl;
    Player* player = new Player();
    player->setPlayer();
    player->setName("Guest");
    player->playerIndex=0;
    
    this->players.push_back(player);
 
    // std::unique_ptr<Strategy> myStrategy = std::make_unique<RandomStrategy>();
    // AI myAI(std::move(myStrategy));
    // this->players.push_back(&myAI);
    
    for (int i = 0; i < this->m_numOfPlayers; i++)
    {
        std::cout<<i<<std::endl;

        if( i ==0){
            
            this->players.push_back(new AI(new HandStrengthStrategy));
            
        }
        else{
            this->players.push_back(new AI(new RandomStrategy));
        }
        this->players[i + 1]->setName("AI" + std::to_string(i+1));
        this->players[i + 1]->playerIndex = i + 1;


    }
    std::cout<<this->playersInHand.size()<<std::endl;
    this->playersInHand = this->players;
    std::cout<<this->players.size()<<std::endl;
}

void Poker::setPlayerCards()
{
    std::vector<Card> cards;
    for(int i=0; i<this->playersInHand.size(); i++)
    {

        Card test1 = this->m_currentDeck.drawCard();
        
        // std::cout<<std::to_string((int)test1.value)<<std::endl;
        cards.push_back(test1);

        Card test2 = this->m_currentDeck.drawCard();
        // std::cout<<std::to_string((int)test2.value)<<std::endl;
        cards.push_back(test2);
        std::cout<<(int)cards[0].value << " " <<(int)cards[1].value << " player "<< i << std::endl;
        this->players[i]->setCards(cards);
        if ( this->players[i]->getName()=="Guest"){
         
            this->notifyUpdatePlayersCards(cards);
            
        }
        cards.clear();
    }


    
} 


void Poker::setChips(int chips) {
    this->chipsPerPlayer = chips;
}

void Poker::setPlayerBlinds()
{
    
    bool bigBlindPaid = false;
    bool smallBlindPaid = false;
    
    //setting correct player indexes
    int bigBlindPlayerIndex = this->blindCounter%this->playersInHand.size();
    int smallBlindPlayerIndex = bigBlindPlayerIndex+1;

    //adjusting small player index to be 0 if its bigger than the number of players in the hand
    if (smallBlindPlayerIndex == this->playersInHand.size()) smallBlindPlayerIndex=0;

    bigBlindPaid = this->players[bigBlindPlayerIndex]->payBlind(25);
    if (bigBlindPaid)std::cout<<this->players[bigBlindPlayerIndex]<<" has paid blind";

    smallBlindPaid = this->players[smallBlindPlayerIndex]->payBlind(10);
    if (smallBlindPaid)std::cout<<this->players[smallBlindPlayerIndex]<<" has paid blind";

    
    if (bigBlindPaid&&smallBlindPaid) 
    {
        this->blindCounter++;
        return;
    }

    if(!bigBlindPaid || !smallBlindPaid)
    {
        this->removePlayerFromHand(this->players[smallBlindPlayerIndex]);
        this->setPlayerBlinds();
    }
}

void Poker::removePlayerFromHand(PlayerBase* player)
{
    std::cout<<"Player "<<player->getName()<< " is bankrupt"<< std::endl;
    this->playersInHand.erase(std::remove(this->playersInHand.begin(), this->playersInHand.end(), player), this->playersInHand.end());
}

void Poker::hand(){
    
    
        this->playersAreReady = false;
        while (!this->playersAreReady)
        {
            std::cout<< "beginning of betting round"<< std::endl;
            for (int j=0; j<this->playersInHand.size(); j++){
                std::vector<Card> cards=this->players[j]->getCards();
                // std::cout << std::to_string((int)cards[0].value)<<" "<< std::to_string((int)cards[1].value)<< std::endl;
                
                // int decision = this->players[j]->makeDecision();
                // if (decision == 1)
                // {
                //     int chipsBet = players[j]->getChipsToBet();
                //     this->pot = this->pot + chipsBet;

                // }
                // else if (decision == 2){
                //     this->removePlayerFromHand(this->playersInHand[j]);
                //     std::cout <<"player "<< this->playersInHand[j]->getName() << " has folded" <<std::endl;
                // }
            }
            this->playersAreReady = true;
        }
    std::cout << "The pot = " << this->pot<< std::endl;
        
    

    std::cout<< "entering determined hand winners"<< std::endl;

    std::vector<PlayerBase*> winners = this->determineHandWinner();

    for (auto& winner : winners){
        std::cout<< "winner = " << winner->getName() << std::endl;
    }
    

        
}

// Hand Ranks
bool Poker::isStraightFlush(PlayerBase *player){
    std::vector<Card> cards = player->getCards();
    cards.insert(cards.end(), this->communityCards.begin(), this->communityCards.end());

    if (isStraight(player) && isFlush(player)) {
        return true;
    }
    return false;

}

bool Poker::isFourOfAKind(PlayerBase *player){

    std::vector<Card> cards = player->getCards();
    cards.insert(cards.end(), this->communityCards.begin(), this->communityCards.end());
    
    //function to return card hand ranks
    auto compareByValue = [](const Card& a, const Card& b) {return a.value < b.value;};

    // sort
    std::sort(cards.begin(), cards.end(), compareByValue);

    // Check for four of a kind
    for (size_t i = 0; i <= cards.size() - 4; i++) {
        //compare all cards to cards next to it
        if (cards[i].value == cards[i+1].value && cards[i+1].value == cards[i+2].value
            && cards[i+2].value == cards[i+3].value) {
            return true;
        }
    }

    return false;
}

bool Poker::isFullHouse(PlayerBase *player){

    std::vector<Card> cards = player->getCards();
    cards.insert(cards.end(), this->communityCards.begin(), this->communityCards.end());

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
        } else if (count == 2) {
            hasPair = true;
        }
    }

    return hasThreeOfAKind && hasPair;

}

bool Poker::isFlush(PlayerBase *player){
    std::vector<Card> cards = player->getCards();
    cards.insert(cards.end(), this->communityCards.begin(), this->communityCards.end());

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

//std::vector<Card> flushCards;
//for (const auto& card : cards) {
//    if (card.suit == suit.first) {
//        flushCards.push_back(card);
//    }
//}
bool Poker::isStraight(PlayerBase *player){
    

    std::vector<Card> cards = player->getCards();
    cards.insert(cards.end(), this->communityCards.begin(), this->communityCards.end());

    auto compareByValue = [](const Card& a, const Card& b) {
    return a.value < b.value;
    };

    //sort
    std::sort(cards.begin(), cards.end(), compareByValue);
    
    int count = 0;
    //looping and checking if any of the handranks come one
    //after another for 4 cards straight
    for (int i = 0; i < cards.size() - 1; i++) {
        if (int(cards[i+1].value) - int(cards[i].value) == 1) {
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

bool Poker::isThreeOfAKind(PlayerBase *player){
    std::vector<Card> cards = player->getCards();
    cards.insert(cards.end(), this->communityCards.begin(), this->communityCards.end());


    auto compareByValue = [](const Card& a, const Card& b) {
    return a.value < b.value;
    };

    //sort
    std::sort(cards.begin(), cards.end(), compareByValue);

    // Check for three of a kind same process as 4 of a kind
    for (size_t i = 0; i <= cards.size() - 3; i++) {
        if (cards[i].value == cards[i+1].value && cards[i+1].value == cards[i+2].value) {
            return true;
        }
    }

    return false;

}

bool Poker::isTwoPair(PlayerBase *player){
    std::vector<Card> cards = player->getCards();
    cards.insert(cards.end(), this->communityCards.begin(), this->communityCards.end());
    auto compareByValue = [](const Card& a, const Card& b) {
    return a.value < b.value;
    };

    //sort
    std::sort(cards.begin(), cards.end(), compareByValue);
    

    int numPairs = 0;
    // go through and check for pairs once we find one pair we increment
    // numPairs and check for the second
    CardValue firstPairValue = CardValue::Two;  // arbitrary initial value
    for (size_t i = 0; i < cards.size() - 1; i++) {
        if (cards[i].value == cards[i+1].value) {
            if (numPairs == 0) {
                firstPairValue = cards[i].value;
                numPairs++;
            } else if (cards[i].value != firstPairValue) {
                // two pairs of different card values found
                return true;
            }
            i++;  // skip over second card in pair
        }
    }

    return false;
}

bool Poker::isPair(PlayerBase *player){
    std::vector<Card> cards = player->getCards();
    cards.insert(cards.end(), this->communityCards.begin(), this->communityCards.end());

    auto compareByValue = [](const Card& a, const Card& b) {
    return a.value < b.value;
    };

    //sort
    std::sort(cards.begin(), cards.end(), compareByValue);

    // Check for four of a kind
    for (size_t i = 0; i <= cards.size() - 2; i++) {
        if (cards[i].value == cards[i+1].value ){
            return true;
        }
    }

    return false;
}


std::vector<PlayerBase*> Poker::determineHandWinner(){
    
    std::vector<PlayerBase*> topPlayerHands;  

    std::cout<< "determineHandWinner"<<std::endl;

    int rank =-1;
    for(auto player: this->players)
    {
        std::cout<< player->getName() << std::endl; 
        if (this->isStraightFlush(player)){
            if (rank==8){
                topPlayerHands.push_back(player);
               
            }
            else{
                rank = 8;
                topPlayerHands.clear();
                topPlayerHands.push_back(player);
            
            }
        }
        else if (this->isFourOfAKind(player)&&rank<8){
            if (rank==7){
                topPlayerHands.push_back(player);
            
            }
            else{
                rank = 7;
                topPlayerHands.clear();
                topPlayerHands.push_back(player);
              
            }
            
        }
        else if (this->isFullHouse(player)&&rank<7){
            if (rank==6){
                topPlayerHands.push_back(player);
                std::cout<< " full if"<<std::endl;
            }
            else{
                rank = 6;
                topPlayerHands.clear();
                topPlayerHands.push_back(player);
                std::cout<< " full else"<<std::endl;
            }
        }
        else if (this->isFlush(player)&&rank<6){
            if (rank==5){
                topPlayerHands.push_back(player);
                std::cout<< "flush if"<<std::endl;
            }
            else{
                rank = 5;
                topPlayerHands.clear();
                topPlayerHands.push_back(player);
                std::cout<< " flush else"<<std::endl;
            }
        }
        else if (this->isStraight(player)&&rank<5){
            if (rank==4){
                topPlayerHands.push_back(player);
                std::cout<< "str8 if"<<std::endl;
            }
            else{
                rank = 4;
                topPlayerHands.clear();
                topPlayerHands.push_back(player);
                std::cout<< " str8 else"<<std::endl;
            }
        }
        else if (this->isThreeOfAKind(player)&&rank<4){
            if (rank==3){
                topPlayerHands.push_back(player);
                std::cout<< " 3 else"<<std::endl;
            }
            else{
                rank = 3;
                topPlayerHands.clear();
                topPlayerHands.push_back(player);
                std::cout<< " 3 else"<<std::endl;
            }
        }
        else if (this->isTwoPair(player)&&rank<3){
            if (rank==2){
                topPlayerHands.push_back(player);
                std::cout<< "2pair if "<< std::endl;
            }
            else{
                rank = 2;
                topPlayerHands.clear();
                topPlayerHands.push_back(player);
                std::cout<< "two pair else "<< std::endl;
            }
        }
        else if (this->isPair(player)&&rank<2){
            if (rank==1){
                topPlayerHands.push_back(player);
                std::cout<< "pair if "<< std::endl;
            }
            else{
                rank = 1;
                topPlayerHands.clear();
                topPlayerHands.push_back(player);
                std::cout<< "pair else "<< std::endl;
            }
        }
        else{
            if (rank<1){

            std::cout<< "high card "<< std::endl;
            topPlayerHands.push_back(player);
            
            }
        }
    }
    return topPlayerHands;
}

void Poker::fullGame()
{
    
  
    std::cout<<"numberOfchips set"<< std::endl;
    this->hand();
    // while (this->players.size()>1)
    // {
    //     this->hand();
    
    // }
    std::cout<<"Match winner = "<<std::endl;


}

// Outline of order in which events will happened although called by the UI 
// betting occurs in each of these steps
// start hand 
// Flop 
// turn
// river

void Poker::startHandState()
{
    std::cout<< "starting a Hand"<< std::endl;
 
    this->setPlayerBlinds();
    
    std::cout<< "setting blinds"<< std::endl;
    this->setPlayerCards();
    std::cout<< "setting player Cards"<< std::endl;
    this->setCommunityCards();
    
    std::cout<< "setting community cards"<< std::endl;
    
   
    
}
void Poker::incrementState(){
    this->currentState = static_cast<GameState>(this->currentState + 1); 
}
void Poker::startGame()
{
  
    std::cout<< "num of players = "<< this->players.size()<<std::endl;
    
    for(auto& player: this->players){
        player->setNumberOfChips(this->chipsPerPlayer);
        std::cout<<player->getNumberOfChips()<<std::endl;
    }
    this->incrementState();
    this->startHandState();
    

}


void Poker::flopState()
{
    this->notifyUpdateCommunityCardsOnFlop(this->communityCard1, this->communityCard2, this->communityCard3);
    this->bettingState();
    
    
}
void Poker::turnState()
{
    this->notifyUpdateCommunityCardsOnTurn(this->communityCard4);
    this->bettingState();
}
void Poker::riverState()
{
    this->notifyUpdateCommunityCardsOnRiver(this->communityCard5);
    this->bettingState();
}
void Poker::showDownState(){
    std::vector<PlayerBase*> players =this->determineHandWinner();
    std::cout << players[0]->getName() << std::endl;
    

    notifyUpdateOnShowDown(this->playersInHand[1]->getCards(), this->playersInHand[2]->getCards(), this->playersInHand[3]->getCards(), players[0]->playerIndex);
}
void Poker::gameLostState() {
    
    this->notifyGameLost();
   
    std::cout << "game over sequence" << std::endl;
}
void Poker::gameWonState() {
    this->notifyGameWon();
}
void Poker::bettingState(){
    bool bettingComplete = false;

    int bettingRound = 0;
    
    int prevBet;
    while(!bettingComplete)
    {
        int numPlayersChecked =0;
        bettingRound++;
        bool allPlayersChecked = false;
  
        for (auto& player : this->playersInHand)
        {
            std::cout << "pot = " << this->pot << std::endl;
            Decision decision = player->makeDecision(this->currentBetAmount, bettingRound);
           

            if (decision == Decision::Fold) {
                std::cout<<player->getName()<<" has folded"<<std::endl;
                if (player->getName() == "Guest") {
                    this->gameLostState();
                }
                this->notifyPlayerFolded(player->playerIndex);
                this->removePlayerFromHand(player);
                
                
       
                
                
            }
            else if (decision == Decision::Call){
                
                int chipsToAdd;
                if (player->getName() == "Guest") {
                    if (player->takeChips(this->currentBetAmount-prevBet)) {
                        std::cout << player->getName() << " has called for " << this->currentBetAmount << std::endl;
                        this->notifyPlayerCall(player->playerIndex, this->currentBetAmount);
                        if (player->getName() == "Guest") {
                            chipsToAdd = 0;
                            this->currentBetAmount = 0;

                        }
                        else {
                            chipsToAdd = this->currentBetAmount;

                        }
                    }
                    else {
                        std::cout << player->getName() << " else loop has called for " << this->currentBetAmount << std::endl;
                        chipsToAdd = player->allIn();

                        this->notifyPlayerAllIn(player->playerIndex);
                    }
                }
                if(player->takeChips(this->currentBetAmount)){
                    std::cout<<player->getName()<<" has called for " << this->currentBetAmount<<std::endl;
                    this->notifyPlayerCall(player->playerIndex, this->currentBetAmount);
                    if (player->getName() == "Guest") {
                        chipsToAdd = 0;
                        this->currentBetAmount = 0;

                    }
                    else {
                        chipsToAdd = this->currentBetAmount;

                    }
                }
                else{
                    std::cout<<player->getName()<<" else loop has called for " << this->currentBetAmount<<std::endl;
                    chipsToAdd = player->allIn();
                    
                    this->notifyPlayerAllIn(player->playerIndex);
                }
                std::cout << this->pot << std::endl;
                this->pot += chipsToAdd;
                std::cout << this->pot << std::endl;

            
            }
            else if (decision == Decision::Check){
                
                numPlayersChecked++;
                this->currentBetAmount = 0;
                std::cout<<player->getName()<<" has checked"<<std::endl;
                this->notifyPlayerCheck(player->playerIndex);
            }
            else if(decision == Decision::Raise){
                int bet = player->getChipsToBet();
                
                std::cout<<player->getName()<<" has raised"<<bet<<std::endl;
                prevBet = this->currentBetAmount;
                this->currentBetAmount = this->currentBetAmount+bet;
                this->pot += bet;
                allPlayersChecked = false;
                notifyPlayerRaise(player->playerIndex, currentBetAmount);
            }
            this->notifyUpdatePotAmount(this->pot);
            std::cout << "pot amount = " << this->pot << std::endl;
            sf::sleep(sf::milliseconds(1000));
            if (numPlayersChecked==4) bettingComplete = true;
        }
            
    }
    std::cout<<"End of Betting"<<std::endl;
    this->incrementState();
    if(this->currentState ==GameState::Flop){
        this->flopState();
    }
    else if(this->currentState ==GameState::Turn){
        this->turnState();
    }
    else if(this->currentState ==GameState::River){
        this->riverState();
    }
    else if(this->currentState ==GameState::ShowDown){
        this->showDownState();
    }
     
    this->currentBetAmount = 0;
}
void Poker::testFunc()
{
    for (auto player: this->players){
        std::cout<<player<<std::endl;
        std::vector<Card> tester = player->getCards();
        std::cout<< (int)tester[0].value<< " "<< (int)tester[1].value<< std::endl;
    }
}

Poker::Poker()
{
    this->initializeVariables();
    this->initializePlayers();
    

    std::cout<<this->playersInHand.size()<<std::endl;
    std::cout<<"Poker"<<std::endl;
}


Poker::~Poker(){

}