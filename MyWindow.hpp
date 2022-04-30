#ifndef Window_hpp
#define Window_hpp
#include<SDL2/SDL.h>
#include<iostream>
#include<memory>
class MyWindow{
public:
    MyWindow();
    MyWindow(SDL_Renderer* renderer);
    ~MyWindow();
    virtual void draw();
    virtual void handleEvent();
    virtual void init();
    void setRenderer(SDL_Renderer* renderer);
protected:
    SDL_Renderer* renderer;
};
 

#endif