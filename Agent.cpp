


#include "Agent.h"
#include "Piece.h"

namespace Gaming {
     const double Agent::AGENT_FATIGUE_RATE = 0.3;




// Agent Constructor
    Agent::Agent(const Gaming::Game &g, const Gaming::Position &p, double energy) : Piece (g, p) {
            __energy = energy;
    }

// Agent Destructor
    Agent::~Agent() {
        __energy = 0; //?

    }


// age function
    void Agent::age() {
      __energy = __energy - AGENT_FATIGUE_RATE;
    }


// overloaded operator*  function
    Piece &Agent::operator*(Piece &other) {

        //return <#initializer#>;
    }


// interact function (Agent parameter)
    Piece &Agent::interact(Agent *) {
        //return <#initializer#>;
    }


// interact function (Resource parameter)
    Piece &Agent::interact(Resource *) {
       // return <#initializer#>;
    }


}//end namespace Gaming



