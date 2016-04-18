//
// Created by Owner on 4/6/2016.
//

#include <iomanip>
#include "Piece.h"
#include "Simple.h"



namespace Gaming {

    const char Simple::SIMPLE_ID = 'S';


// Simple Constructor (Simple Agent)
    Simple::Simple(const Gaming::Game &g, const Gaming::Position &p, double energy) :
            Agent(g, p, energy) {

    }


// Simple Destructor (Simple Agent)
    Simple::~Simple() {
        // What do I need?
    }


// print function
    void Simple::print(std::ostream &os) const {
        os << SIMPLE_ID << std::setw(4) << std::left << Piece::__id;
    }


// takeTurn function
    ActionType Simple::takeTurn(const Surroundings &s) const {
//        std::vector<int> surroundings;
//        std::vector<int> emptyGrid;
//
//        for (unsigned int index = 0; index < s.array.size(); index++){
//            if (s.array[index] == PieceType:: ADVANTAGE || s.array[index] == PieceType:: FOOD){
//                surroundings.push_back(index);
//            }
//            else if (s.array[index] == EMPTY){
//                emptyGrid.push_back(index);
//            }
//        }
//        if (surroundings.size() > 0){
//            return __game.reachSurroundings(getPosition(), __game.randomPosition(surroundings));
//        }
//        else if (emptyGrid.size() > 0){
//            return __game.reachSurroundings(getPosition(), __game.randomPosition(emptyGrid));
//        }
//        else{
//            return STAY;
//        }


    }

    }




