#ifndef FOOD_H
#define FOOD_H
#include"snakes.h"
class snakes;
class foods{
private:
    int x,y,big_x,big_y;
    bool flashflag;
    bool bigflag;
    int cnt;
    int progressbar;
    friend class snakes;
public:
    foods();
    void drawfoods(snakes &csnake);
    void drawbigfoods(snakes &csnake);
    void flashbigfoods();
    int get_cnt();
    bool getbigflag();
    int getprogressbar();
    

};

#endif