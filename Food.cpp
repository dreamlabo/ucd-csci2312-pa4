// Todd Labo
//PA-4

#include "Game.h"
#include "Resource.h"
#include "Food.h"


namespace Gaming {

    const char Food::FOOD_ID = 'F';


// food constructor
    Food::Food(const Gaming::Game &g, const Gaming::Position &p, double capacity)
            : Resource (g, p, capacity){

    }



    Food::~Food() {

    }

// print function
    void Food::print(std::ostream &os) const {
       os <<  FOOD_ID;
    }


} // end of namespace Gaming


