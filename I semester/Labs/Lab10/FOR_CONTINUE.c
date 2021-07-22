#include <stdio.h>
#include <math.h>

main()
{
    double p = 1.,x;
    int i;

    printf("Enter x=");
    scanf("%f",&x);

    for (i=2;;i++){
        if (i==11)
            break;
        else if (i == 5) continue;
        else {
            p=p* (tan(abs(x))+1/(i-5));
            printf("\ni = %d   P = %f",i,p);
        }
    }
    return 0;
}
