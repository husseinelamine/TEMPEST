#ifndef FireBall_hpp
#define FireBall_hpp


#include "Point.hpp"
#include "Terrain.hpp"
#include <SDL2/SDL.h>

#include <memory>
class FireBall{
public:
    FireBall();
    FireBall(Point p1, Point p2, int index, std::shared_ptr<Terrain> terrain);
    ~FireBall();
    void setTerrain(std::shared_ptr<Terrain> terrain);
    std::shared_ptr<Terrain> getTerrain();
    void calculatePosition(float h);
    void moveFireBall();
    std::vector<Point> getFireBall();
    void initPosition();
    void setTerrain(Point position,std::shared_ptr<Terrain> terrain);
    Point homothety(Point p, float h);
    bool isfinished;
private:
    int index;
    std::vector<Point> fireball, fireball0;
    std::shared_ptr<Terrain> terrain;
    Uint32 start_time;
    Uint32 total_duration;
    Point p1, p2;
    float rayon;
    };

#endif