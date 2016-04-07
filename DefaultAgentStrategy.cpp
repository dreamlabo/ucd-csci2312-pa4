// Todd Labo
// PA-4


#include "Strategy.h"
#include "DefaultAgentStrategy.h"

namespace Gaming {

// DefaultAgentStrategy Constructor
  DefaultAgentStrategy::DefaultAgentStrategy()
          : Strategy()

    {

    }


    DefaultAgentStrategy::~DefaultAgentStrategy() {

    }


// overloaded operator()
    ActionType DefaultAgentStrategy::operator()(const Surroundings &s) const {
      //return S;
    }


} // end namespace Gaming


