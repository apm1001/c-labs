#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
//#include <color.h>

main()
{
    int g1,g2;
    g1=DETECT;
    g2=DETECT;
    initgraph(&g1,&g2,"");
    //первый способ
    /*int a=50,b=50;
    for(int i = 1;i<4;i++){
        for(int j = 1;j<4;j++){
            rectangle(a,b,a+30,b+30);
            a+=50;
        }
        a=50;
        b+=50;
    }*/
    //второй способ
    int poly[10];
    poly[0] = 50;        /* первая точка */
    poly[1] = 50;
    poly[2] = 80;   /* 2 */
    poly[3] = 50;
    poly[4] = 80;   /* 3 */
    poly[5] = 80;
    poly[6] = 50;    /* 4 */
    poly[7] = 80;
    poly[8] = poly[0];   // возврат в исходную точку
    poly[9] = poly[1];

    for(int i = 1;i<4;i++){
        for(int j = 1;j<4;j++){
            drawpoly(5,poly);
            poly[0] += 50;
            poly[2] += 50;
            poly[4] += 50;
            poly[6] += 50;
            poly[8] = poly[0];
        }
        poly[1] += 50;
        poly[3] += 50;
        poly[5] += 50;
        poly[7] += 50;
        poly[9] = poly[1];
        poly[0] = 50;
        poly[2] = 80;
        poly[4] = 80;
        poly[6] = 50;
        poly[8] = poly[0];
    }
    getch();
    closegraph();

}
