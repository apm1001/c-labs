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
        putpixel(5,l,BLACK);
        putpixel(155,l,BLACK);
        putpixel(255,l,BLACK);
        putpixel(330,l,BLACK);
        putpixel(430,l,BLACK);
        putpixel(505,l,BLACK);
        putpixel(580,l,BLACK);
    }
    for(l=430;l<580;l++){
        putpixel(l,175,BLACK);
    }
    for(l=290;l<360;l++){
        putpixel(l,325,BLACK);
    }
    for(b=5;b<80;b++){
        for(l=26;l<175;l++){
            putpixel(b++,l++,BLACK);
        }
    }
    for(b=80;b<155;b++){
        for(l=175;l>25;l--){
            putpixel(b++,l--,BLACK);
        }
    }
    for(b=255;b<330;b++){
        for(l=26;l<175;l++){
            putpixel(b++,l++,BLACK);
        }
    }
    for(b=250;b<325;b++){
        for(l=400;l>250;l--){
            putpixel(b++,l--,BLACK);
        }
    }
    for(b=325;b<400;b++){
        for(l=250;l<400;l++){
            putpixel(b++,l++,BLACK);
        }
    }
    getch();
    closegraph();

}
