



#include "Game.h"
#include "Simple.h"
#include "Strategic.h"
#include "Agent.h"
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

        // set up game board
//        for ( size_t index = 0; index < MIN_WIDTH * MIN_HEIGHT; index++){
//            __grid.push_back(nullptr);
//        }




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

            //set up game board
            for ( size_t index = 0; index < __width * __height; index++){
                __grid.push_back(nullptr);
            }


//            if (!manual)
//            {
//                populate();
//            }
//            else
//            {
//                __numInitResources = 0;
//                __numInitAgents = 0;
//            }
            // needs work
            // needs __grid
        }


// Game constructor #3
    Game::Game(const Game &another) {


        // needs work
    }

    unsigned int Game::getNumPieces() const {  // needs work
        unsigned int numAgents = 0;

        for (auto it = __grid.begin(); it != __grid.end(); ++it){
            Piece *piece = dynamic_cast<Piece*>(*it);
            if (piece) numAgents++;
        }
        return numAgents;
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
// returns the number of Agents on the grid
// Precondition:
// Postcondition: the number of Agents is returned
    unsigned int Game::getNumAgents() const {
        unsigned int numAgents = 0;

        for (auto it = __grid.begin(); it != __grid.end(); ++it){
            Agent *agent = dynamic_cast<Agent*>(*it);
            if (agent) numAgents++;
        }
        return numAgents;
    }



// getNumSimple Function
// returns the number of Simple Agents on the grid
// Precondition:
// Postcondition: the number of Simple Agents is returned
    unsigned int Game::getNumSimple() const {
      unsigned int numSimpleAgents = 0;

        for (auto it = __grid.begin(); it != __grid.end(); ++it){
            Agent *agent = dynamic_cast<Simple*>(*it);
            if (agent) numSimpleAgents++;
        }
        return numSimpleAgents;
    }



// getNumStrategic Function
// returns the number of Strategic Agents on the game board
// Precondition:
// Postcondition: the number of Strategic Agents is returned
    unsigned int Game::getNumStrategic() const {
        unsigned int numStrategicAgents = 0;

        for (auto it = __grid.begin(); it != __grid.end(); ++it){
            Agent *agent = dynamic_cast<Strategic*>(*it);
            if (agent) numStrategicAgents++;
        }
        return numStrategicAgents;
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
        os << "Round " << game.__round << std::endl;

      //  unsigned int j = 0;
        for (size_t index = 0; index < game.__height; index++){
            for(size_t index_2 = 0; index_2 < game.__width; index_2++){
                os << "[";
                if(game.__grid[index + index_2] != nullptr)
                {
                    os <<  game.__grid[index + index_2];
                }
                else
                    os << "     ";

                os << "]";
            }

        }
        return os;
    }








}//end namespace gaming


