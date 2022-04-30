#include "PolyNiv2.hpp"
PolyNiv2::PolyNiv2(){ 
}
PolyNiv2::~PolyNiv2(){
}
std::vector<Point> PolyNiv2::getPoly(Point center) const{
    std::vector<Point> p;
    int nb_points = 16;
    float radius = 50.0;
    Point current = {center.x- static_cast<int>(radius/2.0), center.y-static_cast<int>(radius/2.0)};
    p.push_back(current);
    for (int i = nb_points; i >= 1; i--)
    {
        int q = static_cast<int>(4.0f * i / static_cast<float>(nb_points));
        //int mod = 4 * i % nb_points;
        switch (q)
        {
            case 3:
                current.x += static_cast<int>(4.0f * radius / static_cast<float>(nb_points));
                p.push_back(current);
                break;
            case 2:
                current.y += static_cast<int>(4.0f * radius / static_cast<float>(nb_points));
                p.push_back(current);
                break;
            case 1:
                current.x -= static_cast<int>(4.0f * radius / static_cast<float>(nb_points));
                p.push_back(current);
                break;
            case 0:
                current.y -= static_cast<int>(4.0f * radius / static_cast<float>(nb_points));
                p.push_back(current);
                break;
        }
    }
    return p;
}