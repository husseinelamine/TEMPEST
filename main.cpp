#include"Application.hpp"
#include<iostream>

int main(){
    Application app{"SDL Tutorial", 100, 100, 1920, 1080, SDL_WINDOW_SHOWN|SDL_WINDOW_ALLOW_HIGHDPI|SDL_WINDOW_FULLSCREEN_DESKTOP};
    app.run();
    
    return 1;
}