#include"StartWindow.hpp"

StartWindow::StartWindow(){
    std::cout << "StartWindow::StartWindow()" << std::endl;
}
StartWindow::StartWindow(SDL_Renderer* renderer):MyWindow(renderer){
    std::cout << "StartWindow::StartWindow(SDL_Renderer* renderer)" << std::endl;
}
StartWindow::~StartWindow(){
    std::cout << "StartWindow::~StartWindow()" << std::endl;
}
void StartWindow::draw(){

    std::cout << "StartWindow::draw()" << std::endl;
    SDL_SetRenderDrawColor(renderer, 241, 211, 2, 255);
    //SDL_RenderDrawPoint(renderer, x, y);
    SDL_RenderDrawLine(renderer, 200, 200, 300, 300);
    SDL_RenderPresent(renderer);

}
void StartWindow::handleEvent(){
    std::cout << "StartWindow::handleEvent()" << std::endl;
}
