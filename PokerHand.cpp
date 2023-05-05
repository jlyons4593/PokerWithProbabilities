#include "PokerHand.h"
#include "IPokerHandUI.h"
void PokerHand::initVariables()
{
    this->deck.shuffleDeck();
    this->numOfPlayers = 4;
    this->chipsPerPlayer = 100;
    this->currentState = GameState::InitialState;
    
}

void PokerHand::initPlayers()
{
    
    // create player objects and add them to the players vector
    Player* player = new Player();
    player->setPlayer();
    player->setName("Joe");
    
    this->players.push_back(player);
    for (int i = 0; i < this->numOfPlayers; i++)
    {
        if( i %2 ==0){
            this->players.push_back(new AI(new RandomStrategy));
        }
        else{
            this->players.push_back(new AI(new HandStrengthStrategy));
        }
        this->players[i + 1]->setName("AI" + std::to_string(i+1));
    }
    
}

void PokerHand::loadUI()
{
   
    IPokerHandUI& inter = IPokerHandUI::getInstance();
    PokerHandUI* ui = inter.getPokerHandUI();
    this->ui = ui;
    this->attach(this->ui);

    while (!this->ui->handStarted) {

        this->ui->initialUpdate();

        this->ui->render();
    }
 
    while (this->ui->isGameRunning) {

        this->ui->update();

        this->ui->render();
    }
    
   
}

void PokerHand::payBlinds()
{

    this->players[1]->takeChips(10);
    std::cout << players[1]->getName() << " has paid the big blind" << std::endl;
    std::cout << this->players[1]->returnNumberOfChips() << std::endl;
    

    this->players[2]->takeChips(5);
    std::cout << players[2]->getName() << " has paid the small blind" << std::endl;
    std::cout << this->players[2]->returnNumberOfChips() << std::endl;

}
void PokerHand::setPlayerCards() 
{
    std::vector<Card> cards;
    for (int i = 0; i < this->players.size(); i++)
    {
        Card card1 = this->deck.drawCard();
        cards.push_back(card1);
        Card card2 = this->deck.drawCard();
        cards.push_back(card2);

        std::cout << (int)cards[0].value << " " << (int)cards[1].value << " player " << i << std::endl;

        this->players[i]->setCards(cards);
        if (this->players[i]->getName() == "Joe") {

            std::cout << " Name of player is Joe" << std::endl;
            this->notifyUpdatePlayersCards(cards);
        }
        cards.clear();
    }


}
void PokerHand::setCommunityCards()
{
    for (int i = 0; i < 5; i++ ) {
        this->communityCards.push_back(this->deck.drawCard());
    }
    std::cout << this->communityCards.size() << std::endl;
    std::cout << (int)this->communityCards[4].value << std::endl;
    
}
void PokerHand::setCardsAndBlinds()
{
    std::cout << "Setting blinds and cards" << std::endl;

    this->payBlinds();
    std::cout << "setting blinds" << std::endl;
    this->setPlayerCards();
    std::cout << "setting player Cards" << std::endl;
    this->setCommunityCards();

    std::cout << "setting community cards" << std::endl;

}

void PokerHand::updateUI()
{
    switch (this->currentState) {
    case GameState::Preflop:
        // Call a function to update the UI for the preflop state
        break;
    case GameState::Flop:
        // Call a function to update the UI for the flop state
        break;
    case GameState::Turn:
        // Call a function to update the UI for the turn state
        break;
    case GameState::River:
        // Call a function to update the UI for the river state
        break;
    case GameState::Showdown:
        // Call a function to update the UI for the showdown state
        break;
    }
}

void PokerHand::beginGame()
{
    
    this->initVariables();
    this->initPlayers();
}

void PokerHand::startHand() 
{
    for (auto& player : this->players) {
        player->setNumberOfChips(this->chipsPerPlayer);
    }
    this->setCardsAndBlinds();
    this->setState(GameState::Preflop);
}

PokerHand::PokerHand()
{
    
    this->beginGame();
    
}

PokerHand::~PokerHand()
{
    for (auto& player : this->players) 
    {
        delete player;
    }
}
