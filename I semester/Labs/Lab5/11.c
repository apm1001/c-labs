#include <stdio.h>
#include <math.h>

int main(){
float a, x, y;
float t;
printf("a="); scanf("%f", &a);
printf("x="); scanf("%f", &x);
printf("y="); scanf("%f", &y);
if (x==0) {
printf("znamenatel ne mojet biti =0");
}
else if(a*y-abs(pow(y,2)-pow(x,2))<0) {
printf("virajenie pod cornem ne moej biti < 0");
}
else {
t=sqrt(a*y-abs(pow(y,2)-pow(x,2)))/pow(x,2);
printf("t=%f", t);
}
return 0;
}
