// Todd Labo
// PA-4

#include "Piece.h"
#include "Strategy.h"
#include "DefaultAgentStrategy.h"

namespace Gaming {

// DefaultAgentStrategy Constructor
  DefaultAgentStrategy::DefaultAgentStrategy()
          : Strategy(){
    }


    DefaultAgentStrategy::~DefaultAgentStrategy() {
    }


// overloaded operator()
    ActionType DefaultAgentStrategy::operator()(const Surroundings &s) const {

//    If there are adjacent Advantage-s, returns a motion to one of them. That is, it prefers Advantage to Food.
//    lf there aren't adjacent Advantage-s, returns a move to an adjacent Food.
//    If there arent' adjacent Food-s, return's a move to an adjacent empty position.
//    If there aren't adjacent empty positions, it returns a move to an adjacent Simple agent (i.e. attacking it).
//    If no adjacent Simple agents, returns STAY.

      std::vector<int> advantage_Surr;
      std::vector<int> food_Surr;
      std::vector<int> empty_Surr;
      std::vector<int> simple_Surr;
      ActionType ac;

      for (unsigned int index = 0; index < s.array.size(); index++) {
        if (s.array[index] == PieceType::ADVANTAGE) {
          advantage_Surr.push_back(index);
        }
        else if (s.array[index] == FOOD) {
          food_Surr.push_back(index);
        }
        else if (s.array[index] == EMPTY) {
          empty_Surr.push_back(index);
        }
        else if (s.array[index] == SIMPLE) {
          simple_Surr.push_back(index);
        }
        else {
          // ignore the other types
        }
      }

      //now execute the strategy
      if (advantage_Surr.size() > 0) {
        ac = Game::reachSurroundings(Position(1, 1), Game::randomPosition(advantage_Surr));
      }
      else if (food_Surr.size() > 0) {
        ac = Game::reachSurroundings(Position(1, 1), Game::randomPosition(food_Surr));
      }
      else if (empty_Surr.size() > 0) {
        ac = Game::reachSurroundings(Position(1, 1), Game::randomPosition(empty_Surr));
      }
      else if (simple_Surr.size() > 0) {
        ac = Game::reachSurroundings(Position(1, 1), Game::randomPosition(simple_Surr));
      }
      else {
        ac = STAY;
      }
      return ac;
    }

} // end namespace Gaming


