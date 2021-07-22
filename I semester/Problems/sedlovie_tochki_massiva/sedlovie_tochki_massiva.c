#include <stdio.h>

main()
{
    int a[100][100],n,k,max,min,l;

    printf("Vvedi razmernost' massiva n = ");
    scanf("%d",&n);

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++){
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
    }

    printf("Massiv A:\n");
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
            printf("%3d",a[i][j]);
        printf("\n");
    }
    for (int i=0;i<n;i++){
        min = a[i][0];
        k = 0;
        for (int j=1;j<n;j++)
            if (min>a[i][j]){
                min = a[i][j];
                k = j;
            }
        max = a[0][k];
        l = 0;
        for (int j=1;j<n;j++)
            if (max<a[j][k]){
                max = a[j][k];
                l = j;
            }
        if (l == i)
            printf("\nSedlovaia tochka a[%d,%d] = %d",i,k,a[i][k]);
    }

}
