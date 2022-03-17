#include"foods.h"
#include<iostream>
#include"tool.h"
#include<cstdlib>
#include"points.h"

foods::foods()
{
    cnt=0;
    x=y=big_x=big_y=0;
    flashflag=false;
    bigflag=false;
    progressbar=0;
}

void foods::drawfoods(snakes &csnake)   //利用rand（）函数获取食物坐标，若与蛇身重合则重新获取
{
    while(1)
    {
     int temp_x=rand()%30;           //我们想让食物落在2-29的范围，即地图里面；
     int temp_y=rand()%30;
     if(temp_x<2) temp_x +=2;
     if(temp_y<2) temp_y +=2;
     bool flag=false;
     for(auto & point:csnake.snake)
     {
         if((point.get_x()==temp_x&&point.get_y()==temp_y)||(big_x==temp_x&&big_y==temp_y))
         {
             flag==true;
             break;
         }
     }
     if(flag)
        continue;
    x=temp_x;
    y=temp_y;
    setcursorposition(x,y);
    setcolor(13);
    std::cout<<"★";
    cnt++;
    cnt =cnt%5;
    if(cnt==0)
    {
        drawbigfoods(csnake);
    }
    break;
    }

}

void foods::drawbigfoods(snakes & csnake)
{
    setcursorposition(5,0);
    setcolor(11);
    std::cout<<"------------------------------------------";//进度条"
    progressbar =42;
    while(1)
    {
        int temp_x=rand()%30;
        int temp_y=rand()%30;
        if(temp_x<2) temp_x +=2;
        if(temp_y<2) temp_y +=2;
        bool flag=false;
        for(auto &point :csnake.snake)
        {
            if((point.get_x()==temp_x&&point.get_y()==temp_y)||(temp_x==x&&temp_y==y))
                {   
                    flag=true;
                    break;
                }
        }
        if(flag)
            continue;
        big_x=temp_x;
        big_y=temp_y;
        setcursorposition(big_x,big_y);
        setcolor(18);
        std::cout<<"■";
        flashflag=true;  //是否有闪烁标记
        bigflag=true;   //是否有限时食物标记
        break;    
    }
}
int foods::get_cnt()
{
    return cnt;
}
void foods::flashbigfoods()       //这个函数循环进行来达到闪烁效果
{
    setcursorposition(big_x,big_y);
    setcolor(18);
    if(flashflag)
    {
        std::cout<<"  ";
        flashflag=false;
    }
    else
    {
        std::cout<<"■";
        flashflag=true;
    }
    setcursorposition(26,0);
    setcolor(11);
    for(int i=42;i>=progressbar;i--)
    {
        std::cout<<"\b \b";
    }
    progressbar--;
    if(progressbar==0)
    {
        setcursorposition(big_x,big_y);
        std::cout<<"  ";
        big_x=0;
        big_y=0;
        bigflag=false;
    }
}
bool foods::getbigflag()
{
    return bigflag;
}
int foods::getprogressbar()
{
    return progressbar;
}


