#include"Application.hpp"


Application::Application(){
    mywindow = nullptr;
    Global::isRunning = true;
    black[0] = 0;
    black[1] = 0;
    black[2] = 0;
    black[3] = 255;
}

Application::Application(const char* title, int xpos, int ypos, int width, int height, Uint32 flags):
    title(title), x_pos(xpos), y_pos(ypos), width(width), height(height), flags(flags)
{
    mywindow = std::make_shared<PlayWindow>(renderer);
    Global::isRunning = true;
    black[0] = 255;
    black[1] = 0;
    black[2] = 0;
    black[3] = 255;
}

Application::~Application(){
}

void Application::showWindow(){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr<<"Pb init SDL"<< std::endl;
        return;
    }
    window = SDL_CreateWindow(title, x_pos, y_pos, width, height, flags);
    if (window == NULL)
    {
        std::cerr<<"Pb create window"<< std::endl;
        return;
    }
    Global::setWidth(width);
    Global::setHeight(height);
    renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        std::cerr<<"Pb create renderer"<< std::endl;
        return;
    }
    mywindow->setRenderer(renderer);
}

void Application::render(){
    SDL_SetRenderDrawColor(renderer, black[0], black[1], black[2], black[3]);
    SDL_RenderPresent(renderer);
}

void Application::run(){
    showWindow();
    mywindow->init();
    while(running()){
        mywindow->handleEvent();
        mywindow->draw();
    }
    SDL_Quit();
}