#include"PolyNiv1.hpp"
PolyNiv1::PolyNiv1(){ 
}
PolyNiv1::~PolyNiv1(){
}
std::vector<Point> PolyNiv1::getPoly(Point center) const{
    std::vector<Point> p;
    float radius = 50.0;
    int nb_pts_tmp = 17;
    double theta = 360.0f / nb_pts_tmp;
    double current_theta = theta;
    for(int i = 1; i <= nb_pts_tmp; i++){
        int x_current = center.x + radius * sin(2 * M_PI / nb_pts_tmp * i + 1/1000.0);
        int y_current = center.y + radius * cos(2 * M_PI / nb_pts_tmp * i + 1/1000.0);
        p.push_back({x_current, y_current});
        current_theta += theta;
    }
    return p;
}