#include <color.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <graphics.h>
void rec(int x,int y,int n){
    if(x>=n){
        return;
    }
    /*
    line(x,y,x+60,y);
    line(x+60,y,x,y+60);
    */
    for(int i=x;i<x+60;i++){
        putpixel(i,y,WHITE);
    }
    for(int i=y;i<y+60;i++){
        putpixel(x+60,i,WHITE);
    }
    return rec(x+60,y+60,n);
}
int main(){
    int ga,gm;
    ga=DETECT;
    gm=DETECT;
    initgraph(&ga,&gm,"");
    setcolor(3);
    setlinestyle(0,1,1);
    int i,j;
    int n = 200;
    int x=0,y=0;
    setfillstyle(6,1);
    rec(0,15 ,n);
    for(i=0;i<n+40;i++){
        putpixel(i,255,WHITE);
    }
    for(i=0;i<n+55;i++){
        putpixel(1,i,WHITE);
    }
    getch();
    closegraph();
}
