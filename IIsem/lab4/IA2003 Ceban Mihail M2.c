#include <stdio.h>
#include <math.h>
#include <color.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
//16,685,684
main(){


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ClearConsoleToColors(2,7);
    srand(time(NULL));
    const int n = 5;
    int i,j,k=0,a[n][n],c[n][n],max=-99999,min=99999,imax,jmax,imin,jmin;
    bool bi=false,bj=false;
    printf("Массив A:\n");

    SetColor(5);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            a[i][j]  = c[i][j] = rand()%100;
            printf("%4i",a[i][j]);
            if(a[i][j]>max){
                max = a[i][j];
                imax = i;
                jmax = j;
            }
        }
        printf("\n");
    }
    SetColor(2);
    printf("(684)Массив B(с удаленными строками и столбцами на max):\n");
    SetColor(5);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==imax&&j==jmax){
                SetColor(3);
                printf("%4i",a[i][j]);
            }
            else if(i==imax||j==jmax){
                SetColor(6);
                printf("%4i",a[i][j]);
            }
            else{
                SetColor(5);
                printf("%4i",a[i][j]);
            }
        }
        printf("\n");
    }
    SetColor(5);
    printf("\n\n");
    for(i=0;i<n;i++){
        if(i==imax){
            continue;
        }
        for(j=0;j<n;j++){
            if(j==jmax){
                continue;
            }
            printf("%4i",a[i][j]);
        }
        printf("\n");
    }
    SetColor(2);
    printf("\n\n(685)Массив С(пересечение двух диагоналей заменено минимумом элементов главное и побочной диагоналей):\n");
    for(i=0;i<n;i++){
        if(min>c[i][i]){
            min = c[i][i];
            imin = jmin = i;
        }
        if(min>a[i][n-i-1]){
            min = c[i][n-i-1];
            imin = i;
            jmin = n-i-1;
        }
    }
    SetColor(5);
    k=c[n/2][n/2];
    c[n/2][n/2] = c[imin][jmin];
    c[imin][jmin] = k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if((i==n/2&&j==n/2)||(i==imin&&j==jmin)){
                SetColor(6);
                printf("%4i",c[i][j]);
                SetColor(5);
            }
            else{
                printf("%4i",c[i][j]);
            }
        }
        printf("\n");
    }



}
