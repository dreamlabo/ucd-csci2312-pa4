
#include <iomanip>
#include "Agent.h"
#include "Strategic.h"

namespace Gaming {

    const char Strategic::STRATEGIC_ID = 'T' ;


    Gaming::Strategic::Strategic(const Gaming::Game &g, const Gaming::Position &p, double energy, Gaming::Strategy *s)
            : Agent (g, p, energy){
              __strategy = s;
            }


// Strategic Destructor
    Strategic::~Strategic() {

    }

// print function
    void Strategic::print(std::ostream &os) const {
        os << Strategic::STRATEGIC_ID << std::setw(4) << std::left <<Piece::__id;

    }


// takeTurn function
    ActionType Strategic::takeTurn(const Surroundings &s) const {
       return (*__strategy)(s);
    }


}// end namespace Gaming