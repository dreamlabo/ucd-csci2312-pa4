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
//If the Agent's energy >= aggressiveness threshold AND there are any adjacent Agent-s, challenge one of them.
//Else if adjacent Advantage-s, move onto an Advantage.
//Else if adjacent Food-s, move onto an Food.
//Else if adjacent empty positions, move onto an empty position.
//Else STAY

        std::vector<int> agent_Surr;
        std::vector<int> advantage_Surr;
        std::vector<int> food_Surr;
        std::vector<int> empty_Surr;

        ActionType ac;

        // fill vectors with appropriate pieces
        for (unsigned int index = 0; index < s.array.size(); index++) {

            if (s.array[index] == PieceType::SIMPLE || s.array[index] == PieceType::STRATEGIC) {
                agent_Surr.push_back(index);
                }

            else if (s.array[index] == ADVANTAGE) {
                advantage_Surr.push_back(index);
            }
            else if (s.array[index] == FOOD) {
                food_Surr.push_back(index);
            }
            else if (s.array[index] == EMPTY) {
                empty_Surr.push_back(index);
            }
            else {
                // ignore the other types
            }

        }

        // execute the strategy....
        if (agent_Surr.size() > 0 &&  __agentEnergy >= DEFAULT_AGGRESSION_THRESHOLD)    {
            ac = Game::reachSurroundings(Position(1, 1), Game::randomPosition(agent_Surr));
        }
        else if (advantage_Surr.size() > 0) {
            ac = Game::reachSurroundings(Position(1, 1), Game::randomPosition(advantage_Surr));
        }
        else if (food_Surr.size() > 0) {
            ac = Game::reachSurroundings(Position(1, 1), Game::randomPosition(food_Surr));
        }
        else if (empty_Surr.size() > 0) {
            ac = Game::reachSurroundings(Position(1, 1), Game::randomPosition(empty_Surr));
        }
        else {
            ac = STAY;
        }

        return ac;
    }

} // end namespace Gaming

