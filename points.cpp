#include"points.h"
#include<iostream>
#include"tool.h"
points::points(const int x,const int y)
{
    this->x=x;this->y=y;
}
void points::print()
{
    setcursorposition(x,y);
    std::cout<<"■";
}
void points::printcircle()
{
    setcursorposition(x,y);
    std::cout<<"●";
}
void points::clear()
{
    setcursorposition(x,y);
    std::cout<<"  ";
}
void points::changeposition(const int x,const int y)     //改变当前点的坐标
{
    this->x=x;
    this->y=y;
}
