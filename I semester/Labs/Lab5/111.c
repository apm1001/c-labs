#include <stdio.h>
#include <math.h>
#include <conio.h>

int main(){
float a, x, y;
float t;
printf("a="); scanf("%f", &a);
printf("x="); scanf("%f", &x);
printf("y="); scanf("%f", &y);
if (x!=0)
    if(a*y-abs(pow(y,2)-pow(x,2))>=0) {
        t=sqrt(a*y-abs(pow(y,2)-pow(x,2)))/pow(x,2);
        printf("t=%f", t);
    }
    else printf("virajenie pod cornem ne moej biti < 0");
else printf("znamenatel ne mojet biti =0");

getch();
}
