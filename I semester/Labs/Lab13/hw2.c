#include <stdio.h>

main()
{
    int x,y,*xx,*yy;
    printf("x=");
    xx=&x;
    scanf("%i",xx);
    printf("x=%i  &x=%i  *xx=%i  %i\n",x,&x,*xx,xx+2);
    *xx=5; printf("x=%i\n",x);

    yy=&y;
    printf("y=");
    scanf("%i",yy);
    printf("y=%i  &y=%i  *yy=%i\n",y,&y,*yy);
    *yy=50; printf("y=%i\n",y);
    x-=*xx; printf("x=%i  *xx=%i  %i\n",x,*xx,xx+2);
    (*xx)--; printf("x=%i  &x=%i  xx=%i\n",x,&x,xx);
    *xx+=*yy; printf("x=%i  &x=%i  xx=%i\n",x,&x,xx);
    *xx-=*yy; printf("x=%i  &x=%i  xx=%i\n",x,&x,xx);
    *xx=*yy%*xx; printf("x=%i  &x=%i  xx=%i  *yy/*xx=%f\n",x,&x,xx,(float)*yy/(float)(*xx));
    *yy=(x+y)*6; printf("x=%i  y=%i  yy=%i  xx=%i\n",x,y,yy,xx);
    *xx=2-*yy+*xx*10; printf("x=%i  y=%i  yy=%i  xx=%i\n",x,y,yy,xx);

    int z=500,*zz;
    zz=&z; printf("x=%i  y=%i  z=%i  zz=%i  yy=%i  xx=%i\n",x,y,z,zz,yy,xx);
    *zz-=x+y-2*(*xx); printf("x=%i  y=%i  z=%i  zz=%i  yy=%i  xx=%i\n",x,y,z,zz,yy,xx);
    zz=yy-xx; printf("x=%i  y=%i  z=%i  zz=%i  yy=%i  xx=%i\n",x,y,z,zz,yy,xx);
    int h=-3,*hh;
    hh=&h; printf("x=%i  y=%i  z=%i  h=%i  hh=%i  zz=%i  yy=%i  xx=%i\n",x,y,z,h,hh,zz,yy,xx);
    *hh=z+*xx-y; printf("x=%i  y=%i  z=%i  h=%i  hh=%i  zz=%i  yy=%i  xx=%i\n",x,y,z,h,hh,zz,yy,xx);
    zz=zz-yy; printf("x=%i  y=%i  z=%i  h=%i  hh=%i  zz=%i  yy=%i  xx=%i\n",x,y,z,h,hh,zz,yy,xx);

}
