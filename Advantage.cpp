// Todd Labo
// PA-4

#include "Resource.h"
#include "Advantage.h"

namespace Gaming{

    const char Advantage::ADVANTAGE_ID = 'D';
    const double Advantage::ADVANTAGE_MULT_FACTOR= 2.0;



// Advantage Constructor
    Gaming::Advantage::Advantage(const Gaming::Game &g, const Gaming::Position &p, double capacity)
    : Resource(g, p, capacity){

    }



// Advantage Destructor
    Advantage::~Advantage() {
     // need what?
    }


// print function
    void Advantage::print(std::ostream &os) const {
        os << Advantage::ADVANTAGE_ID;
    }

// getCapacity function
    double Advantage::getCapacity() const {
      //  return Resource::getCapacity();
    }


// consume function
    double Advantage::consume() {
        //return Resource::consume();
    }


} // end Gaming Namespace

