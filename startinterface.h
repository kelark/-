#ifndef STARTINTERFACE_H
#define STARTINTERFACE_H
#include"points.h"
#include<deque>
#include<vector>
class startinterface{
    private:
        int speed;   //速度变量
        std::deque<points>startsnake;//开始进场的蛇
        std::vector<points>textsnake;//进场的文字
    public:
        startinterface();
        void printfirst();
        void printsecond();
        void printthird();
        void printtext();
        void cleartext();
        void action();
};
#endif