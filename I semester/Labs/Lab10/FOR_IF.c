#include <stdio.h>
#include <math.h>

main() {
    float l,x,a,b;
    const float p = 3.14;

    printf("Enter a = ");
    scanf("%f",&a);
    printf("Enter b = ");
    scanf("%f",&a);
    printf("|-------------|-------------|");
    printf("\n|      X      |      L      |");
    printf("\n|-------------|-------------|");

    for (x = -10;x<=10;x+=1.23){
        if (x<1.2) {
            l=2*cos(x-p/6);
            printf("\n|%13g|%13g|",x,l);
        }
        else if ((x>=1.2) && (x<=3.9)) {
            l = pow(x,2)/a+cos(pow(x+b,3));
            printf("\n|%13g|%13g|",x,l);
        }
        else {
            l = abs(x/2*a)+pow(sin(x+1),2);
            printf("\n|%13g|%13g|",x,l);
        }
    }
    printf("\n|-------------|-------------|");
    return 0;
}
