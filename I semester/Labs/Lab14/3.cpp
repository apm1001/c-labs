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

    int p[10];

    p[0] = 100;
    p[1] = 100;
    p[2] = 400;
    p[3] = 100;
    p[4] = 400;
    p[5] = 400;
    p[6] = 100;
    p[7] = 400;
    p[8] = p[0];
    p[9] = p[1];
    drawpoly(5,p);


    p[0] = 300;
    p[1] = 100;
    p[2] = 400;
    p[3] = 200;
    p[4] = 200;
    p[5] = 400;
    p[6] = 100;
    p[7] = 300;
    p[8] = p[0];
    p[9] = p[1];
    drawpoly(5,p);

    circle(130,371,30);

    ellipse(250,250,0,360,72,72);

    getch();
    closegraph();

}
