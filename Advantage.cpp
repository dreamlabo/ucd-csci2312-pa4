// Todd Labo
// PA-4
#include <iomanip>
#include "Resource.h"
#include "Advantage.h"

namespace Gaming{

    const char Advantage::ADVANTAGE_ID = 'D';
    const double Advantage::ADVANTAGE_MULT_FACTOR = 2.0;


// Advantage Constructor
    Gaming::Advantage::Advantage(const Gaming::Game &g, const Gaming::Position &p, double capacity)
    : Resource(g, p, capacity){
        __capacity = capacity * Advantage::ADVANTAGE_MULT_FACTOR;
    }


// Advantage Destructor
    Advantage::~Advantage() {
    }


// print function
    void Advantage::print(std::ostream &os) const {
        os << Advantage::ADVANTAGE_ID << std::setw(4) << std::left << __id;
    }

// getCapacity function
    double Advantage::getCapacity() const {
      return __capacity;
    }


// consume function
    double Advantage::consume() {
        finish();
    }


} // end Gaming Namespace

