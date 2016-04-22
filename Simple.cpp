// Todd Labo
// PA-4

#include <iomanip>
#include "Piece.h"
#include "Simple.h"

namespace Gaming {

    const char Simple::SIMPLE_ID = 'S';


// Simple Constructor (Simple Agent)
    Simple::Simple(const Game &g, const Position &p, double energy) :
            Agent(g, p, energy) {
    }


// Simple Destructor (Simple Agent)
    Simple::~Simple() {
    }


// print function
    void Simple::print(std::ostream &os) const {
        os << SIMPLE_ID << std::setw(4) << std::left << __id;
    }


// takeTurn function
    ActionType Simple::takeTurn(const Surroundings &s) const {
        std::vector<int> surround;
        std::vector<int> empty;

        ActionType  ac;

        for (unsigned int index = 0; index < s.array.size(); index++){
            if (s.array[index] == PieceType::ADVANTAGE || s.array[index] == PieceType::FOOD){
                surround.push_back(index);
            }
            else if (s.array[index] == EMPTY){
                empty.push_back(index);
            }
            else {
                // ignore the other types
            }
        }
        if (surround.size() > 0){
            ac =  Game::reachSurroundings(Position(1,1), Game::randomPosition(surround));
        }
        else if (empty.size() > 0){
            ac =  Game::reachSurroundings(Position(1,1), Game::randomPosition(empty));
        }
        else{
            ac = STAY;
        }
    return ac;
    }

}




