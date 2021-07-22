#include <color.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

void out(float x[],int n, int i){
    if (i<n){
        printf("%10g",x[i]);
        out(x,n,i+1);
    }
}
void method1(float x[],int n, int i){
    if(i<n&&i>1){
        x[i] = x[i-1]/2.0+3*x[i-2]/4.0;
        method1(x,n,i+1);
    }
    else if(i<2){
        x[0]=0;
        x[1]=5/8.0;
        method1(x,n,2);
    }
}
void method2(float x[],int n, int i){
    if(i<n&&i>1){
        x[i] = (i+1)*x[i-2];
        method2(x,n,i+1);
    }
    else if(i<2){
        x[0]=1.0;
        x[1]=0.3;
        method2(x,n,2);
    }
}
void method3(float x[],int n, int i){
    if(i<n&&i>2){
        x[i] = (i+3)*(x[i-1]-1)+(i+4)*x[i-3];
        method3(x,n,i+1);
    }
    else if(i<2){
        x[0]=x[1]=x[2]=1;
        method3(x,n,3);
    }
}
float suma1(float x[],int n,int i,float o){
    if(i<n){
        return x[i]/o+suma1(x,n,i+1,o);
    }
    else{
        return 0;
    }
}
float pr1(float x[],int n,int i){
    if(i<n){
        return log(1+x[i])*pr1(x,n,i+1);
    }
    else{
        return 1;
    }
}
float suma2(float x[],int n,int i){
    if(i<n-1){
        return x[i]*x[i+1]+suma2(x,n,i+1);
    }
    else{
        return 0;
    }
}
int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    SetColor(15);
Menu:
    int k, n=4,i=0,m,p;
    float a[50],o;
    printf("Type dimension of array N = ");
    scanf("%i",&n);
M1:
    printf("\nChoose the case:\n1)\n2)\n3)\n-->");
    scanf("%i",&p);
    switch(p){
    case 1:
        method1(a,n,0);
        out(a,n,i);
    M2:
        printf("\n(o!=0)o = ");
        scanf("%f",&o);
        printf("\n(m<n)m = ");
        scanf("%i",&m);
        if(m<n&&m>0&&o!=0){
            printf("Sum from 0 to m of x[i]/o = %.2f",suma1(a,m,0,o));
        }
        else{
            printf("Error!Try again!");
            goto M2;
        }
        break;
    case 2:
        method2(a,n,0);
        out(a,n,i);
    M4:
        printf("\n(k<n)k = ");
        scanf("%i",&k);
        if(k<n&&k>0){
            printf("P of log(1+x[i]) = %.2f",pr1(a,k,0));
        }
        else{
            printf("Error!Try again!");
            goto M4;
        }
        break;
    case 3:
        method3(a,n,0);
        out(a,n,i);

        printf("\nSum(x[1]*x[2]+x[2]*x[3]+...) = %.2f",suma2(a,n,0));
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
