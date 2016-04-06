

#include "Piece.h"




namespace Gaming{

    unsigned int Piece::__idGen = 0;




// Piece Constructor
    Piece::Piece(const Gaming::Game &g, const Gaming::Position &p) : __game(g),__position(p) {
            __finished = false;
            __turned = false;
            __id = __idGen++;
    }


// Piece desctructor
    Piece::~Piece() {
            __finished = true;
            __turned = true;
            __id = 0;
        //or should it be __idGen--  ?
    }


}//end namespace Gaming




