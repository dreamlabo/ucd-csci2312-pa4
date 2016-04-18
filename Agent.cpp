#include "Food.h"
#include "Advantage.h"
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

        return *this;

    }


// interact function (Agent parameter)
    Piece &Agent::interact(Agent *agent) {
        if(this->__energy == agent->__energy){ //If equal, both Agent-s call Piece::finish()
            this->finish();              //  and are taken out of the Game at the end of the round.
            agent->finish();
        }
        else if(this->__energy > agent->__energy){  // if unequal, the Agent with the larger wins,
            this->__energy -= agent->__energy;            // the smaller energy is subtracted from its energy, and the losing Agent calls Piece::finish()
            agent->finish();                        //  and is taken out of the Game at the end of the round.
        }
        else{
            agent->__energy -= this->__energy;
            this->finish();
        }
        return *this;
    }



// interact function (Resource parameter)
    Piece &Agent::interact(Resource *resource) {
       __energy += resource->consume();

    }


}//end namespace Gaming



