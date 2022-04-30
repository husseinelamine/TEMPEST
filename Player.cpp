#include "Player.hpp"

Player::Player(){
}
Player::Player(std::shared_ptr<Terrain> terrain){
    this->index = 0;
    this->ratio = 0.7;
    setTerrain(terrain);
    calculatePostion();
    
}
Player::~Player(){
}
void Player::setTerrain(std::shared_ptr<Terrain> terrain){
    this->terrain = terrain;
}
std::shared_ptr<Terrain> Player::getTerrain(){
    return terrain;
}
std::vector<Point> Player::getPlayer(){
    return player;
}
int Player::getIndex(){
    return index;
}
void Player::calculatePostion(){
    player.clear();
    float distance = terrain->getRadius();
    std::vector<Point> grand = terrain->getGrand();
    Point p1 = grand[index];
    Point p2 = grand[(index+1)%grand.size()];
    Point center = terrain->getCenter();
    Point milieu;
    milieu = {(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};
    Point t_vector = {milieu.x - center.x, milieu.y - center.y};
    float norm = sqrt(t_vector.x * t_vector.x + t_vector.y * t_vector.y);
    t_vector.x = static_cast<int>(static_cast<double>(t_vector.x)*(distance/norm));
    t_vector.y = static_cast<int>(static_cast<double>(t_vector.y)*(distance/norm));
    Point translated = {milieu.x + t_vector.x, milieu.y + t_vector.y};
    player.push_back(translated);
    player.push_back(p1);
    float distance2 = distance*ratio;
    t_vector = {milieu.x - center.x, milieu.y - center.y};
    t_vector.x = static_cast<int>(static_cast<double>(t_vector.x)*(distance2/norm));
    t_vector.y = static_cast<int>(static_cast<double>(t_vector.y)*(distance2/norm));
    Point translated2 = {milieu.x + t_vector.x, milieu.y + t_vector.y};
    player.push_back(translated2);
    player.push_back(p2);
}
void Player::movePlayer(int direction){
    if(direction == PLAYER_RIGHT){
        index = (index+1)%terrain->getGrand().size();
    }
    else if(direction == PLAYER_LEFT){
        if(index == 0){
            index = terrain->getGrand().size()-1;
        }
        else{
            index = (index-1)%terrain->getGrand().size();
        }
    }
    calculatePostion();
}
