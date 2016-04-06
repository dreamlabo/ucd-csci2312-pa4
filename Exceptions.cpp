

#include "Exceptions.h"



namespace Gaming{

//******************************
// Class     GamingException   *
//******************************

// setName Function
// returns __name
// Precondition:
// Postcondition: __name is returned
    void GamingException::setName(std::string name) {
        __name = name;
    }

    std::ostream &operator<<(std::ostream &os, const GamingException &ex) {
        os << ex.__name << std::endl;

        return os;

    }
//***********************************************************************************

//******************************
// Class     DimensionEx       *
//******************************
// DimensionEx Constructor
    Gaming::DimensionEx::DimensionEx(unsigned expWidth, unsigned expHeight, unsigned width, unsigned height):
        __exp_height(expHeight), __exp_width(expHeight), __width(width), __height(height){
        setName("DimensionEx");
    }


// getExpWidth Function  (DimensionEx)
// returns __exp_width
// Precondition:
// Postcondition:  __exp_width is returned
    unsigned DimensionEx::getExpWidth() const {
                return __exp_width;
    }


// getExpHeight Function  (DimensionEx)
// returns __exp_height
// Precondition:
// Postcondition:  __exp_height is returned
    unsigned DimensionEx::getExpHeight() const {
        return __exp_height;
    }


// getWidth Function  (DimensionEx)
// returns __exp_height
// Precondition:
// Postcondition:  __width is returned
    unsigned DimensionEx::getWidth() const {
        return __width;
    }


// getHeight Function  (DimensionEx)
// returns __height;
// Precondition:
// Postcondition:  __height; is returned
    unsigned DimensionEx::getHeight() const {
        return __height;
    }



//***************************************************************************************

//****************************************
// Class     InsufficientDimensionsEx    *
//****************************************
//   __print_args Function
    void InsufficientDimensionsEx::__print_args(std::ostream &os) const {
        os << "InsufficientDimensionsEx : ";
        os << "Width: " << __width;
        os << "Height: " << __height;
        os << "Exp. Width: " << __exp_width;
        os << "Exp. Height: " << __exp_height;

    }

   InsufficientDimensionsEx::InsufficientDimensionsEx(unsigned minWidth, unsigned minHeight, unsigned width,
                                                       unsigned height)
        : DimensionEx(minWidth, minHeight, width, height) {
             setName("InsufficientDimensionsEx");
   }




}// end of Gaming namespace

















