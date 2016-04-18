

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
        os << ex.getName() << std::endl;
        return os;
    }


//***********************************************************************************

//******************************
// Class     DimensionEx       *
//******************************
// DimensionEx Constructor
    Gaming::DimensionEx::DimensionEx(unsigned expWidth, unsigned expHeight, unsigned width, unsigned height):
        __exp_height(expHeight),
        __exp_width(expWidth),
        __width(width),
        __height(height){
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



    void OutOfBoundsEx::__print_args(std::ostream &os) const {
        os << getName();
        os << "Width: " << getExpWidth();
        os << "Height: " << getHeight();
        os << "Exp. Width: " << getExpWidth();
        os << "Exp. Height: " << getHeight();

    }


  OutOfBoundsEx::OutOfBoundsEx(unsigned maxWidth, unsigned maxHeight, unsigned width, unsigned height)
          : DimensionEx(maxWidth, maxHeight, width, height){
             setName("OutOfBoundsEx");
    }






//*******************************************************************************************

//****************************************
//  Class      PositionEx                *
//    (Inherents from GamingException)   *
//****************************************
PositionEx::PositionEx(unsigned x, unsigned y)
            : __x(x), __y(y) {
            setName("PositionEx");
    }


// __print_args function
//
// Precondition: a PositionEx exception has been thrown
// Postcondition: the
    void PositionEx::__print_args(std::ostream &os) const {
         os << "X: " << __x << ", " << "Y: " << __y << std::endl;
    }

//************************************************************************************************
//****************************************
//  Class    PositionNonemptyEx          *
//        (Inherents from PositionEx)    *
//****************************************
    Gaming::PositionNonemptyEx::PositionNonemptyEx(unsigned x, unsigned y)
        : PositionEx(x,y){
   // setName("PositionNonemptyEx");
    }

//************************************************************************************************
//****************************************
//  Class    PositionEmptyEx             *
//        (Inherents from PositionEx)    *
//****************************************
    Gaming::PositionEmptyEx::PositionEmptyEx(unsigned x, unsigned y)
            : PositionEx(x,y) {
        setName("PositionEmptyEx");

    }

    void Gaming::PosVectorEmptyEx::__print_args(std::ostream &os) const {
        os << getName() << std::endl;
    }

    PosVectorEmptyEx::PosVectorEmptyEx() {
        setName("PosVectorEmptyEx");
    }


}// end of Gaming namespace































