#ifndef Game_hpp
#define Game_hpp

#include "Point.hpp"
#include "Terrain.hpp"
#include "Player.hpp"
#include "PolyNiv1.hpp"
#include "PolyNiv2.hpp"
#include "Global.hpp"
#include "Enemy.hpp"
#include "FireBall.hpp"

#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include <iostream>
#include <cmath>
class Game{
public:
    Game();
    Game(SDL_Renderer *renderer);
    ~Game();
    void setScore(int score);
    int getScore();
    void setLevel(int level);
    int getLevel();
    void drawPlayer();
    void drawEnemy();
    void drawEnemyFire();
    void drawTerrain();
    void CreatePlayer();
    void createEnemies();
    void movePlayer(int direction);    
    void moveEnemies();
    void moveFire();
    void enemyCreateFire();  
    bool getStatus();

private:
    int score;
    int level;
    std::shared_ptr<Terrain> terrain;
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<Enemy>> enemies;
    SDL_Renderer *renderer;
    bool status;
};

#endif