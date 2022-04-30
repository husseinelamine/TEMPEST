#include "FireBall.hpp"


FireBall::FireBall(){
}
FireBall::FireBall(Point p1, Point p2, int index, std::shared_ptr<Terrain> terrain){
    this->index = 0;
    this->p1 = p1;
    this->p2 = p2;
    this->total_duration = 1500;
    this->rayon = 0.5;
    this->isfinished = false;
    setTerrain(terrain);
    initPosition();
}
FireBall::~FireBall(){
}
void FireBall::setTerrain(std::shared_ptr<Terrain> terrain){
    this->terrain = terrain;
}
std::shared_ptr<Terrain> FireBall::getTerrain(){
    return terrain;
}
std::vector<Point> FireBall::getFireBall(){
    return fireball;
}
void FireBall::initPosition(){
    fireball.clear();
    fireball0.clear();
    
    Point a{(4*p1.x + 6 * p2.x)/10, (4*p1.y + 6 * p2.y)/10};
    Point b{(6*p1.x + 4 * p2.x)/10, (6*p1.y + 4 * p2.y)/10};
    Point milieuCarre = homothety({(p1.x+p2.x)/2, (p1.y+p2.y)/2}, 1.005);
    fireball.push_back(a);
    fireball.push_back(milieuCarre);
    fireball.push_back(b);

    fireball0.push_back(a);
    fireball0.push_back(milieuCarre);
    fireball0.push_back(b);

    start_time = SDL_GetTicks();

}
void FireBall::calculatePosition(float h){
    for(std::size_t i = 0; i < fireball.size();i++){
        fireball[i] = homothety(fireball0[i], h);
    }
    
}
Point FireBall::homothety(Point p, float h){
    Point center = terrain->getCenterHomo();
    Point p1{(center.x - p.x) * (-h) + center.x,
            (center.y - p.y) * (-h) + center.y};
    return p1;
}
void FireBall::moveFireBall(){
    Uint32 current_time = SDL_GetTicks();
    float ratio = (current_time - start_time) / (float)total_duration;
    float defer = 0.2;
    if(ratio + defer > 1){
        this->isfinished = true;
    }
    calculatePosition(7*(ratio+defer));
}
