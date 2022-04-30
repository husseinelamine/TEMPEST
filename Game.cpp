#include "Game.hpp"

Game::Game(){
    score = 0;
    level = 1;
}
Game::Game(SDL_Renderer *renderer){
    std::cout << "Game::Game(SDL_Renderer *renderer)" << std::endl;
    this->renderer = renderer;
    status = true;
    score = 0;
    level = 1;
    Point center;
    center.x = Global::width/2;
    center.y = static_cast<int>(0.7*Global::height);
    const PolyNiv1 &pol1{};
    const PolyNiv2 &pol2{};

    switch(level){
        case 1:
            terrain = std::make_shared<Terrain>(center, pol1);
            break;
        case 2:
            terrain = std::make_shared<Terrain>(center, pol2);
            break;
        default:
            break;
    }
    CreatePlayer();
}
Game::~Game(){
}
void Game::setLevel(int level){
    this->level = level;
}
int Game::getLevel(){
    return level;
}
bool Game::getStatus(){
    return status;
}
void Game::setScore(int score){
    this->score = score;
}
int Game::getScore(){
    return score;
}
void Game::drawTerrain(){
    std::vector<Point> petit = terrain->getPetit();
    std::vector<Point> grand = terrain->getGrand();
    SDL_SetRenderDrawColor(renderer, 127, 0, 255, 255);
    for(std::size_t i = 0; i < petit.size(); i++){
        SDL_RenderDrawLine(renderer, petit[i].x, petit[i].y, petit[(i+1)%petit.size()].x, petit[(i+1)%petit.size()].y);
        SDL_RenderDrawLine(renderer, grand[i].x, grand[i].y, grand[(i+1)%grand.size()].x, grand[(i+1)%grand.size()].y);
        SDL_RenderDrawLine(renderer, petit[i].x, petit[i].y, grand[i].x, grand[i].y);
    }
}
void Game::CreatePlayer(){
    std::shared_ptr<Player> p = std::make_shared<Player>(terrain);
    player = p;
}

void Game::createEnemies(){
    Uint32 current_time = SDL_GetTicks();
    float ratio = current_time % 700;
    if(ratio < 30){
        for(int i = 0; i < 1; i++){
            std::shared_ptr<Enemy> e = 
                std::make_shared<Enemy>(terrain, current_time % 17);
            this->enemies.push_back(e);
            e->createFire();
        }
    }
}

void Game::movePlayer(int direction){
    player->movePlayer(direction);
}

void Game::moveEnemies(){
    for(std::size_t i = 0; i < enemies.size(); i++){
        enemies[i]->moveEnemy();
    }
}
void Game::moveFire(){
    for(std::size_t i = 0; i < enemies.size(); i++){
        enemies[i]->moveFire();
        if(enemies[i]->isDeleted()){
            enemies.erase(enemies.begin() + i);
        }
        if(!enemies[i]->getStatus()){
            std::cout << "Enemy " << i << " is dead" << std::endl;
            status = false;
        }
        if(enemies[i]->getIndex() == player->getIndex()){
            enemies[i]->setTouch(true);
            std::cout << enemies[i]->getIndex() << " " << player->getIndex() << std::endl;

        }
        else{
            enemies[i]->setTouch(false);
            //std::cout << enemies[i]->getIndex() << " " << player->getIndex() << std::endl;
        }
        
    }
}

void Game::drawPlayer(){
    std::vector<Point> player_points = player->getPlayer();
    SDL_SetRenderDrawColor(renderer, 241, 211, 2, 255);

    for(std::size_t i = 0; i < player_points.size(); i++){
        SDL_RenderDrawLine(renderer, player_points[i].x, player_points[i].y, player_points[(i+1)%player_points.size()].x, player_points[(i+1)%player_points.size()].y);
    }
    
}

void Game::drawEnemy(){
    if(!enemies.size())
        return;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for(auto &e : enemies){
        std::vector<Point> enemy_points = e->getEnemy();
        //SDL_RenderDrawLine(renderer, enemy_points[0].x, enemy_points[0].y, enemy_points[1].x, enemy_points[1].y);
        SDL_RenderDrawLine(renderer, enemy_points[0].x, enemy_points[0].y, enemy_points[2].x, enemy_points[2].y);
        SDL_RenderDrawLine(renderer, enemy_points[1].x, enemy_points[1].y, enemy_points[3].x, enemy_points[3].y);
    }     
}
void Game::drawEnemyFire(){
    if(!enemies.size())
        return;
    SDL_SetRenderDrawColor(renderer, 255, 127, 0, 255);
    for(auto &e : enemies){
    std::vector<FireBall> enemy_fire_balls = e->getFire();
        for(auto &fb : enemy_fire_balls){
            std::vector<Point> enemy_fire_points = fb.getFireBall();
            SDL_RenderDrawLine(renderer, enemy_fire_points[0].x, enemy_fire_points[0].y, enemy_fire_points[1].x, enemy_fire_points[1].y);
            SDL_RenderDrawLine(renderer, enemy_fire_points[1].x, enemy_fire_points[1].y, enemy_fire_points[2].x, enemy_fire_points[2].y);
        }
    }
    
}
void Game::enemyCreateFire(){
    for(std::size_t i = 0; i < enemies.size(); i++){
        enemies[i]->createFire();
    }
}
