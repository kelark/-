#include"controller.h"
#include<windows.h>
int main()
{
    controller * begin=new controller;
    begin->game();
    delete begin;
    return 0;
}