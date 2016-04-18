// Todd Labo
// PA-4

#include "Piece.h"
#include "Strategy.h"
#include "DefaultAgentStrategy.h"

namespace Gaming {

// DefaultAgentStrategy Constructor
  DefaultAgentStrategy::DefaultAgentStrategy()
          : Strategy()

    {

    }


    DefaultAgentStrategy::~DefaultAgentStrategy() {

    }


// overloaded operator()
    ActionType DefaultAgentStrategy::operator()(const Surroundings &s) const {
//      std::vector<int> surrounding_Advantage;
//      std::vector<int> surrounding_Food;
//      std::vector<int> surrounding_Empty;
//      std::vector<int> surrounding_Simple;
//      Position pos(1,1);
//      ActionType action;
//
//      for (unsigned int index = 0; index < s.array.size(); index++) {
//        if (s.array[index] == ADVANTAGE) {
//          surrounding_Advantage.push_back(index);
//        }
//        else if (s.array[index] == FOOD) {
//          surrounding_Food.push_back(index);
//        }
//        else if (s.array[index] == EMPTY) {
//          surrounding_Empty.push_back(index);
//        }
//        else if (s.array[index] == SIMPLE) {
//          surrounding_Simple.push_back(index);
//        }
//      }
//
//
//      if (surrounding_Advantage.size() > 0){
//        PositionRandomizer positionRandomizer;
//        Position position = positionRandomizer(surrounding_Advantage);
//        action =  Game::reachSurroundings(pos, position);
//      }
//      else if (surrounding_Food.size() > 0){
//        PositionRandomizer positionRandomizer;
//        Position position = positionRandomizer(surrounding_Advantage);
//        action = Game::reachSurroundings(pos, position);
//      }
//      else if (surrounding_Empty.size() > 0){
//        PositionRandomizer positionRandomizer;
//        Position position = positionRandomizer(surrounding_Advantage);
//        action =  Game::reachSurroundings(pos, position);
//      }
//      else if (surrounding_Simple.size() > 0){
//        PositionRandomizer positionRandomizer;
//        Position position = positionRandomizer(surrounding_Advantage);
//        action =  Game::reachSurroundings(pos, position);
//      }
//      else
//        action = STAY;
//
//      return action;
    }

} // end namespace Gaming


