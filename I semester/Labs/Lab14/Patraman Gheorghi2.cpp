#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
//IA2003 Patraman v14
main()
{
    int ga,gm;
    ga=DETECT;
    gm=DETECT;
    initgraph(&ga,&gm,"");
    setcolor(1); int i,j;

    bar(100,100,400,400);
    line(100,300,200,400);
    line(300,100,400,200);
    line(100,300,300,100);
    line(400,200,200,400);

    circle(130,371,30);

    ellipse(250,250,0,360,72,72);

    getch();
    closegraph();

}
