#ifndef PolyNiv2_hpp
#define PolyNiv2_hpp
#include"Terrain.hpp"
#include"Poly.hpp"
#include<cmath>
#include<vector>
#include"Point.hpp"
class PolyNiv2: public Poly
{
    public:
        PolyNiv2();
        ~PolyNiv2();
        std::vector<Point> getPoly(Point center) const override;
};
#endif