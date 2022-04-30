#ifndef PolyNiv1_hpp
#define PolyNiv1_hpp
#include"Terrain.hpp"
#include"Poly.hpp"
#include<cmath>
#include<vector>
#include"Point.hpp"
class PolyNiv1: public Poly
{
    public:
        PolyNiv1();
        ~PolyNiv1();
        std::vector<Point> getPoly(Point center) const override;
};
#endif