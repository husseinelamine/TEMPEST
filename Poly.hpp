#ifndef Poly_hpp
#define Poly_hpp
#include<vector>
#include"Point.hpp"
#include <iostream>
class Poly{
    public:
        Poly();
        ~Poly();
        virtual std::vector<Point> getPoly(Point center) const = 0;
};

#endif