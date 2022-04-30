#include"PlayWindow.hpp"

PlayWindow::PlayWindow(){
    std::cout << "PlayWindow::PlayWindow()" << std::endl;
}
PlayWindow::PlayWindow(SDL_Renderer* renderer):MyWindow(renderer){
    std::cout << "PlayWindow::PlayWindow(SDL_Renderer* renderer)" << std::endl;  
}
PlayWindow::~PlayWindow(){
    std::cout << "PlayWindow::~PlayWindow()" << std::endl;
}
void PlayWindow::init(){
    std::cout << "PlayWindow::init()" << std::endl;
    game = std::make_shared<Game>(renderer);
}
void PlayWindow::draw(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    game->drawTerrain();  
    game->drawPlayer();
    game->drawEnemy();
    game->moveEnemies();
    game->drawEnemyFire();
    game->moveFire();
    game->createEnemies();
    if(!game->getStatus()){
        std::cout << "Game Over" << std::endl;
        SDL_Delay(2000);
        Global::isRunning = false;
    }
    SDL_RenderPresent(renderer);
}
void PlayWindow::handleEvent(){
    //std::cout << "PlayWindow::handleEvent()" << std::endl;
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                    Global::isRunning = false;
                    break;
            case SDL_MOUSEBUTTONDOWN:
                std::cout << "Mouse button pressed" << std::endl;
                break;        
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                        std::cout << "PlayWindow::handleEvent() : SDLK_RIGHT" << std::endl;
                        game->movePlayer(PLAYER_RIGHT);
                        break;
                    case SDLK_LEFT:
                        std::cout << "PlayWindow::handleEvent() : SDLK_RIGHT" << std::endl;
                        game->movePlayer(PLAYER_LEFT);
                        break;
                    case 99:
                        break;
                    case 107:
                        break;
                    case SDLK_ESCAPE:
                        Global::isRunning = false;
                        break;
                    case SDLK_SPACE:
                        break;
                    case SDLK_RSHIFT: 
                        break;
                    default:
                        std::cout << "PlayWindow::handleEvent() : default" << std::endl;
                        std::cout << event.key.keysym.sym << std::endl;
                        break;
                }
                break;
            case SDL_KEYUP:
                switch(event.key.keysym.sym)
                {
                    case SDLK_RSHIFT:
                        break;
                    case 99:
                        break;
                    default:
                        break;
                }
                break;
        }
    }
    //std::cout << "PlayWindow::handleEvent()" << std::endl;
}
