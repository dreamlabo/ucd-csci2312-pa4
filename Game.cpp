// Todd Labo
// PA-4


#include <set>
#include "Game.h"
#include "Simple.h"
#include "Strategic.h"
#include "Advantage.h"
#include "Food.h"
#include "Agent.h"
#include <iostream>
#include <vector>
#include <array>
#include "Exceptions.h"
#include "Gaming.h"
#include "DefaultAgentStrategy.h"
#include <iomanip>
#include <sstream>
namespace Gaming {

    const unsigned int Game::NUM_INIT_AGENT_FACTOR = 4;
    const unsigned int Game::NUM_INIT_RESOURCE_FACTOR = 2;
    const unsigned int Game::MIN_WIDTH = 3;
    const unsigned int Game::MIN_HEIGHT = 3;
    const double Game::STARTING_AGENT_ENERGY = 20;
    const double Game::STARTING_RESOURCE_CAPACITY = 10;

    PositionRandomizer Game::__posRandomizer = PositionRandomizer();

// populate function
// randomly populates the game grid with agents (Strategic and Simple), food,
// Precondition:
// Postcondition: The grid is populated and ready for game play
    void Game::populate() {
        // simple pseudo-random number generator
        // sufficient for our casual purposes
        std::default_random_engine gen;
        std::uniform_int_distribution<int> d(0, __width * __height);

        __numInitAgents = (__width * __height) / NUM_INIT_AGENT_FACTOR;
        __numInitResources = (__width * __height) / NUM_INIT_RESOURCE_FACTOR;

        unsigned int numStrategic = __numInitAgents / 2;
        unsigned int numSimple = __numInitAgents - numStrategic;
        unsigned int numAdvantages = __numInitResources / 4;
        unsigned int numFoods = __numInitResources - numAdvantages;



        // Populate the game with Strategic Agents
               while (numStrategic > 0) {
                 int i = d(gen); // random index in the grid vector
                    if (__grid[i] == nullptr) { // is position empty
                     Position pos(i / __width, i % __width);
                     __grid[i] = new Strategic(*this, pos, Game::STARTING_AGENT_ENERGY);
                     numStrategic--;
                 }
               }

        // Populate the game with Simple Agents
           while (numSimple > 0) {
                    int i = d(gen); // random index in the grid vector
                  if (__grid[i] == nullptr) { // is position empty
                      Position pos(i / __width, i % __width);
                      __grid[i] = new Simple(*this, pos, Game::STARTING_AGENT_ENERGY);
                      numSimple--;
             }
           }

        // Populate the game with Food
        while (numFoods > 0) {
            int i = d(gen); // random index in the grid vector
            if (__grid[i] == nullptr) { // is position empty
                Position pos(i / __width, i % __width);
                __grid[i] = new Food(*this, pos, Game::STARTING_RESOURCE_CAPACITY);
                numFoods--;
            }
        }

        // Populate the game with Advantages
        while (numAdvantages > 0) {
            int i = d(gen); // random index in the grid vector
            if (__grid[i] == nullptr) { // is position empty
                Position pos(i / __width, i % __width);
                __grid[i] = new Advantage(*this, pos, Game::STARTING_RESOURCE_CAPACITY);
                numAdvantages--;
            }
        }

    }//end populate function

// Game constructor #1
    Gaming::Game::Game() {
      __round = 0;
      __verbose = false;
      __width = Game::MIN_WIDTH;
      __height = Game::MIN_HEIGHT;
      __status = NOT_STARTED;
//      __numInitAgents = 0;
//      __numInitResources = 0;

        // set up game board
        for (unsigned int index = 0; index < __width * __height; index++){
            __grid.push_back(nullptr);
        }
    }

    Game::Game(unsigned width, unsigned height, bool manual)
            : __width(width),
              __height(height){

                if (__width < MIN_WIDTH || __height < MIN_HEIGHT){
                    throw InsufficientDimensionsEx(__width,__height,MIN_WIDTH,MIN_HEIGHT );
                }

            __round = 0;
            __status = NOT_STARTED;
            __verbose = false;


            //sets up the game board
            for (unsigned int index = 0; index < __width * __height; index++){
                __grid.push_back(nullptr);
            }

            if (!manual){
                populate();
            }
        }


// Destructor
    Game::~Game(){
        while (!__grid.empty()){
            __grid.pop_back();
        }
        __grid.clear();

    }


// Getters **********************************************************************

// getNumPieces function
// returns the total number of pieces on the game board
// Precindition:
// Postcondition:  the total number of pieces on the game board is returned
    unsigned int Game::getNumPieces() const {  // needs work
        unsigned int numPieces = 0;

        for (auto it = __grid.begin(); it != __grid.end(); it++) {
            if (*it != nullptr) {
                numPieces++;
            }
        }
        return numPieces;
    }


// getNumAgents Function
// returns the number of Agents on the grid
// Precondition:
// Postcondition: the number of Agents is returned
    unsigned int Game::getNumAgents() const {
        unsigned int numAgents = 0;
        for (auto it = __grid.begin(); it != __grid.end(); ++it){
            Agent *agent = dynamic_cast<Agent*>(*it);
            if (agent){
                numAgents++;
            }
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
            Simple *simple = dynamic_cast<Simple*>(*it);
            if (simple) {
                numSimpleAgents++;
            }
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
            Strategic *strategic = dynamic_cast<Strategic*>(*it);
            if (strategic) {
                numStrategicAgents++;
            }
        }
        return numStrategicAgents;
    }

//  getNumResources Function
//
// Precondition:
// Postcondition:
    unsigned int Game::getNumResources() const {
        unsigned int numResources = 0;

        for (auto it = __grid.begin(); it != __grid.end(); ++it){
           Resource *resource = dynamic_cast<Resource*>(*it);
            if (resource){
                numResources++;
            }
        }
        return numResources;
    }


// getPiece function
//
// Precondition:
// Postcondition:
    const Piece *Game::getPiece(unsigned int x, unsigned int y) const {
         if(y > __width || x > __height) {
               throw OutOfBoundsEx(__width, __height, x, y);
         }

         if(__grid[(x * __width) + y] == nullptr) {
              throw PositionEmptyEx(x, y);
         }
        if (__grid[(x * __width) + y] != nullptr) {
            return __grid[(x * __width) + y];
        }
    }


    // overloaded operator<<
    std::ostream &operator<<(std::ostream &os, const Game &game) {
    unsigned int column = 0;
    os  << "Round " << game.__round << std::endl;
        for(int index = 0; index < (game.__width * game.__height); index++){
            if(game.__grid[index] == nullptr){
                 os << "[     ]";
            }
            else{
                os << "[" << *game.__grid[index] << "]";
             }

            if (++column == game.__width) {
                column = 0;
                os << std::endl;
            }
        }


        if(game.getStatus() == Game::NOT_STARTED){
            os << "Status: " << "Not Started" << std::endl;
            }
            else if(game.getStatus() == Game::PLAYING){
              os << "Status: " << "Playing..." << std::endl;
            }
            else //(game.getStatus() == Game::OVER)
                 os << "Status: " << "Over!" << std::endl;

        return os;
    }



//**********************************************************************************************
// grid population methods

// addSimple Function Position parameters]
// adds a Simple Agent to the game board at position
// Precondition:  the game grid (__grid) has been created, and the position is empty
// Postcondition: a Simple Agent is added to the game grid
    void Game::addSimple(const Position &position) {
        Simple *s = new Simple(*this,position,STARTING_AGENT_ENERGY);
        if(position.y > __width || position.x > __height) {
            throw OutOfBoundsEx(__width, __height, position.x, position.y);
        }
        if  (__grid[position.x * __width + position.y] != nullptr){
            throw PositionNonemptyEx(position.x, position.y);
        }

        if  (__grid[position.x * __width + position.y] == nullptr) {
            __grid[position.x * __width + position.y] = s;
        }
    }


// addSimple Function (Position/energy) paramters]
// adds a Simple Agent to the game board at position
// Precondition:  the game grid (__grid) has been created, and the position is empty
// Postcondition: a Simple Agent is added to the game grid
    void Game::addSimple(const Position &position, double energy) {
        Simple *s = new Simple(*this, position, energy);
        if(position.y > __width || position.x > __height) {
            throw OutOfBoundsEx(__width, __height, position.x, position.y);
        }

        if  (__grid[position.x * __width + position.y] == nullptr){
        __grid[(position.x * __width) + position.y] = new Simple(*this, position, energy);
         }
    }


// addSimple Function [(int, int) parameters]
// adds a Simple Agent to the game board at (x,y) cord
// Precondition:  the game grid (__grid) has been created, and the position is empty
// Postcondition: a Simple Agent is added to the game grid
    void Game::addSimple(unsigned x, unsigned y) {
        Position position(x, y);
        addSimple(position);
    }


// addSimple Function [(int, int, energy) parameters]
// adds a Simple Agent to the game board at (x,y) cord
// Precondition:  the game grid (__grid) has been created, and the position is empty
// Postcondition: a Simple Agent is added to the game grid
    void Game::addSimple(unsigned x, unsigned y, double energy) {
        Position position(x,y);
        addSimple(position, energy);
    }

// addStrategic Function [(Position, Strategy) parameters]
// adds a Strategic Agent to the game board at (x,y) cord
// Precondition: the game grid (__grid) has been created, and the position is empty
// Postcondition: a Strategic Agent has been added to the game grid
    void Game::addStrategic(const Position &position, Strategy *s) {
        Strategic *t = new Strategic(*this, position, STARTING_AGENT_ENERGY, s);
        if (position.y > __width || position.x > __height) {
            throw OutOfBoundsEx(__width, __height, position.x, position.y);
        }
        if (__grid[position.x * __width + position.y] != nullptr) {
            throw PositionNonemptyEx(position.x, position.y);
        }
        if (__grid[position.x * __width + position.y] == nullptr) {
            __grid[(position.x * __width) + position.y] = t;
        }
    }

// addStrategic Function [(int, int, Strategy) parameters]
// adds a Strategic Agent to the game board at (x,y) cord
// Precondition: the game grid (__grid) has been created, and the position is empty
// Postcondition: a Strategic Agent has been added to the game grid
    void Game::addStrategic(unsigned x, unsigned y, Strategy *s) {
        Position position(x, y);
        addStrategic(position, s);
    }


// addFood Function [(Position) parameters]
// adds a food resource to the game board at Position
// Precondition: the game grid (__grid) has been created, and the position is empty
// Postcondition: a food resource has been added to the game grid
    void Game::addFood(const Position &position) {

        if(position.y > __width || position.x > __height) {
            throw OutOfBoundsEx(__width, __height, position.x, position.y);
        }
        if  (__grid[(position.x * __width) + position.y] != nullptr){
            throw PositionNonemptyEx(position.x, position.y);
        }

        if  (__grid[(position.x * __width) + position.y] == nullptr) {
            Food *f = new Food(*this, position, Game::STARTING_RESOURCE_CAPACITY);
            __grid[(position.x * __width) + position.y] = f;
        }
    }


// addFood Function [(int, int) parameters]
// adds a food resource to the game board at (x,y) cord
// Precondition: the game grid (__grid) has been created, and the position is empty
// Postcondition: a food resource has been added to the game grid
    void Game::addFood(unsigned x, unsigned y) {
        Position position(x, y);
        addFood(position);
    }


// addAdvantage Function [Position parameters]
// adds an Advantage resource to the game board at the Position sent
// Precondition: the game grid (__grid) has been created, and the position is empty
// Postcondition: an Advantage resource has been added to the game grid
    void Game::addAdvantage(const Position &position) {
        if (position.y >= __width || position.x >= __height) {
            throw OutOfBoundsEx(__width, __height, position.x, position.y);
        }
        Advantage *a = new Advantage(*this, position, Game::STARTING_RESOURCE_CAPACITY);
        if ((__grid[(position.x * __width) + position.y] == nullptr)) {
            __grid[(position.x * __width) + position.y] = a;
        }
    }
// addAdvantage Function [(int, int) parameters]
// adds an Advantage resource to the game board at (x,y) cord
// Precondition: the game grid (__grid) has been created, and the position is empty
// Postcondition: an Advantage resource has been added to the game grid
    void Game::addAdvantage(unsigned x, unsigned y) {
        Position position(x, y);
        addAdvantage(position);
    }

// getSurroundings function
//
// Precondition:
// PostCondition:
    const Surroundings Game::getSurroundings(const Position &pos) const {
        Surroundings surroundings;

        unsigned int index = 0;

        for(int row = -1; row <= 1; row++){
            for(int column = -1; column <= 1; column++){
                if( pos.x + row < 0 || pos.x + row >= __height || pos.y + column < 0 || pos.y + column  >= __width ) {
                    surroundings.array[index] = PieceType:: INACCESSIBLE;
                    index++;
                }
                else if(__grid[(pos.x + row) * __width + (pos.y + column)] == nullptr) {
                    surroundings.array[index] = EMPTY;
                    index++;
                }
                else{
                    surroundings.array[index] = getPiece(pos.x + row,pos.y + column)->getType();
                    index++;
                }
            }
        }
        surroundings.array[4] = SELF;
        return surroundings;
    }
// reachSurroundings function
//
// Precondition:
// Postcondition:
    const ActionType Game::reachSurroundings(const Position &from, const Position &to) {
        ActionType actionType;

            if (to.x < from.x && to.y == from.y){
                actionType = N;
            }
            else if (to.x < from.x && to.y > from.y){
                actionType = NE;
            }
            else if (to.x == from.x && to.y > from.y){
                actionType = E;
            }
            else if (to.x > from.x && to.y > from.y){
                actionType = SE;
            }
            else if (to.x > from.x && to.y == from.y){
                actionType = S;
            }
            else if (to.x > from.x && to.y < from.y){
                actionType = SW;
            }
            else if (to.x == from.x && to.y < from.y){
                actionType = W;
            }
            else if (to.x < from.x && to.y < from.y){
                actionType = NW;
            }
            else{
                actionType = STAY;
            }
        return actionType;
    }


// isLegal function
//
// Precondition:
// Postcondition:
    bool Game::isLegal(const ActionType &ac, const Position &pos) const {
        Surroundings surroundings = getSurroundings(pos);
        bool isLegal = true;

        switch (ac) {
            case N:
                if (surroundings.array[1] == INACCESSIBLE) {
                    isLegal = false;
                }
                break;
            case NE:
                if (surroundings.array[2] == INACCESSIBLE) {
                    isLegal = false;
                }
                break;
            case E:
                if (surroundings.array[5] == INACCESSIBLE) {
                    isLegal = false;
                }
                break;
            case SE:
                if (surroundings.array[8] == INACCESSIBLE) {
                    isLegal = false;
                }
                break;
            case S:
                if (surroundings.array[7] == INACCESSIBLE) {
                    isLegal = false;
                }
                break;
            case SW:
                if (surroundings.array[6] == INACCESSIBLE) {
                    isLegal = false;
                }
                break;
            case W:
                if (surroundings.array[3] == INACCESSIBLE) {
                    isLegal = false;
                }
                break;
            case NW:
                if (surroundings.array[0] == INACCESSIBLE) {
                    isLegal = false;
                }
                break;
            case STAY:
                isLegal = true;
                break;
        }
        return isLegal;
    }


// move Function
//
// Precondition:
// Postcondition:
    const Position Game::move(const Position &pos, const ActionType &ac) const {
        if (isLegal(ac, pos)) {

            int new_X = pos.x;
            int new_Y = pos.y;

            switch (ac) {
                case N:
                    new_X--;
                    break;
                case NE:
                    new_X--;
                    new_Y++;
                    break;
                case E:
                    new_Y++;
                    break;
                case SE:
                    new_X++;
                    new_Y++;
                    break;
                case S:
                    new_X++;
                    break;
                case SW:
                    new_X++;
                    new_Y--;
                    break;
                case W:
                    new_Y--;
                    break;
                case NW:
                    new_X--;
                    new_Y--;
                    break;
                default:
                    break;
            }
            Position new_Pos((unsigned) new_X, (unsigned) new_Y);
            return new_Pos;
        }
    }



// round Function
//
// Precondition:
// Postcondition:
    void Game::round() {

        std::set<Piece*> game_Round;

        //insert game grid into the <set>
        for (auto it = __grid.begin(); it != __grid.end(); ++it) {
            if (*it) {
                game_Round.insert(game_Round.end(), *it);
                (*it)->setTurned(false);
            }
        }

        for (auto it = game_Round.begin(); it != game_Round.end(); it++) {
            if (!(*it)->getTurned()) {
                (*it)->setTurned(true);
                (*it)->age();

                ActionType action = (*it)->takeTurn(getSurroundings((*it)->getPosition()));
                Position orig_Pos = (*it)->getPosition();
                Position new_Pos = move(orig_Pos, action);

                if (orig_Pos.x != new_Pos.x || orig_Pos.y != new_Pos.y) {
                    Piece *game_Piece = __grid[(new_Pos.x * __width) + new_Pos.y];
                    if (game_Piece) {
                        (*(*it) * *game_Piece);
                        if ((*it)->getPosition().x != orig_Pos.x || (*it)->getPosition().y != orig_Pos.y) {
                            __grid[(orig_Pos.x * __width) + orig_Pos.y] = game_Piece;
                            __grid[(new_Pos.x * __width) + new_Pos.y ] = (*it);
                        }
                    } else {
                        (*it)->setPosition(new_Pos);
                        __grid[(orig_Pos.x * __width) + orig_Pos.y] = nullptr;
                        __grid[(new_Pos.x * __width) + new_Pos.y ] = (*it);
                    }
                }
            }
        }

        for (unsigned int index = 0; index < __grid.size(); index++) {
            if (__grid[index] && !(__grid[index]->isViable())) {
                __grid[index] = nullptr;
            }
        }

        if (getNumPieces() < 2  || getNumResources() <= 0) {
            __status = OVER;
        }
        __round++;
    }

// play Function
//
// Precondition:
// Postcondition:
        void Game::play(bool verbose) {
            __verbose = verbose;
            __status = PLAYING;

            std::cout << std::endl;
            std::cout << *this;

            while(__status != OVER) {
                round();
                if(verbose){
                    std::cout << *this;
                }
            }

            if(!verbose) {
                std::cout << *this;
            }
        }

}//end namespace gaming


