#include <stdio.h>
#include <conio.h>
#include "lab5:\gotoxy.h*
#include "d:\color.h*

main() {
    int mark1, mark2;
    mark1:system("cls");
    SetColor(2);
    printf("\nChoose:\n\r1.Formula\n\r2.Checking condition\n\r3.Exit\n\r==>");
    int r; scanf("%i",&r);
    switch(r)
    {
    case 1:
        float a, x, y;
        float t;
        SetColor(2); gotoxy(10,10);
        printf("a="); scanf("%f", &a);
        printf("x="); scanf("%f", &x);
        printf("y="); scanf("%f", &y);
        if (x==0) {
        printf("znamenatel ne mojet biti =0");
        }
        else if(a*y-abs(pow(y,2)-pow(x,2))<0) {
        printf("virajenie pod cornem ne moej biti < 0");
        }
        else {
        t=sqrt(a*y-abs(pow(y,2)-pow(x,2)))/pow(x,2);
        printf("t=%f", t);
        }
    case 2:
        float y,x,a=0.9;
        SetColor(3); gotoxy(30,10);
        printf("x="); scanf("%f", &x);
        if (x>1) y=a*log10(x)+pow(abs(x),1/3);
            else y=2*a*cos(x)+3*pow(x,2);
        gotoxy(30,10);printf("y=%i",y);
        break;
    case 3: goto mark2;
    default:
        printf("gresit"); SetColor(4);
        system("pause");
        goto mark1;
    }
    mark2:
        if(r!=3){
            gotoxy(50,10);
            puts("Try again?(y/n)");
            gotoxy(50,10);
            char c=getche();
            if (c=='y') goto mark1;
        }
}
