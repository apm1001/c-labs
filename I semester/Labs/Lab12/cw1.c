#include <stdio.h>
#include <math.h>
main()
{
    int n,a=10,b=6,i_sum = 0,i_p= 0;

    printf("Vvedi razmernost' massiva X: n = ");
    scanf("%d",&n);
    float x[n][n],l[n][n],pi=3.14,max,sum = 0.0,p = 1.0,med = 0.0,k =0.0;

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++){
            printf("x[%d][%d] = ",i,j);
            scanf("%f",&x[i][j]);
    }
    max = x[0][0];
    printf("Massiv X:\n");
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%5.2g",x[i][j]);
            sum+=x[i][j];
            if (max<x[i][j]) max = x[i][j];
        }
        printf("\n");
    }
    printf("Suma = %.2f\nMaximalnii element = %.2f",sum,max);
    printf("\nMassiv L:\n");
    sum = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
                if (x[i][j]<1.2){
                        l[i][j] = 2*cos(x[i][j]-pi/6);
                        printf("%5.2f",l[i][j]);
                        sum += l[i][j];
                        i_sum++;
                }
                else if (x[i][j]<=3.9){
                        l[i][j] = pow(x[i][j],2)/a+cos(pow(x[i][j]+b,3));
                        printf("%5.2f",l[i][j]);
                        if (l[i][j]!=0) p*=l[i][j];
                        i_p++;
                }
                else {
                        l[i][j] = abs(x[i][j]/(2*a))+pow(sin(x[i][j]+1),2);
                        printf("%5.2f",l[i][j]);
                        med += l[i][j];
                        k = k+1.0;
                }
        }
        printf("\n");
    }
    printf("Sum(%d) = %.2f\nProizvedenie(%d) = %.2f\nMedia(%.f) = %.2f",i_sum,sum,i_p,p,k,med/k);

}
