#include "PokerHand.h"
#include "IPokerHandUI.h"
void PokerHand::initVariables()
{
    this->deck.shuffleDeck();
    this->numOfPlayers = 4;
    this->chipsPerPlayer = 100;
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
        std::cout<<i<<std::endl;

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

    while (this->ui->isGameRunning) {

        this->ui->update();

        this->ui->render();
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
        std::cout << player->getNumberOfChips() << std::endl;
    }

   
}
PokerHand::PokerHand()
{
    this->beginGame();
}

PokerHand::~PokerHand()
{
    for (auto& player : this->players) {
        delete player;
    }
}
