//матрица с клавиатуры, элементы - только положительные цифры
//собрать в одномрные массив и составить одно число
//1 3 5 == 135
//6 2 5 == 625
//и потом вычислить максимальное из них
#include <stdio.h>
#include <math.h>
main()
{
    int n,i,j,max = 0,sum;
    printf("Enter the matrix dimension (N<=5) N = ");
    scanf("%i",&n);

    printf("Enter the matrix elements, they should be positive (>0) :\n");
    int matrix[n][n],array[n];

    for (i = 0;i<n;i++)
        for (j = 0;j<n;j++){
            printf("Matrix[%i][%i] = ",i,j); scanf("%i",&matrix[i][j]);
        }
    printf("--------------------------------------------------------------------------------------\n");
    for (i = 0;i<n;i++){
        sum = 0;
        for (j = 0;j<n;j++){
            array[j] = matrix[i][j]; printf("%3i",array[j]);
            sum+=array[j]*pow(10,n-1-j);
        }
        printf("  =  %i \n",sum);
        if (max<sum) max = sum;
    }
    printf("\nMax = %i",max);

}
