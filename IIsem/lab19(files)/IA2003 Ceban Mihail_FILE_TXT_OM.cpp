#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define forLoop for(int i=0;i < n;i++)

bool del(int x,int y){
    if(x%y==0){
        return true;
    }
    else{
        return false;
    }
}

int Max(int o,int y){
    if(o>y){
        return o;
    }
    else return y;
}

int Min(int o,int y){
    if(o>y){
        return y;
    }
    else return o;
}

void outputArr(int *x,int n){
    printf("\nArray:\n");
    for(int i=0;i<n;i++){
        printf("%6i",x[i]);
    }
}
void inputArrRand(int *x,int n){
    for(int i=0;i<n;i++){
        x[i] = rand()%100-20;
    }
}
void inputArrKeyB(int *x,int n){
    for(int i=0;i<n;i++){
        printf("A(%i) = ",i);
        scanf("%i",&x[i]);
    }
}
void f1(int x[20],int n,FILE *f){
    int k,min=999999,max=-999999;
    printf("\nK = ");
    scanf("%i",&k);
    forLoop{
        if((2*i+1+k)>=n) break;
        else
            min = Min(x[2*i+1+k],min);
    }
    forLoop{
        i++;
        if((2*i+1+k)>=n) break;
        else
            max = Max(x[2*i+1],max);
    }
    printf("Max(%i,%i) = %i",min,max,Max(min,max));
    fprintf(f,"Max(%i,%i) = %i",min,max,Max(min,max));
}
void f2(int x[20],int n,FILE *f){
    int sum=0,pr=1;
    forLoop{
        if(del(x[i],3))sum+=x[i];
        if(del(x[i],5)&&x[i]!=0)pr*=x[i];
    }
    printf("\nMax(%i,%i) = %i",sum,pr,Max(sum,pr));
    fprintf(f,"\nMax(%i,%i) = %i",sum,pr,Max(sum,pr));
}
void f3(int x[20],int n,FILE *f){
    printf("\nРешение\n");
    forLoop{
        if(x[i]==0){
            x[i]=5;
        }
    }
    outputArr(x,n);
    fprintf(f,"\nРешение:\n");
    for(int i = 0;i<n;i++){
        fprintf(f,"%5i",x[i]);
    }
}
void f4(int x[20],int n,FILE *f){
    int pr=1,sum=0,k=0;
    int p,t;
    printf("\np = ");
    scanf("%i",&p);
    printf("t = ");
    scanf("%i",&t);
    forLoop{
        if(x[i]<0){
            pr*=x[i];
        }
        i++;
    }
    if(pr>0){
        forLoop{
            if(del(x[i],p))sum+=x[i];
        }

        if(sum<t){
            fprintf(f,"\nСумма элементов, делящихся на %i (%i) меньше %i",p,sum,t);
            printf("\nСумма элементов, делящихся на %i (%i) меньше %i",p,sum,t);
        }
        else{
            fprintf(f,"\nСумма элементов, делящихся на %i (%i) не меньше %i",p,sum,t);
            printf("\nСумма элементов, делящихся на %i (%i) не меньше %i",p,sum,t);
        }
    }
    else{
        fprintf(f,"\nПроизведение отрицательных меньше нуля!!");
        printf("\nПроизведение отрицательных меньше нуля!!");
    }

}
int main(){


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
Menu:
    int k,N;
    char ch;
    printf("\nВведите размерность массива N = ");
    scanf("%i",&N);
    printf("\nВыберите способ ввода массива:\n1 - с клавиатуры\n2 - случайно -->");
    scanf("%i",&k);
    int a[N];
    switch(k){
    case 1:
        inputArrKeyB(a,N);
        break;
    case 2:
        inputArrRand(a,N);
        break;
    default:printf("Вы ввели неверное значение, попробуйте еще раз!!!");goto M3;
    }
    outputArr(a,N);
    FILE *f;
    f = fopen("2.txt","w+");
    fprintf(f,"Array A\n");
    for(int i=0;i<N;i++){
        fprintf(f,"%6i",a[i]);
    }

M1:
    printf("\nВыберите случай:\n1)max(min(a[1+k],a[3+k],..),max(нечет))\n2)max(summ(эл-ов делящ. на 3), произведения элементов делящихся на 5)\n3)все эл-ты - 0 заменить на 5\n4)если произведение(отрицательных на четных поз)>0, определить если сумма элементов делящихся на p < t\n-->");
    ch = getche();
    switch(ch){
    case '1':
        f1(a,N,f);
        break;
    case '2':
        f2(a,N,f);
        break;
    case '3':
        f3(a,N,f);
        break;
    case '4':
        f4(a,N,f);
        break;
    default:printf("Недопустимое значение, попробуйте еще раз!!");goto M1;
    }
    fclose(f);
M3:
    printf("\nПовторить ?(1-да)(2-завершить программу)-->");
    scanf("%i",&k);
    switch(k){
    case 1:goto Menu;
    case 2:break;
    default:printf("Вы ввели неверное значение, попробуйте еще раз!!!");goto M3;
    }
}
