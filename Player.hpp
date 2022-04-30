#ifndef Player_hpp
#define Player_hpp

#define PLAYER_RIGHT -1
#define PLAYER_LEFT 1

#include "Point.hpp"
#include "Terrain.hpp"

#include <memory>
class Player{
public:
    Player();
    Player(std::shared_ptr<Terrain> terrain);
    ~Player();
    void setTerrain(std::shared_ptr<Terrain> terrain);
    std::shared_ptr<Terrain> getTerrain();
    void calculatePostion();
    void movePlayer(int direction);
    std::vector<Point> getPlayer();
    int getIndex();

private:
    int index;
    float ratio;
    std::vector<Point> player;
    std::shared_ptr<Terrain> terrain;

};

#endif