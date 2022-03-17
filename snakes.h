#ifndef SNAKE_H
#define SNAKE_H
#include"points.h"
#include<deque>
#include"foods.h"
class foods;
class snakes
{
    public:
        enum Direction {UP,DOWN,LEFT,RIGHT};
        snakes();
        void initsnake();
        void move();
        void normalmove();
        bool overedge();
        bool hititself();
        bool changedirection();
        bool getfood(const foods &);
        bool getbigfood(foods &);
    private:
        std::deque<points>snake;
        Direction direction;
        friend class foods;

      
    
};
#endif