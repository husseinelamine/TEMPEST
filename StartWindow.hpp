#ifndef StartWindow_hpp
#define StartWindow_hpp

#include "MyWindow.hpp"
#include<SDL2/SDL.h>
#include<iostream>


class StartWindow: public MyWindow{
public:
    StartWindow();
    StartWindow(SDL_Renderer *renderer);
    ~StartWindow();
    void draw() override;
    void handleEvent() override;
};
#endif