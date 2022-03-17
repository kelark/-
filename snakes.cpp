#include"snakes.h"
#include<deque>
#include<conio.h>  //kbhit()
#include"points.h"
#include"tool.h"
#include"foods.h"
#include<iostream>

 snakes::snakes()
{
    snake.emplace_back(points(14,8));
    snake.emplace_back(points(15,8));
    snake.emplace_back(points(16,8));
    direction =Direction::DOWN;
}
void snakes::initsnake()
{
    for(auto &point :snake)
        point.printcircle();
}

void snakes::move()   //������
{
    switch(direction)
    {
        case Direction::DOWN:
        snake.emplace_back(points(snake.back().get_x(),snake.back().get_y()+1));
        break;
        case Direction::UP:
        snake.emplace_back(points(snake.back().get_x(),snake.back().get_y()-1));
        break;
        case Direction::LEFT:
        snake.emplace_back(points(snake.back().get_x()-1,snake.back().get_y()));
        break;
        case Direction::RIGHT:
        snake.emplace_back(points(snake.back().get_x()+1,snake.back().get_y()));
        break;
        default:
        break;
    }
    setcolor(14);
    snake.back().printcircle();

}

void snakes::normalmove()  //�����ƶ���ͷ������β����
{
    move();
    snake.front().clear();
    snake.pop_front();
}

bool snakes::overedge()    //���ͼ�й�  ��������Ӳ�ͬ�Ѷȵĵ�ͼҪ��������       �����ǵĻ�˵��û�������߽�
{
    return snake.back().get_x()<30&&snake.back().get_x()>1&&snake.back().get_y()>1&&snake.back().get_y()<30;

}
bool snakes::hititself()     //�ж��Ƿ�ײ�����Լ���
{
    std::deque<points>::size_type cnt = 1;
    points *head=new points(snake.back().get_x(),snake.back().get_y());
    for(auto &point:snake)
    {
        if(!(point==*head))
            cnt++;
    }
    delete head;
    if(cnt==snake.size())
        return true;
    else
        return false;
}

bool snakes::changedirection()
{
    char ch;
    if(kbhit())
    {
        ch=getch();
        switch(ch)
        {
            case 'A':
            case 'a':
            case 75:    if(direction!=Direction::RIGHT)
                            direction=Direction::LEFT;
                         break;
            case 'D':
            case 'd':
            case 77:    if(direction!=Direction::LEFT)
                            direction=Direction::RIGHT;
                        break;
            case 'W':
            case 'w':
            case 72:   if(direction!=Direction::DOWN)
                            direction=Direction::UP;
                        break;
            case 'S':
            case 's':
            case 80:    if(direction!=Direction::UP)
                            direction=Direction::DOWN;
                        break;
            case 27 :   return false;
            default :   break;

        }
        
    }
    return true;
    
}
bool snakes::getfood(const foods & cfood)
{
     if(snake.back().get_x()==cfood.x&&snake.back().get_y()==cfood.y)
        return true;
    else 
        return false;
}

bool snakes::getbigfood(foods &cfood)
{
    if(snake.back().get_x()==cfood.big_x&&snake.back().get_y()==cfood.big_y)
    {
        cfood.bigflag = false;
        cfood.big_x = 0;
        cfood.big_y = 0;
        setcursorposition(1, 0);
        std::cout << "                                                            " ;
        return true;
    }
    else
        return false;
}