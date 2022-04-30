#ifndef Application_hpp
#define Application_hpp

#include"MyWindow.hpp"
#include"StartWindow.hpp"
#include"PlayWindow.hpp"
#include "Global.hpp"
#include<iostream>
#include<memory>
#include<cstdlib>
#include<SDL2/SDL.h>

class Application{
public:
    Application();
    Application(const char* title, int xpos, int ypos, int width, int height, Uint32 flags);
    ~Application();
    void run();
    bool running() { return Global::isRunning; }
private: 
    std::shared_ptr<MyWindow> mywindow;
    const char* title;
    int x_pos;
    int y_pos;
    int width;
    int height;
    Uint32 flags;
    SDL_Window* window;
    SDL_Renderer* renderer;
    Uint32 black[4];

    void showWindow();
    void render();
    
};


#endif