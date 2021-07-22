#include <stdio.h>
#include <stdbool.h>

main(){
    int k;
    float a,b,c,d,min,max,max_3;
    bool ba,bmin,bmax;

    Menu:
        printf("\nChoose:\n1).max(a,b)\n2).min(c,d)\n3).max(a,min(c,d))\n-->");
        scanf("%d",&k);

        switch(k){
            case 1:
                switch(bmax){
                    case 1: printf("\nmax(%g,%g)=%g",a,b,max); goto Reset;
                    case 0:
                        if (ba==0) {printf("a="); scanf("%f",&a); ba = 1;}
                        printf("b="); scanf("%f",&b);

                        if (a>b) max = a;
                            else max = b;
                        bmax = 1;
                        printf("max(%g,%g)=%g",a,b,max);
                        goto Reset;
                }
            case 2:
                switch(bmin) {
                    case 1: printf("\nmin(%g,%g)=%g",c,d,min); goto Reset;
                    case 0:
                        printf("c="); scanf("%f",&c);
                        printf("d="); scanf("%f",&d);

                        if (c>d) min = d;
                            else min = c;
                        bmin = 1;
                        printf("min(%g,%g)=%g",c,d,min);
                        goto Reset;
                }
            case 3:
                switch(ba) {
                    case 0: printf("a="); scanf("%f",&a); ba = 1;
                    case 1: break;

                }
                switch(bmin){
                    case 0:
                        printf("c="); scanf("%f",&c);
                        printf("d="); scanf("%f",&d);

                        if (c>d) min = d;
                            else min = c;
                        bmin = 1;
                        printf("min(%g,%g)=%g",c,d,min);
                    case 1:
                        if (a>min) max_3=a;
                            else max_3=min;
                        printf("\nmax(%g,%g)=%g",a,min,max_3);
                        goto Reset;
                }

        }
    Reset:
        printf("\nReset values? (1/2)-->"); scanf("%d",&k);
        switch(k){
            case 1: ba=0; bmax=0; bmin=0; break;
            case 2: break;
            default: printf("Wrong value!!!Try again"); goto Reset;
        }
        printf("\nRepeat? (1/2)-->"); scanf("%d",&k);
        switch(k){
            case 1: goto Menu; break;
            case 2: break;
            default: printf("Wrong value!!!Try again"); goto Reset;
        }
    return 0;
}
