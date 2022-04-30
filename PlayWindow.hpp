#ifndef PlayWindow_hpp
#define PlayWindow_hpp

#define PLAYER_RIGHT -1
#define PLAYER_LEFT 1

#include "MyWindow.hpp"
#include "Terrain.hpp"
#include "PolyNiv1.hpp"
#include "PolyNiv2.hpp"
#include "Global.hpp"
#include "Game.hpp"
#include<SDL2/SDL.h>
#include<iostream>


class PlayWindow: public MyWindow{
public:
    PlayWindow();
    PlayWindow(SDL_Renderer *renderer);
    ~PlayWindow();
    void draw() override;
    void handleEvent() override;
    void init() override;
    Uint32 ticks;
    private:
        std::shared_ptr<Game> game;
        

};
#endif