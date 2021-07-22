#include <stdio.h>
#include <math.h>>
#include <conio.h>

main()
{
    float x;
    float y,y1,y2,d;

    printf("Introdu x=");
    scanf("%f",&x);

    if (x<-4) y=-3;
        else if (x<-3) y=x+1;
            else if (x<-2) y=-2;
                else if (x<-1)y=-x-4;
                    else if (x<=1)y=x-2;
                        else if (x<5) {
                                d=4-4*(pow(x,2)-6*x+2);
                                y1=(2-sqrt(d))/2;
                                y2=(2+sqrt(d))/2;
                                if (y1<=y2) y=y1;
                                    else y=y2;
                        }
                            else if (x>5)y=2*x-11;

    printf("%5c%9c\n",'X','Y');
    printf("%6.2f%10.2f",x,y);
    getch();
}
