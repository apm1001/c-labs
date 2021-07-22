#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <math.h>
//#include <color.h>

main()
{
    int b = DETECT, l;

    initgraph(&b,&l, " ");
    setbkcolor(WHITE);
    cleardevice();

    for(l=25;l<175;l++){
        putpixel(125,l,BLACK);
    }
    getch();
    closegraph();

}
