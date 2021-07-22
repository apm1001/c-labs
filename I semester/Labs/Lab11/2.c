#include <stdio.h>
#include <math.h>

main()
{
    const int n=100;
    float a[n],sum = 0;

    a[0] = pow(cos(1),2);
    a[1] = -1*pow(sin(1),2);

    printf("Array A:\n");

    for (int i=2;i<n;i++)
        a[i] = 2*a[i-1]-a[i-2];

    for (int i=0;i<n;i++){
        if (i%10==0) printf("\n");
        printf("%7.2f",a[i]);
        if (a[i]<2)
            sum+=pow(a[i],2);
    }

    printf("\n\nSumm = %.2f",sum);

    return 0;
}
