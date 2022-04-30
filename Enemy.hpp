#ifndef Enemy_hpp
#define Enemy_hpp


#include "Point.hpp"
#include "Terrain.hpp"
#include "FireBall.hpp"

#include <SDL2/SDL.h>

#include <memory>
class Enemy{
public:
    Enemy();
    Enemy(std::shared_ptr<Terrain> terrain, int index);
    ~Enemy();
    void setTerrain(std::shared_ptr<Terrain> terrain);
    std::shared_ptr<Terrain> getTerrain();
    void calculatePosition(float h);
    void moveEnemy();
    void moveFire();
    std::vector<Point> getEnemy();
    void initPosition();
    void createFire();
    std::vector<FireBall> getFire();
    Point homothety(Point p, float h);
    int getIndex();
    void setTouch(bool touch);
    int getState();
    bool getStatus();
    bool isDeleted();
    int index; 
private:
    std::vector<Point> enemy, enemy0;
    std::shared_ptr<Terrain> terrain;
    Uint32 start_time;
    Uint32 total_duration;
    std::vector<FireBall> fireballs;
    bool touched;
    bool status;
    bool deleted;
};

#endif