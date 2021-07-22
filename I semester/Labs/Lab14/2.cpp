#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <math.h>
//#include <color.h>
void rec(int x,int y,int n){
    if(x<n){
        return;
    }
    line(x,y,x+60,y);
    line(x+60,y,x,y+60);
    return rec(x+60,y+60,n);
}
main()
{
    int ga,gm;
    ga=DETECT;
    gm=DETECT;
    initgraph(&ga,&gm,"");
    setcolor(3); int i,j;
  circle(80,80,50);
 /*
    for(i=80;i<83;i++)
        for(j=80;j<83;j++)
            putpixel(i,j,3);

    outtextxy(54,85,"(80,80)");

    setfillstyle(6,1);

    rectangle(200,100,400,200);
    floodfill(210,110,3);

    setfillstyle(1,5);
    bar(420,50,500,100);

    bar3d(30,180,140,280,50,4);

    int s=imagesize(30,180,140,280);
    void *P=malloc(s);

    getimage(30,180,140,280,P);
    for(int i = 0;i<6;i++){
        int d=i%2==0?0:1;
        putimage(300,180,P,d);
    }

    arc(20,340,1,90,60);

    ellipse(400,220,0,360,100,30);

    fillellipse(150,340,100,100);

    pieslice(250,340,0,90,100);

    lineto(300,100);

    sector(400,340,0,180,50,10);
    */
    rec(0,0,200);
    getch();
    closegraph();

}
