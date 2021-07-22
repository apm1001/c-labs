#include <color.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
struct str { int a;}; str a;
void inputKey(int x[],int n, int i){
    if (i<n){
        printf("a[%i] = ",i);
        scanf("%i",&x[i]);
        inputKey(x,n,i+1);
    }
}
void inputRand(int x[],int n, int i){
    if (i<n){
        x[i] = rand()%200-10;
        inputRand(x,n,i+1);
    }
}
void out(int x[],int n, int i){
    if (i<n){
        printf("%4i",x[i]);
        out(x,n,i+1);
    }
}
int suma(int x[],int n,int i,int y){
    if(i>=n){
        return 0;
    }
    else if(x[i]%y==0){
        return x[i]+suma(x,n,i+1,y);
    }
        else{
            return suma(x,n,i+1,y);
        }
}
int pr(int x[],int n, int i){
    if(i>=n){
        return 1;
    }
    else if(x[i]%5==0&&x[i]!=0){
        return x[i]*pr(x,n,i+1);
    }
        else{
            return pr(x,n,i+1);
        }
}
int kol(int x[],int n, int i){
    if(i<n){
        if(x[i]==0&&i%5==0){
            return 1+kol(x,n,i+1);
        }
        else{
            return kol(x,n,i+1);
        }
    }
    else{
        return 0;
    }
}
int prOtr(int x[],int n,int i){
    if(i<n){
        if(x[i]<0&&i%2==0){
            return x[i]*prOtr(x,n,i+1);
        }
        else{
            return prOtr(x,n,i+1);
        }
    }
    return 1;
}
int Max(int o,int y){
    if(o>y){
        return o;
    }
    else return y;
}
int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    SetColor(15);
Menu:
    int k, n=4,a[50],i=0,m,p;
    printf("Type dimension of array N = ");
    scanf("%i",&n);
    printf("Input with keyboard or random?(1 | 2)\n-->");
    scanf("%i",&k);
    if(k==1){
        inputKey(a,n,0);
    }
    else{
        inputRand(a,n,0);
    }
    out(a,n,0);
M1:
    printf("\nChoose the case:\n2)\n3)\n4)\n-->");
    scanf("%i",&k);
    switch(k){
    case 2:
        printf("Answer: %i",Max(suma(a,n,0,3),pr(a,n,0)));
        break;
    case 3:
        printf("Answer: %i",kol(a,n,0));
        break;
    case 4:
        printf("m = ");
        scanf("%i",&m);
        printf("p = ");
        scanf("%i",&p);
        if(prOtr(a,n,0)>0){
            if(suma(a,n,i,m)<p){
                printf("Сумма элементов, делящихся на m меньше p");
            }
            else{
                printf("Сумма элементов, делящихся на m не меньше p");
            }
        }
        else{
            printf("Произведение отрицательных на четных позициях меньше 0");
        }
        break;
    default:
        printf("Wrong value!Try again!");
        goto M1;
    }

M3:
    printf("\nПовторить ?(1-да)(2-завершить программу)-->");
    scanf("%i",&k);
    switch(k){
    case 1:goto Menu;
    case 2:break;
    default:printf("Вы ввели неверное значение, попробуйте еще раз!!!");goto M3;
    }

}
