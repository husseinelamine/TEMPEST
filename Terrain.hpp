#ifndef Terrain_hpp
#define Terrain_hpp

#include"Point.hpp"
#include"Poly.hpp"
#include <vector>
#include <cmath>
#include <iostream>
class Terrain{
    public:
        Terrain();
        Terrain(Point c, const Poly& p);
        ~Terrain();
        std::vector<Point> getPetit();
        std::vector<Point> getGrand();
        Point getCenter();
        Point getCenterHomo();
        float getRadius();

    private:
        Point center, center_homo;
        std::vector<Point> p_petit, p_grand;
        float h, center_move, radius;
        Point homothety(Point p);
        void polyFinal();
};

#endif