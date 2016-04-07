//
// Created by Owner on 4/6/2016.
//


#include "Piece.h"
#include "Simple.h"



namespace Gaming {

     const char Simple::SIMPLE_ID = 'S' ;


// Simple Constructor (Simple Agent)
    Simple::Simple(const Gaming::Game &g, const Gaming::Position &p, double energy): Agent(g, p, energy) {

    }



// Simple Destructor (Simple Agent)
    Simple::~Simple() {
        // What do I need?
    }


// print function
    void Simple::print(std::ostream &os) const {
        os << SIMPLE_ID;

    }

// takeTurn function
    ActionType Simple::takeTurn(const Surroundings &s) const {
        return S;
    }


}



