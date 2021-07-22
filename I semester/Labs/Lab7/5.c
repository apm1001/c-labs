#include <stdio.h>
#include <conio.h>

main()
{
int x = 3, y = 1, z = 2;
z+=++x-y++;
printf ("\nx=%i y=%i z=%i", x, y, z);
printf ("\nSTEP I ==> %i", (x-->++z)?(y+=x):(z-=y));
printf ("\nx=%i y=%i z=%i", x, y, z);
printf ("\nSTEP II ==> %i", (y++>++z)?(z+=x-y):(y-=x+z));
printf ("\nx=%i y=%i z=%i", x, y, z);
printf ("\nSTEP III ==> %i", (x<++z-y++)?(x*=z-y):(z-=y));
printf ("\nx=%i y=%i z=%i", x, y, z);
printf ("\nSTEP IV ==> %s", (y<x>z)? "yes":"no");
printf ("\nx=%i y=%i z=%i", x, y, z);
printf ("\nSTEP V ==> %i", (x==++z)?(y/=x-1):(x*=++y-z--));
printf ("\nx=%i y=%i z=%i", x, y, z);
getch();
}
