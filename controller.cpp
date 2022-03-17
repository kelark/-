#include"controller.h"
#include"tool.h"
#include"startinterface.h"
#include<iostream>
#include"windows.h"
#include"maps.h"
#include"snakes.h"
#include"foods.h"
#include<time.h>
#include<cstdlib>
#include<conio.h>
void controller::start()
{
    setwindowsize(41,32);
    setcolor(2);
    startinterface * start=new startinterface;
    start->action();
    delete start;
    
    setcursorposition(13,26);
    std::cout<<"press any key to start...";
    setcursorposition(13,27);
    system("pause");

}

void controller::select()
{
    setcolor(3);
    setcursorposition(13,26);
    std::cout<<"                           ";
    setcursorposition(13,27);
    std::cout<<"                           ";

    setcursorposition(6,21);
    std::cout<<"请选择游戏难度:";
    setcursorposition(6,22);
    std::cout<<"(上下键选择,enter确认)";

    setcursorposition(27,22);
    setbackcolor();
    std::cout<<"简单模式";
    setcursorposition(27,24);
    setcolor(3);
    std::cout<<"普通模式";
    setcursorposition(27,26);
    std::cout<<"困难模式";
    setcursorposition(27,28);
    std::cout<<"炼狱模式";


    //用户开始进行选择
    int ch;
    bool flag=false;//用来表示是否键入enter键
    while(1)
    {
        
        ch=getch();
        switch(ch)
        {
            case 72:     //UP
                if(key>1)
                {
                    switch(key)
                    {
                        case 2: 
                            setcursorposition(27,22);
                            setbackcolor();
                            std::cout<<"简单模式";
                            setcursorposition(27,24);
                            setcolor(3);
                            std::cout<<"普通模式";
                            key--;
                            break;
                        case 3:
                            setcursorposition(27,24);
                            setbackcolor();
                            std::cout<<"普通模式";
                            setcursorposition(27,26);
                            setcolor(3);
                            std::cout<<"困难模式";
                            key--;
                            break;
                        case 4:
                            setcursorposition(27,26);
                            setbackcolor();
                            std::cout<<"困难模式";
                            setcursorposition(27,28);
                            setcolor(3);
                            std::cout<<"炼狱模式";
                            key--;
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 80:      //DOWN
                if(key<4)
                {
                    switch(key)
                    {
                        case 1:
                            setcursorposition(27,24);
                            setbackcolor();
                            std::cout<<"普通模式";
                            setcursorposition(27,22);
                            setcolor(3);
                            std::cout<<"简单模式";
                            key++;
                            break;
                        case 2:
                            
                            setcursorposition(27,26);
                            setbackcolor();
                            std::cout<<"困难模式";
                            setcursorposition(27,24);
                            setcolor(3);
                            std::cout<<"普通模式";
                            key++;
                            break;
                        case 3:
                            
                            setcursorposition(27,28);
                            setbackcolor();
                            std::cout<<"炼狱模式";
                            setcursorposition(27,26);
                            setcolor(3);
                            std::cout<<"困难模式";
                            key++;
                            break;
                    }
                }
                break;
            case 13:    //enter
                flag=true;
                break;
            default:
                break;
        }
        if(flag)
            break;
        setcursorposition(0,31);
    }
    switch(key)
    {
        case 1:
            speed=135;
            break;
        case 2:
            speed=100;
            break;
        case 3:
            speed=60;
            break;
        case 4:
            speed=30;
            break;
        default:
            break;
    }
}
void controller::drawgame()
{
    //绘制地图
    system("cls");//清屏 
    setcolor(3);  
    maps *map=new maps;
    map->printinitmap();
    delete map;

    //侧边栏
    setcolor(3);
    setcursorposition(33, 1);
    std::cout << "Greedy Snake" ;
    setcursorposition(34, 2);
    std::cout << "贪吃蛇" ;
    setcursorposition(31, 4);
    std::cout << "难度：" ;
    setcursorposition(36, 4);
    switch (key)
    {
    case 1:
        std::cout << "简单模式" ;
        break;
    case 2:
        std::cout << "普通模式" ;
        break;
    case 3:
        std::cout << "困难模式" ;
        break;
    case 4:
        std::cout << "炼狱模式" ;
        break;
    default:
        break;
    }
    setcursorposition(31, 7);
    std::cout << "得分：" ;
    setcursorposition(37, 7);
    std::cout << "     0" ;
    setcursorposition(33, 13);
    std::cout << " 方向键移动" ;
    setcursorposition(33, 15);
    std::cout << " ESC键暂停" ;

}
  
int controller::playgame()    //游戏正式开始
{   //初始化蛇和食物
    snakes *csnake=new snakes;
    foods *cfood=new foods;
    setcolor(6);
    csnake->initsnake();
    srand(time(0)); //用系统时间做种子，避免每次出现的食物都在同一位置
    cfood->drawfoods(*csnake);

    //游戏循环
    while(csnake->overedge()&&csnake->hititself())    //如果蛇没有撞墙或者撞到自己就一直进行循环
    {
        if(!csnake->changedirection())     //按下esc时，进行菜单选项
        {
            int tmp=menu();
            switch(tmp)
            {
                case 1:
                    //setcolor(11);
                    setcursorposition(32,19);
                    std::cout<<"        ";
                    setcursorposition(34,21);
                    std::cout<<"        ";
                    setcursorposition(34,23);
                    std::cout<<"        ";
                    setcursorposition(34,25);
                    std::cout<<"        ";
                    break;
                case 2:
                    delete csnake;
                    delete cfood;
                    return 1;       //作为返回值返回到game函数中，表示重新开始；
                case 3:
                    delete csnake;
                    delete cfood;
                    return 2;       //作为返回值返回到game函数中，表示退出游戏;
                default:
                    break;
            }
        }
        if(csnake->getfood(*cfood))
        {
            csnake->move();
            updatescore(1);     //1表示普通食物的权重;
            rewritescore();
            cfood->drawfoods(*csnake);
        }
        else
        {
            csnake->normalmove();
        }
        if(csnake->getbigfood(*cfood))
        {
            csnake->move();
            //csnake->move();
            updatescore(cfood->getprogressbar()/5);
            rewritescore();
        }
        if(cfood->getbigflag())
            cfood->flashbigfoods();
        Sleep(speed);  //营造蛇的移动效果
    }
    //退出循环表示蛇以及死亡
    delete csnake;
    delete cfood;
    int tmp=gameover();
    switch(tmp)
    {
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            return 2;
    }

}
void controller::game()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
    CursorInfo.bVisible = false; //隐藏控制台光标
    SetConsoleCursorInfo(handle, &CursorInfo);
    start();
    while(1)
    {
        select();
        drawgame();
        int tmp=playgame();
        if(tmp==1)
        {
            setcolor(3);
            system("cls");
            continue;
        }
        else if(tmp==2)
            break;
        else    
        break;
    }
}
int controller::gameover()
{
    setcolor(11);
    setcursorposition(10,8);
    std::cout<<"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    Sleep(30);
    setcursorposition(10,9);
    std::cout<<"┃               Game Over !!!              ┃";
    Sleep(30);
    setcursorposition(10,10);
    std::cout<<"┃                                          ┃";
    Sleep(30);
    setcursorposition(10,11);
    std::cout<<"┃              很遗憾！你挂了              ┃" ;
    Sleep(30);
    setcursorposition(10,12);
    std::cout<<"┃                                          ┃" ;
    Sleep(30);
    setcursorposition(10,13);
    std::cout<<"┃         你的分数为：                     ┃" ;
    setcursorposition(24, 13);
    std::cout<<scores;
    Sleep(30);
    setcursorposition(10, 14);
    std::cout<<"┃                                          ┃" ;
    Sleep(30);
    setcursorposition(10, 15);
    std::cout<<"┃               是否再来一局？             ┃" ;
    Sleep(30);
    setcursorposition(10, 16);
    std::cout<<"┃                                          ┃" ;
    Sleep(30);
    setcursorposition(10, 17);
    std::cout<<"┃                                          ┃" ;
    Sleep(30);
    setcursorposition(10, 18);
    std::cout<<"┃   嗯，好的          不了，还是学习有意思 ┃" ;
    Sleep(30);
    setcursorposition(10, 19);
    std::cout<<"┃                                          ┃" ;
    Sleep(30);
    setcursorposition(10, 20);
    std::cout<<"┃                                          ┃" ;
    Sleep(30);
    setcursorposition(10, 21);
    std::cout<<"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" ;
    setcursorposition(12,18);
    setbackcolor();
    std::cout<<"嗯，好的";
    setcursorposition(0,31);
    //选择部分，跟上面select部分一样
    int tmp_key=1;
    int ch;
    bool flag=false;
    while(1)
    {
        ch=getch();
        switch(ch)
        {
            case 75:  //LEFT
                if(tmp_key==2)
                    {
                        setcursorposition(21,18);
                        setcolor(11);
                        std::cout<<"不了，还是学习有意思";
                        setcursorposition(12,18);
                        setbackcolor();
                        std::cout<<"嗯，好的";
                        tmp_key--;
                        
                        
                    }
                    break;
            case 77://RIGHT
                if(tmp_key==1)
                {
                    setcursorposition(21,18);
                    setbackcolor();
                    std::cout<<"不了，还是学习有意思";
                    setcursorposition(12,18);
                    setcolor(11);
                    std::cout<<"嗯，好的";
                    tmp_key++;
                }
                break;
            case 13:
                flag=true;
                break;
            default:
                break;
        }
        if(flag)
            break;
        setcursorposition(0,31);
    }
    //enter 退出
    if(tmp_key==1)
    {
        return 1; //重新开始
    }
    if(tmp_key==2)
    {
        return 2;//退出游戏
    }
    return 0;
}
void controller::updatescore(const int &tmp)
{
    scores += key*10*tmp;
}
void controller::rewritescore()
{
    setcolor(3);
    setcursorposition(37,7);
    int bit=0;
    int tmp=scores;
    while(tmp!=0)
    {
        bit++;
        tmp /=10;
    }
    for(int i=0;i<(6-bit);i++)
    {
        std::cout<<" ";
    }
    std::cout<<scores;
}
int controller::menu()
{
    setcolor(11);
    setcursorposition(32,19);
    std::cout<<"菜单:";
    setbackcolor();
    setcursorposition(34,21);
    std::cout<<"继续游戏";
    setcolor(11);
    setcursorposition(34,23);
    std::cout<<"重新开始";
    setcursorposition(34,25);
    std::cout<<"退出游戏";

    int ch;
    int tmp_key=1;
    bool flag=false;
    while(1)
    {
        ch=getch();
        switch(ch)
        {
            case 72://up
                if(tmp_key>1)
                {
                    switch(tmp_key)
                    {
                        case 2:
                            setcursorposition(34,21);
                            setbackcolor();
                            std::cout<<"继续游戏";
                            setcursorposition(34,23);
                            setcolor(11);
                            std::cout<<"重新开始";
                            tmp_key--;
                            break;
                        case 3:
                            setcursorposition(34,23);
                            setbackcolor();
                            std::cout<<"重新开始";
                            setcursorposition(34,25);
                            setcolor(11);
                            std::cout<<"退出游戏";
                            tmp_key--;
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 80:   //DOWN
                if(tmp_key<3)
                {
                    switch(tmp_key)
                    {
                        case 1:
                            setcursorposition(34,21);
                            setcolor(11);
                            std::cout<<"继续游戏";
                            setcursorposition(34,23);
                            setbackcolor();
                            std::cout<<"重新开始";
                            tmp_key++;
                            break;
                        case 2:
                            setcursorposition(34,23);
                            setcolor(11);
                            std::cout<<"重新开始";
                            setcursorposition(34,25);
                            setbackcolor();
                            std::cout<<"退出游戏";
                            tmp_key++;
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 13:
                flag=true;
                break;
            default:
                break;

        }
        if(flag)
            break;
        setcursorposition(0,31);

    }
    
    return tmp_key;
}