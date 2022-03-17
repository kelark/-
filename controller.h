#ifndef CONTROLLER_H
#define CONTROLLER_H
class controller{
    private:
        int speed;
        int scores;
        int key;
    public:
        controller():speed(200),scores(0),key(1){}
        void start();
        void select();
        void drawgame();
        int playgame();//游戏中的循环
        int menu();
        void updatescore(const int&);
        void rewritescore();
        int gameover();
        void game();//游戏大循环
};
#endif