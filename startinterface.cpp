#include"startinterface.h"
#include"points.h"
#include<windows.h>
startinterface::startinterface()
{
    speed=35;
    startsnake.emplace_back(points(0,14));   //贪吃蛇身体
    startsnake.emplace_back(points(1,14));
    startsnake.emplace_back(points(2,15));
    startsnake.emplace_back(points(3,16));
    startsnake.emplace_back(points(4,17));
    startsnake.emplace_back(points(5,18));
    startsnake.emplace_back(points(6,17));
    startsnake.emplace_back(points(7,16));
    startsnake.emplace_back(points(8,15));
    startsnake.emplace_back(points(9,14));


    textsnake.emplace_back(points(-26, 14));//S
    textsnake.emplace_back(points(-25, 14));
    textsnake.emplace_back(points(-27, 15));
    textsnake.emplace_back(points(-26, 16));
    textsnake.emplace_back(points(-25, 17));
    textsnake.emplace_back(points(-27, 18));
    textsnake.emplace_back(points(-26, 18));

    textsnake.emplace_back(points(-23, 14));//N
    textsnake.emplace_back(points(-23, 15));
    textsnake.emplace_back(points(-23, 16));
    textsnake.emplace_back(points(-23, 17));
    textsnake.emplace_back(points(-23, 18));
    textsnake.emplace_back(points(-22, 15));
    textsnake.emplace_back(points(-21, 16));
    textsnake.emplace_back(points(-20, 17));
    textsnake.emplace_back(points(-19, 14));
    textsnake.emplace_back(points(-19, 15));
    textsnake.emplace_back(points(-19, 16));
    textsnake.emplace_back(points(-19, 17));
    textsnake.emplace_back(points(-19, 18));

    textsnake.emplace_back(points(-17, 18));//A
    textsnake.emplace_back(points(-16, 17));
    textsnake.emplace_back(points(-15, 16));
    textsnake.emplace_back(points(-14, 15));
    textsnake.emplace_back(points(-14, 16));
    textsnake.emplace_back(points(-13, 14));
    textsnake.emplace_back(points(-13, 16));
    textsnake.emplace_back(points(-12, 15));
    textsnake.emplace_back(points(-12, 16));
    textsnake.emplace_back(points(-11, 16));
    textsnake.emplace_back(points(-10, 17));
    textsnake.emplace_back(points(-9, 18));

    textsnake.emplace_back(points(-7, 14));//K
    textsnake.emplace_back(points(-7, 15));
    textsnake.emplace_back(points(-7, 16));
    textsnake.emplace_back(points(-7, 17));
    textsnake.emplace_back(points(-7, 18));
    textsnake.emplace_back(points(-6, 16));
    textsnake.emplace_back(points(-5, 15));
    textsnake.emplace_back(points(-5, 17));
    textsnake.emplace_back(points(-4, 14));
    textsnake.emplace_back(points(-4, 18));

    textsnake.emplace_back(points(-2, 14));//E
    textsnake.emplace_back(points(-2, 15));
    textsnake.emplace_back(points(-2, 16));
    textsnake.emplace_back(points(-2, 17));
    textsnake.emplace_back(points(-2, 18));
    textsnake.emplace_back(points(-1, 14));
    textsnake.emplace_back(points(-1, 16));
    textsnake.emplace_back(points(-1, 18));
    textsnake.emplace_back(points(0, 14));
    textsnake.emplace_back(points(0, 16));
    textsnake.emplace_back(points(0, 18));
    
}
void startinterface::printfirst()     //贪吃蛇出现
{
    for(auto &point :startsnake)
    {
        point.print();
        Sleep(speed);
    }
}
void startinterface::printsecond()
{
    for(int i=10;i<40;i++)      //蛇头不能到边界，因为要留存打印的位置，最后应该是78的地方；
    {
        int j=((i-2)%8<4)?(15+(i-2)%8):(21-(i-2)%8);
        startsnake.emplace_back(i,j);
        startsnake.back().print();
        startsnake.front().clear();
        startsnake.pop_front();
        Sleep(speed);
    }
}
void startinterface::printthird()
{
    while(!startsnake.empty()||textsnake.back().get_x()<33)
    {
        if(!startsnake.empty())
        {
            startsnake.front().clear();
            startsnake.pop_front();
        }  
        cleartext();//清除已有文字
        printtext();//重新打印文字
        Sleep(speed);

    }

}
void startinterface::cleartext()
{
    for(auto &point :textsnake)
    {
        if(point.get_x()>=0)
            point.clear();
        point.changeposition(point.get_x()+1,point.get_y());
    }
}
void startinterface::printtext()//将大于0的坐标都打印出来
{
    for(auto &point :textsnake)
    {
        if(point.get_x()>=0)
            point.print();
    }
}
void startinterface::action()
{
    printfirst();
    printsecond();
    printthird();
}