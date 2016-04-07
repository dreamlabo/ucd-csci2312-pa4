// Todd Labo
// PA-4


#include "Piece.h"
#include "Resource.h"

namespace Gaming{

     const double Resource::RESOURCE_SPOIL_FACTOR  = 1.2;

//Resource Constructor
    Gaming::Resource::Resource(const Gaming::Game &g, const Gaming::Position &p, double capacity)
            : Piece(g, p)
    {
        __capacity = capacity;
    }

// Resource Destructor
    Resource::~Resource() {

    }


// consume function
    double Resource::consume() {
        return 0;
    }


// age function
    void Resource::age() {
        __capacity /= RESOURCE_SPOIL_FACTOR;
    }

// takeTurn function
    ActionType Resource::takeTurn(const Surroundings &s) const {
        return S;
    }

// overloaded operator*
    Piece &Resource::operator*(Piece &other) {
        //return <#initializer#>;
    }

// interact function   (Agent parameter)
    Piece &Resource::interact(Agent *) {
        //return <#initializer#>;
    }


// interact function (Resource Parameter)
    Piece &Resource::interact(Resource *) {
        //return <#initializer#>;
    }



} // end namespace Gaming
