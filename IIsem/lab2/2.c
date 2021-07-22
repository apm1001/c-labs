#include <stdio.h>
#include "color.h"
#include <time.h>
#include <stdbool.h>
//23 var
main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    const int n = 20;
    int a[n],i,max=-999999,min=999999,sum = 0,pr=1;

    ClearConsoleToColors(2,7);
    printf("Массив А:\n");

    for(i = 0;i<n;i++){
        printf("%4i",i);
    }
    printf("\n");
    SetColor(5);
    for(i = 0;i<n;i++){
        a[i] = (rand()%50)-25;
        printf("%4i",a[i]);
    }

    SetColor(2);
    //1)max(min(a[1+k,3+k...],max(nechet))
    int k;
    printf("\nK = ");scanf("%i",&k);
    for(i = 0;i<n;i++){
        if((2*i+1+k)>=n) break;
        else
            if(a[2*i+1+k]<min) min = a[2*i+1+k];
    }
    for(i=0;i<n/2;i++){
        if(a[2*i+1]>max) max = a[2*i+1];
    }
    printf("Max(%i,%i) = %i",min,max,max>min?max:min);

    //2)max(sum(el. del. na 3),pr(del. na 5))
    for(i=0;i<n;i++){
        if(a[i]%3==0)sum+=a[i];
        if(a[i]%5==0&&a[i]!=0)pr*=a[i];
    }
    printf("\nMax(%i,%i) = %i",sum,pr,sum>pr?sum:pr);

    //3)pervie 3 el, summa indexov kotorih delitsia na 3
    for(i=0;i<n-2;i++){
        if((i+i+1+i+2)%3==0){
            k = i;
            a[i] = a[i+1] = a[i+2] = 5;
            break;
        }
    }
    printf("\nЗамена первых 3 элементов, сумма индексов которых делится на 3:\n");
    for(i = 0;i<n;i++){
        printf("%4i",i);
    }
    printf("\n");
    SetColor(5);
    for(i = 0;i<n;i++){
        if(i==k||i==k+1||i==k+2){
            SetColor(1);
            printf("%4i",a[i]);
            SetColor(5);
        }
        else printf("%4i",a[i]);
    }
    SetColor(2);

    //4)Если произведение(4-х отрицательных от конца на четных позициях)>0, определить если сумма эл-ов делящихся на p<t
    pr = 1;
    sum = 0;
    k=0;
    int p,t;
    printf("\np = ");scanf("%i",&p);
    printf("t = ");scanf("%i",&t);
    for(i=n-1;i>=0;i--){
        if(i%2==0&&a[i]<0){
            pr*=a[i];
            k++;
        }
    }
    if(pr>0){
        for(i=0;i<n;i++){
            if(a[i]%p==0)sum+=a[i];
        }

    if(sum<t){
        printf("\nСумма элементов, делящихся на %i (%i) меньше %i",p,sum,t);
    }
    else{
        printf("\nСумма элементов, делящихся на %i (%i) не меньше %i",p,sum,t);
    }
    }

}
