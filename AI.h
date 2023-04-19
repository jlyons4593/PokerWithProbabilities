#include "PlayerBase.h"
#include "Strategy.h"


class AI : public PlayerBase{
public:
    int makeDecision() override;

    void setStrategy(std::unique_ptr<Strategy> strategy);

    AI(std::unique_ptr<Strategy> strategy);
    

private:
    std::unique_ptr<Strategy> strategy_;
    
};