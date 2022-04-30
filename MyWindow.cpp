#include"MyWindow.hpp"

MyWindow::MyWindow()
{
    //ctor
}
MyWindow::MyWindow(SDL_Renderer* renderer):renderer(renderer)
{
    //ctor
}
void MyWindow::setRenderer(SDL_Renderer* renderer){
    this->renderer = renderer;
}

MyWindow::~MyWindow()
{
    //dtor
}
void MyWindow::draw()
{
    std::cout << "MyWindow::draw()" << std::endl;
}

void MyWindow::handleEvent()
{
    std::cout << "MyWindow::handleEvent()" << std::endl;
}
void MyWindow::init()
{
    std::cout << "MyWindow::init()" << std::endl;
}

