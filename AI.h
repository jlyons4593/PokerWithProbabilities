#include "PlayerBase.h"
#include "Strategy.h"


class AI : public PlayerBase{
public:
    int makeDecision() override;

   

    AI(Strategy* strategy);
    

private:
    Strategy* strategy_;
    
};