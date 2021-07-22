#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <stdbool.h>
main()
{
    int ga,gm;
    ga=DETECT;
    gm=DETECT;
    initgraph(&ga,&gm,"");
    setfillstyle(1,9);
    bar(0,0,700,300);
    int rx=50,ry=250,r=25;
    bool b=false;
    for(int i=0;i<20;i++){
        setfillstyle(1,14);
        fillellipse(rx,ry,r,r);
        line(rx-50,ry,rx-25,ry);
        line(rx,ry-25,rx,ry-50);
        line(rx+25,ry,rx+50,ry);
        line(rx,ry+25,rx,ry+50);
        line(rx+15,ry+15,rx+30,ry+30);
        line(rx-15,ry-15,rx-30,ry-30);
        line(rx-15,ry+15,rx-30,ry+30);
        line(rx+15,ry-15,rx+30,ry-30);

        delay(200);
        setfillstyle(1,9);
        bar(rx-50,ry-50,rx+50,ry+50);
        if((ry>50)&&(!b)){
            rx+=30; ry-=20;
        }
        else b = true;
        if(b) {
            rx+=30; ry+=20;
        }
    }
    getch();
    closegraph();
}

