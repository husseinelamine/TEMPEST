#include "Enemy.hpp"

Enemy::Enemy(){
}
Enemy::Enemy(std::shared_ptr<Terrain> terrain, int index){
    this->index = index;
    this->total_duration = 3000;
    this->status = true;
    this->deleted = false;
    setTerrain(terrain);
    setTouch(false);
    initPosition();
}
Enemy::~Enemy(){
}
bool Enemy::isDeleted(){
    return this->deleted;
}
void Enemy::setTerrain(std::shared_ptr<Terrain> terrain){
    this->terrain = terrain;
}
void Enemy::setTouch(bool touch){
    this->touched = touch;
}
std::shared_ptr<Terrain> Enemy::getTerrain(){
    return terrain;
}
std::vector<Point> Enemy::getEnemy(){
    return enemy;
}
std::vector<FireBall> Enemy::getFire(){
    return fireballs;
}
int Enemy::getIndex(){
    return index;
}
bool Enemy::getStatus(){
    return status;
}
void Enemy::initPosition(){
    enemy.clear();
    std::vector<Point> petit = terrain->getPetit();
    Point a = petit[index];
    Point b = petit[(index+1)%petit.size()];

    enemy.push_back(a);
    enemy.push_back(b);
    enemy.push_back(homothety(b, 1.05));
    enemy.push_back(homothety(a, 1.05));

    enemy0.push_back(a);
    enemy0.push_back(b);
    enemy0.push_back(homothety(b, 1.05));
    enemy0.push_back(homothety(a, 1.05));

    start_time = SDL_GetTicks();
}

void Enemy::calculatePosition(float h){
    Point center = terrain->getCenterHomo();
    for(std::size_t i = 0; i < enemy.size();i++){
        enemy[i] = homothety(enemy0[i], h);
    }
}
Point Enemy::homothety(Point p, float h){
    Point center = terrain->getCenterHomo();
    Point p1{(center.x - p.x) * (-h) + center.x,
            (center.y - p.y) * (-h) + center.y};
    return p1;
}
void Enemy::moveEnemy(){
    
    Uint32 current_time = SDL_GetTicks();
    float ratio = (current_time - start_time) / (float)total_duration;
    if(ratio + 0.14 > 1){
        ratio = 1-0.14;
        if(touched){
            status = false;
        }
        else{
            deleted = true;
        }
    }
    calculatePosition(7*(ratio+0.14));
}

void Enemy::createFire(){
    fireballs.push_back(FireBall{enemy[0], enemy[1], index, terrain});
}
void Enemy::moveFire(){
    for(std::size_t i = 0; i < fireballs.size();i++){
        if(fireballs[i].isfinished){
            fireballs.erase(fireballs.begin()+i);
        }
        else{
            fireballs[i].moveFireBall();
        }
    }
}
