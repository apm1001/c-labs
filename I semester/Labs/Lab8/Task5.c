#include<stdio.h>
#include<conio.h>
main()
{
int k=0;
int m=1;
int l=2;
printf("%10c%10c%10c\n------------------------------------------------",'k','m','l');
Loop1:
{

switch(k)
{
case 1: k-=++m+l;
case 2: k+=m; break;
case 3: m+=++k*l++;
case 4: l+=++m+l; break;
case 5: k+=l+=m;
case 6: m+=--l; break;
case 7: k+=m--;
case 8: k+=l; break;

default: k+=--l*m;break;
}
printf("\n%10i%10i%10i",k,m,l);
}
k++;
if(k<20) goto Loop1;
}
