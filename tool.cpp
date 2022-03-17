#include"tool.h"
#include<windows.h>
#include<cstdio>
void setwindowsize(int cols,int lines)
{
    system("title 贪吃蛇");
    char cmd[30];
    sprintf(cmd,"mode con cols=%d lines=%d",cols*2,lines);
    system(cmd);
}
void setcursorposition(int x,int y)   //将光标移动到指定位置
{
    COORD position;
    position.X=x*2;
    position.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
}
void setcolor(int colorID)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colorID);   //1蓝2绿3红
}
void setbackcolor()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);
    //字体为蓝，背景为白色
}