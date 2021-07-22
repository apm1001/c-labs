#include <stdio.h>
#include <math.h>

main() {
float a=20.3, f, x;
printf("Input x = ");
scanf("%x",&x);
if (x>1) f = log10(x+1);
else f = pow((sin(sqrt(abs(a*x)))),2);
printf("f = %f",f);
}
