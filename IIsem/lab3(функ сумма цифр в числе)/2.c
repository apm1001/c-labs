#include <stdio.h>
#include "color.h"
#include <time.h>
#include <stdbool.h>
#include <conio.h>
int sum_num(x){
    int sum=0;
    if(x<0){
        x*=-1;
    }
    while(x/10>0){
        sum+=x%10;
        x/=10;
    }
    sum+=x;
    return sum;
}
main(){


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    ClearConsoleToColors(2,7);
    const int p = 50;
    int l;
    int a[p],i,m,m1,k=0;
    int k1[p],x[p],y[p],sov[4] = {6,28,496,8128},sk,sk1;
Menu:
    printf("\nВыберите задание (4 или 5)-->");
    scanf("%i",&l);
    switch (l)
    {
        case 4:
    printf("Массив А:\n");

    for(i = 0;i<p;i++){
        printf("%4i",i);
    }
    printf("\n");
    SetColor(5);
    for(i = 0;i<p;i++){
        a[i] = (rand()%50)-25;
        printf("%4i",a[i]);
    }
    SetColor(2);

    printf("\nm = "); scanf("%i",&m);

    printf("\n");
    for(i=0;i<p;i++){
        printf("%4i",sum_num(a[i]));
    }
    printf("\n");
    for(i=0;i<p;i++){
        if((sum_num(a[i])%m)==0){
            m1 = i;
            break;
        }
    }
    k=0;
    printf("\nВыполнение условия задания:\n");
    for(i = 0;i<p;i++){
        if(i>=m1&&k<3&&a[i]<0){
            k++;
            SetColor(3);
            printf("%4i",i);
            SetColor(2);
        }
        else{
            printf("%4i",i);
        }
    }
    SetColor(5);
    printf("\n");
    k=0;
    for(i = 0;i<p;i++){
        if(i>=m1&&k<3&&a[i]<0){
            k++;
            SetColor(3);
            printf("%4i",a[i]);
            SetColor(5);
        }
        else{
            printf("%4i",a[i]);
        }
    }
    SetColor(2);
    printf("\nПовторить ?(1 - да;2 - завершить программу)-->");
    scanf("%i",&l);
    if (l == 1){
        goto Menu;
    }
    break;
case 5:
    printf("Массив K:\n");

    for(i = 0;i<p;i++){
        printf("%3i",i);
    }
    printf("\n");
    SetColor(5);
    for(i = 0;i<p;i++){
        k1[i] = rand()%30;
        printf("%3i",k1[i]);
    }
    SetColor(2);
    sk=0;sk1=0;
    x[0] = y[0] = 0;
    printf("\nМассив К:\n");
    for(i=0;i<p;i++){
        if((i%2==0)&&(k1[i]==sov[0]||k1[i]==sov[1]||k1[i]==sov[2]||k1[i]==sov[3])){
            SetColor(8);
            printf("%3i",i);
            SetColor(2);
        }
        else if((i%2!=0)&&i>0&&i<p-1&&(((k1[i-1]+k1[i]+k1[i+1])/3.0)>10)){
            SetColor(9);
            printf("%3i",i);
            SetColor(2);
        }
        else
            printf("%3i",i);
    }
    printf("\n");
    for(i=0;i<p;i++){
        if((i%2==0)&&(k1[i]==sov[0]||k1[i]==sov[1]||k1[i]==sov[2]||k1[i]==sov[3])){
            x[sk] = k1[i];
            sk++;
            SetColor(8);
            printf("%3i",k1[i]);
            SetColor(2);
        }
        else if((i%2!=0)&&i>0&&i<p-1&&(((k1[i-1]+k1[i]+k1[i+1])/3.0)>10)){
            y[sk1] = k1[i];
            sk1++;
            SetColor(9);
            printf("%3i",k1[i]);
            SetColor(2);
        }
        else
            printf("%3i",k1[i]);

    }
    printf("\nРазделение на массивы X и Y:\n");
    if(x[0]!=0){
        printf("Массив X(расположены на нечетных позициях и являются совершенными числами):\n");
    for(i = 0;i<sk;i++){
        printf("%3i",i);
    }
    printf("\n");
    SetColor(8);
    for(i = 0;i<sk;i++){
        printf("%3i",x[i]);
    }
    SetColor(2);
    }
    else{
        printf("\nНи одно значение не подошло под условие для массива X!!!");
    }
    if(y[0]!=0){
        printf("\nМассив Y(расположены на нечетных позициях и у которых среднее арифметическое этого элемента и его соседей больше 10):\n");

    for(i = 0;i<sk1;i++){
        printf("%3i",i);
    }
    printf("\n");
    SetColor(9);
    for(i = 0;i<sk1;i++){
        printf("%3i",y[i]);
    }
    SetColor(2);
    }
    else{
        printf("\nНи одно значение не подошло под условие для массива Y!!!");
    }

    printf("\nПовторить ?(1 - да;2 - завершить программу)-->");
    scanf("%i",&l);
    if (l == 1){
        goto Menu;
    }
    break;
    default: printf("\nНеправильное значение, попробуйте еще раз!!"); goto Menu;

    }


}
