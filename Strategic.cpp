

#include "Agent.h"
#include "Strategic.h"

namespace Gaming {

    const char Strategic::STRATEGIC_ID = 'T' ;


    Gaming::Strategic::Strategic(const Gaming::Game &g, const Gaming::Position &p, double energy, Gaming::Strategy *s)
            : Agent (g, p, energy)
    {

    }


// Strategic Destructor
    Strategic::~Strategic() {

    }

// print function
    void Strategic::print(std::ostream &os) const {

    }


// takeTurn function
    ActionType Strategic::takeTurn(const Surroundings &s) const {
        return S;
    }


}// end namespace Gaming