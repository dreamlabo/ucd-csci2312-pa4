// Todd Labo
//PA-4



#include <iomanip>
#include "Game.h"
#include "Resource.h"
#include "Food.h"


namespace Gaming {

    const char Food::FOOD_ID = 'F';


// food constructor
    Food::Food(const Gaming::Game &g, const Gaming::Position &p, double capacity)
            : Resource (g, p, capacity){
            __capacity = capacity;
    }


    Food::~Food() {

    }

// print function
    void Food::print(std::ostream &os) const {
       os <<  Food::FOOD_ID << std::setw(4)  << std::left <<Piece::__id;
    }


} // end of namespace Gaming


