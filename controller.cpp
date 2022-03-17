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
    std::cout<<"��ѡ����Ϸ�Ѷ�:";
    setcursorposition(6,22);
    std::cout<<"(���¼�ѡ��,enterȷ��)";

    setcursorposition(27,22);
    setbackcolor();
    std::cout<<"��ģʽ";
    setcursorposition(27,24);
    setcolor(3);
    std::cout<<"��ͨģʽ";
    setcursorposition(27,26);
    std::cout<<"����ģʽ";
    setcursorposition(27,28);
    std::cout<<"����ģʽ";


    //�û���ʼ����ѡ��
    int ch;
    bool flag=false;//������ʾ�Ƿ����enter��
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
                            std::cout<<"��ģʽ";
                            setcursorposition(27,24);
                            setcolor(3);
                            std::cout<<"��ͨģʽ";
                            key--;
                            break;
                        case 3:
                            setcursorposition(27,24);
                            setbackcolor();
                            std::cout<<"��ͨģʽ";
                            setcursorposition(27,26);
                            setcolor(3);
                            std::cout<<"����ģʽ";
                            key--;
                            break;
                        case 4:
                            setcursorposition(27,26);
                            setbackcolor();
                            std::cout<<"����ģʽ";
                            setcursorposition(27,28);
                            setcolor(3);
                            std::cout<<"����ģʽ";
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
                            std::cout<<"��ͨģʽ";
                            setcursorposition(27,22);
                            setcolor(3);
                            std::cout<<"��ģʽ";
                            key++;
                            break;
                        case 2:
                            
                            setcursorposition(27,26);
                            setbackcolor();
                            std::cout<<"����ģʽ";
                            setcursorposition(27,24);
                            setcolor(3);
                            std::cout<<"��ͨģʽ";
                            key++;
                            break;
                        case 3:
                            
                            setcursorposition(27,28);
                            setbackcolor();
                            std::cout<<"����ģʽ";
                            setcursorposition(27,26);
                            setcolor(3);
                            std::cout<<"����ģʽ";
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
    //���Ƶ�ͼ
    system("cls");//���� 
    setcolor(3);  
    maps *map=new maps;
    map->printinitmap();
    delete map;

    //�����
    setcolor(3);
    setcursorposition(33, 1);
    std::cout << "Greedy Snake" ;
    setcursorposition(34, 2);
    std::cout << "̰����" ;
    setcursorposition(31, 4);
    std::cout << "�Ѷȣ�" ;
    setcursorposition(36, 4);
    switch (key)
    {
    case 1:
        std::cout << "��ģʽ" ;
        break;
    case 2:
        std::cout << "��ͨģʽ" ;
        break;
    case 3:
        std::cout << "����ģʽ" ;
        break;
    case 4:
        std::cout << "����ģʽ" ;
        break;
    default:
        break;
    }
    setcursorposition(31, 7);
    std::cout << "�÷֣�" ;
    setcursorposition(37, 7);
    std::cout << "     0" ;
    setcursorposition(33, 13);
    std::cout << " ������ƶ�" ;
    setcursorposition(33, 15);
    std::cout << " ESC����ͣ" ;

}
  
int controller::playgame()    //��Ϸ��ʽ��ʼ
{   //��ʼ���ߺ�ʳ��
    snakes *csnake=new snakes;
    foods *cfood=new foods;
    setcolor(6);
    csnake->initsnake();
    srand(time(0)); //��ϵͳʱ�������ӣ�����ÿ�γ��ֵ�ʳ�ﶼ��ͬһλ��
    cfood->drawfoods(*csnake);

    //��Ϸѭ��
    while(csnake->overedge()&&csnake->hititself())    //�����û��ײǽ����ײ���Լ���һֱ����ѭ��
    {
        if(!csnake->changedirection())     //����escʱ�����в˵�ѡ��
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
                    return 1;       //��Ϊ����ֵ���ص�game�����У���ʾ���¿�ʼ��
                case 3:
                    delete csnake;
                    delete cfood;
                    return 2;       //��Ϊ����ֵ���ص�game�����У���ʾ�˳���Ϸ;
                default:
                    break;
            }
        }
        if(csnake->getfood(*cfood))
        {
            csnake->move();
            updatescore(1);     //1��ʾ��ͨʳ���Ȩ��;
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
        Sleep(speed);  //Ӫ���ߵ��ƶ�Ч��
    }
    //�˳�ѭ����ʾ���Լ�����
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
    GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
    CursorInfo.bVisible = false; //���ؿ���̨���
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
    std::cout<<"����������������������������������������������������������������������������������������";
    Sleep(30);
    setcursorposition(10,9);
    std::cout<<"��               Game Over !!!              ��";
    Sleep(30);
    setcursorposition(10,10);
    std::cout<<"��                                          ��";
    Sleep(30);
    setcursorposition(10,11);
    std::cout<<"��              ���ź��������              ��" ;
    Sleep(30);
    setcursorposition(10,12);
    std::cout<<"��                                          ��" ;
    Sleep(30);
    setcursorposition(10,13);
    std::cout<<"��         ��ķ���Ϊ��                     ��" ;
    setcursorposition(24, 13);
    std::cout<<scores;
    Sleep(30);
    setcursorposition(10, 14);
    std::cout<<"��                                          ��" ;
    Sleep(30);
    setcursorposition(10, 15);
    std::cout<<"��               �Ƿ�����һ�֣�             ��" ;
    Sleep(30);
    setcursorposition(10, 16);
    std::cout<<"��                                          ��" ;
    Sleep(30);
    setcursorposition(10, 17);
    std::cout<<"��                                          ��" ;
    Sleep(30);
    setcursorposition(10, 18);
    std::cout<<"��   �ţ��õ�          ���ˣ�����ѧϰ����˼ ��" ;
    Sleep(30);
    setcursorposition(10, 19);
    std::cout<<"��                                          ��" ;
    Sleep(30);
    setcursorposition(10, 20);
    std::cout<<"��                                          ��" ;
    Sleep(30);
    setcursorposition(10, 21);
    std::cout<<"����������������������������������������������������������������������������������������" ;
    setcursorposition(12,18);
    setbackcolor();
    std::cout<<"�ţ��õ�";
    setcursorposition(0,31);
    //ѡ�񲿷֣�������select����һ��
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
                        std::cout<<"���ˣ�����ѧϰ����˼";
                        setcursorposition(12,18);
                        setbackcolor();
                        std::cout<<"�ţ��õ�";
                        tmp_key--;
                        
                        
                    }
                    break;
            case 77://RIGHT
                if(tmp_key==1)
                {
                    setcursorposition(21,18);
                    setbackcolor();
                    std::cout<<"���ˣ�����ѧϰ����˼";
                    setcursorposition(12,18);
                    setcolor(11);
                    std::cout<<"�ţ��õ�";
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
    //enter �˳�
    if(tmp_key==1)
    {
        return 1; //���¿�ʼ
    }
    if(tmp_key==2)
    {
        return 2;//�˳���Ϸ
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
    std::cout<<"�˵�:";
    setbackcolor();
    setcursorposition(34,21);
    std::cout<<"������Ϸ";
    setcolor(11);
    setcursorposition(34,23);
    std::cout<<"���¿�ʼ";
    setcursorposition(34,25);
    std::cout<<"�˳���Ϸ";

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
                            std::cout<<"������Ϸ";
                            setcursorposition(34,23);
                            setcolor(11);
                            std::cout<<"���¿�ʼ";
                            tmp_key--;
                            break;
                        case 3:
                            setcursorposition(34,23);
                            setbackcolor();
                            std::cout<<"���¿�ʼ";
                            setcursorposition(34,25);
                            setcolor(11);
                            std::cout<<"�˳���Ϸ";
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
                            std::cout<<"������Ϸ";
                            setcursorposition(34,23);
                            setbackcolor();
                            std::cout<<"���¿�ʼ";
                            tmp_key++;
                            break;
                        case 2:
                            setcursorposition(34,23);
                            setcolor(11);
                            std::cout<<"���¿�ʼ";
                            setcursorposition(34,25);
                            setbackcolor();
                            std::cout<<"�˳���Ϸ";
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