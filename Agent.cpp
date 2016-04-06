


#include "Agent.h"
#include "Piece.h"

namespace Gaming {
     const double AGENT_FATIGUE_RATE = 0.3;




// Agent Constructor
    Agent::Agent(const Gaming::Game &g, const Gaming::Position &p, double energy) : Piece (g, p) {
            __energy = energy;
    }

// Agent Destructor
    Agent::~Agent() {
        __energy = 0; //?

    }


}//end namespace Gaming



