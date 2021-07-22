#include<stdio.h>
#include<conio.h>
#include<math.h>
main()
{
double l,a,c,b,d,k;

printf("l=",l);scanf("%d",l);
if(l<-6)
{
printf("\na=",a);scanf("%d",a);
printf("\nd=",d);scanf("%d",d);
k=sqrt(1/(l-a*d));
printf("\nk=%f\tl=%d",k,l);
}
else if(l>=-6 && l<=2)
{
printf("\nb=",b);scanf("%i",b);
for(l;l<=2;l+=0.31) {
k=6*b*l-log(l)/log(3);
printf("\nk=%f\tl=%d",k,l);
}
}
else if((l>2) && (l<5))
{
printf("\nc=",c);scanf("%i",c);
for(l=0;l<=5;l+=0.2)
{
k=1/(sqrt(c-l));
printf("\nk=%f\tl=%d",k,l);
}
}
else
{
k=pow(l,2)-3*cos(l);
printf("\nk=%f\tl=%d",k,l);
}
}
