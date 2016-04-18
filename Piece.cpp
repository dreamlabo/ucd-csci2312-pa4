

#include "Piece.h"




namespace Gaming{

    unsigned int Piece::__idGen = 100;


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
           // __idGen--;
        //or should it be __idGen--  ?
    }

    std::ostream &operator<<(std::ostream &os, const Piece &piece) {
        piece.print(os);
        return os;

    }


}//end namespace Gaming




