#include <stdio.h>
#include <math.h>
main(){
    int k;
    float e,c,a,d,b,m;
    Menu:
        printf("\n1)Enter c.\n2)Exit.\n==>");
        scanf("%d",&k);
        switch(k){
            case 1:
                printf("c="); scanf("%f",&c);
                if (c<1){
                    m=1/(9-c);
                    printf("c=%g   m=%g",c,m);
                    goto Menu; break;
                }
                if ((c>=1)&&(c<=3)){
                    printf("a="); scanf("%f",&a);
                    printf("d="); scanf("%f",&d);
                    m=6*c*a + d;
                    for (c;c<=3;c+=0.1)
                    printf("\nc=%3g   m=%g",c,m);
                    goto Menu; break;
                }
                if ((c>3)&&(c<6)){
                    printf("e="); scanf("%f",&e);
                    m=e*pow(9-pow(c,2),1/2);
                    for (c;c<6;c+=0.2)
                    printf("\nc=%3g   m=%g",c,m);
                    goto Menu; break;
                }
                if (c>=6){
                    printf("b="); scanf("%f",&b);
                    m=b*c+5;
                    printf("c=%g   m=%g",c,m);
                    goto Menu; break;
                }
            case 2:break;
            default:
                printf("Wrong value!Try again!");
                goto Menu;
                break;

        }
    return 0;
}
