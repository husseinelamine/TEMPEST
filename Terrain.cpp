#include "Terrain.hpp"

Terrain::Terrain():
    h(7.0), center_move(1.5), radius(25.0)
{
    center.x = 0;
    center.y = 0;
    center_homo.x = center.x;
    center_homo.y = center.y + radius / center_move;
}
Terrain::Terrain(Point p, const Poly& pol):
    h(7.0), center_move(1.5), radius(25.0)
{
    center.x = p.x;
    center.y = p.y;
    center_homo.x = center.x;
    center_homo.y = center.y + radius / center_move;
    p_petit = pol.getPoly(center);
    polyFinal();
}
Terrain::~Terrain(){
    
}

Point Terrain::homothety(Point p){
    Point p1;
    float h1 = -h;
    p1.x = (center_homo.x - p.x) * h1 + center_homo.x;
    p1.y = (center_homo.y - p.y) * h1 + center_homo.y;
    return p1;    
}
void Terrain::polyFinal(){
    p_grand.clear();
    for(std::size_t i = 0; i < p_petit.size(); i++){
        p_grand.push_back(homothety(p_petit[i]));
    }
}
std::vector<Point> Terrain::getPetit(){
    return p_petit;
}
std::vector<Point> Terrain::getGrand(){
    return p_grand;
}
Point Terrain::getCenter(){
    return center;
}
Point Terrain::getCenterHomo(){
    return center_homo;
}
float Terrain::getRadius(){
    return radius;
}