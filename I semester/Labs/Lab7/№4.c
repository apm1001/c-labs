#include <stdio.h>
#include <conio.h>

main(){
    float x,y;

    printf("Input x=");
    scanf("%f",&x);

    y=(x<2)?(pow(x,2)+4*x-7):1/(pow(x,2)+4*x-7);

    printf("\ny=%g",y);

    printf("\nInput x=");
    scanf("%f",&x);

    y=(x<2)?(pow(x,2)+4*x-7):1/(pow(x,2)+4*x-7);

    printf("\ny=%g",y);

    getch();
}
