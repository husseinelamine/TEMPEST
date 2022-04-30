#include "Global.hpp"

int Global::width = 800;
int Global::height = 600;
bool Global::isRunning = true;
void Global::setWidth(int w){
    width = w;
}
void Global::setHeight(int h){
    height = h;
}
int Global::getWidth(){
    return width;
}
int Global::getHeight(){
    return height;
}