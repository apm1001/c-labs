#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>

main()
{
    int ga,gm;
    ga=DETECT;
    gm=DETECT;
    initgraph(&ga,&gm,"");
    setcolor(1); int i,j;
    ellipse(200,300,0,360,100,20);

    circle(120,300,10);
    circle(150,300,10);
    circle(180,300,10);
    circle(210,300,10);
    circle(240,300,10);
    circle(270,300,10);
    rectangle(100,200,300,285);
    rectangle(170,170,220,200);
    rectangle(220,175,300,190);

    char t1[]="Press 'f' to fire!!";
    char t2[]="Press 'e' to close program!!";
    setusercharsize(3,3,3,3);
    outtextxy(5,5,t1);
    outtextxy(5,25,t2);

    int x,y;
    char ch;
    Menu:
        ch = getch();
        switch(ch){
        case 'f':
            x=310;
            y=183;
            for(i=0;i<30;i++){
                setfillstyle(1,1);
                pieslice(x,y,0,360,8);
                delay(100);
                setfillstyle(1,0);
                bar(x-8,y-8,x+8,y+8);
                x+=10;
            }
            goto Menu;
        case 'e':break;
        default: printf("\nError!Try again!"); goto Menu;

        }
    getch();
    closegraph();
}
