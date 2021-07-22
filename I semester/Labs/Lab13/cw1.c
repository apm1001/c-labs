//214
#include <stdio.h>
#include <math.h>
main()
{
    float a[100], *p;
    int i=0;
    p = a;

    *p = pow(cos(1),2);
    printf("%7.2f",*p);
    p++;
    *p = -1*pow(sin(1),2);
    printf("%7.2f",*p);
    i=2;
     for (p=a+2;p<(a+100);p++){
        *p = 2*(*(p-1))-*(p-2);
        printf("%7.2f",*p);
        i++;
        if (i%10==0)printf("\n");
     }
     i=0;
     printf("\n Result:\n");
     for (p=a;p<(a+100);p++){
         if (*p<2) printf("%10.2f",pow(*p,2));
         i++;
         if (i%10==0)printf("\n");
     }

}
