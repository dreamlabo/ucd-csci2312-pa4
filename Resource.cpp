// Todd Labo
// PA-4


#include "Piece.h"
#include "Resource.h"

namespace Gaming{

     const double Resource::RESOURCE_SPOIL_FACTOR  = 1.2;

//Resource Constructor
    Gaming::Resource::Resource(const Gaming::Game &g, const Gaming::Position &p, double capacity)
            : Piece(g, p) {
              __capacity = capacity;
            }

// Resource Destructor
    Resource::~Resource() {

    }


// consume function
    double Resource::consume() {
        double consume = __capacity;
        __capacity = 0;
        finish();
        return consume;
    }


// age function
    void Resource::age() {
        __capacity = __capacity/ Resource::RESOURCE_SPOIL_FACTOR;
        if (__capacity < 1){
            finish();
        }
    }



// takeTurn function
    ActionType Resource::takeTurn(const Surroundings &s) const {
        return STAY;
    }

// overloaded operator*
    Piece &Resource::operator*(Piece &other) {
        return *this;
    }

// interact function   (Agent parameter)
    Piece &Resource::interact(Agent *agent) {
        return *this;
    }


// interact function (Resource Parameter)
    Piece &Resource::interact(Resource *resource) {
        return *this;
    }



} // end namespace Gaming
