



#include "Game.h"
#include <iostream>
#include <vector>
#include <array>
#include "Exceptions.h"
#include "Gaming.h"
#include "DefaultAgentStrategy.h"
namespace Gaming {

    const unsigned int NUM_INIT_AGENT_FACTOR = 4;
    const unsigned int NUM_INIT_RESOURCE_FACTOR = 2;
    const unsigned int Game::MIN_WIDTH = 3;
    const unsigned int Game::MIN_HEIGHT = 3;
    const double STARTING_AGENT_ENERGY = 20;
    const double STARTING_RESOURCE_CAPACITY = 10;



// populate function
// randomly populates the game grid with agents (Strategic and Simple), food,
// Precondition:
// Postcondition: The grid is populated and ready for game play
    void Game::populate() {

// Populate the game with Strategic Agents
//        while (numStrategic > 0) {
//            int i = d(gen); // random index in the grid vector
//            if (__grid[i] == nullptr) { // is position empty
//                Position pos(i / __width, i % __width);
//                __grid[i] = new Strategic(*this, pos, Game::STARTING_AGENT_ENERGY);
//                numStrategic --;
//            }
//        }


    }

// Game constructor #1
    Gaming::Game::Game() {

      __round = 0;
      __width = Game::MIN_WIDTH;
      __height = Game::MIN_HEIGHT;

      __status = NOT_STARTED;
      __numInitAgents = 0;
      __numInitResources = 0;

        // need grid

    }

    Game::Game(unsigned width, unsigned height, bool manual)
            : __width(width),
              __height(height)
        {
            try {
                if (__width < MIN_WIDTH || __height < MIN_HEIGHT){
                    throw InsufficientDimensionsEx(__width,__height,MIN_WIDTH,MIN_HEIGHT );
                }

            } catch (InsufficientDimensionsEx &ex) {
            throw ex;
            }
            __round = 0;
            __status = NOT_STARTED;
            __numInitAgents = 0;
            __numInitResources = 0;
            // needs work
            // needs __grid
        }


// Game constructor #3
    Game::Game(const Game &another) {


        // needs work
    }

    unsigned int Game::getNumPieces() const {  // needs work
        return __numInitAgents;
    }



// Destructor
    Game::~Game(){
        while (!__grid.empty()){
            __grid.pop_back();
        }
        __grid.clear();
        __status = OVER;
        __verbose = false;
    }



// Getters *******************

// getNumAgents Function
// returns __numInitAgents
// Precondition:
// Postcondition:  __numInitAgents is returned.
    unsigned int Game::getNumAgents() const {
        return __numInitAgents;
    }



// getNumSimple Function
//
// Precondition:
// Postcondition:
    unsigned int Game::getNumSimple() const {
       // needs work;
    }



//  getNumStrategic Function
//
// Precondition:
// Postcondition:
    unsigned int Game::getNumStrategic() const {
       // needs work return 0;
    }

//  getNumResources Function
//
// Precondition:
// Postcondition:

    unsigned int Game::getNumResources() const {
        return __numInitResources;
    }

// overloaded operator<<
    std::ostream &operator<<(std::ostream &os, const Game &game) {
        return os;
    }








}//end namespace gaming


