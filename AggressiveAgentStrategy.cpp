// Todd Labo
// PA-4
//

#include "Game.h"
#include "AggressiveAgentStrategy.h"


namespace  Gaming{
    const double AggressiveAgentStrategy::DEFAULT_AGGRESSION_THRESHOLD = Game::STARTING_AGENT_ENERGY * 0.75;


   AggressiveAgentStrategy::AggressiveAgentStrategy(double agentEnergy)
         : __agentEnergy(agentEnergy){
    }


    AggressiveAgentStrategy::~AggressiveAgentStrategy() {

    }


    ActionType AggressiveAgentStrategy::operator()(const Surroundings &s) const {
        return S;
    }



} // end namespace Gaming

