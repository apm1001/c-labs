#include <stdio.h>
#include <math.h>
double f(double x){
    if(pow(x,2)+2*x-8||pow(x,2)+2*x-3){
        return 24/(pow(x,2)+2*x-8)-15/(pow(x,2)+2*x-3)-2;
    }
    return 1;
}
double func(double a,double b){
    double m=(a+b)/2;
    if(fabs(b-a)<=0.0001) return m;
    if(f(a)*f(m)<=0) return func(a,m);
    if(f(m)*f(b)<=0) return func(m,b);
}
int main(){
    printf("\nAnswer:\n");
    printf("(-3,-1):%.2f\n",func(-3,-1));
    printf("(-1,1):%.2f\n",func(-1,1));
    printf("(-5.3,-5):%.2f\n",func(-5.3,-5));
    printf("(2.3,5):%.2f\n",func(2,3.5));
}
