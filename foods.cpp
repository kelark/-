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

void foods::drawfoods(snakes &csnake)   //����rand����������ȡʳ�����꣬���������غ������»�ȡ
{
    while(1)
    {
     int temp_x=rand()%30;           //��������ʳ������2-29�ķ�Χ������ͼ���棻
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
    std::cout<<"��";
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
    std::cout<<"------------------------------------------";//������"
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
        std::cout<<"��";
        flashflag=true;  //�Ƿ�����˸���
        bigflag=true;   //�Ƿ�����ʱʳ����
        break;    
    }
}
int foods::get_cnt()
{
    return cnt;
}
void foods::flashbigfoods()       //�������ѭ���������ﵽ��˸Ч��
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
        std::cout<<"��";
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


