#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>
main()
{
    int i,k,n,a=0.5,b=3.1,nr,l,letter_num,main_max,main_min;
    float x[10],z[10],w[10],sum,p,max,sum2;
    char ch;
    bool b_sum = false, b_p = false, b_sum2 = false;

        printf("Enter array dimension (n<=10) n = "); scanf("%d",&n);
        printf("Enter array elements:\n");
        for(i=0;i<n;i++){
            printf("x[%d] = ",i+1);
            scanf("%f",&x[i]);
        }
        letter_num = 0;
        printf("Enter a name:\n-->");
        while((int)ch!=27)
        {
            ch = getch();
            printf("%c",ch);
            letter_num++;
        }
        letter_num--;
        printf("\nNumber of letters: %d",letter_num);
        printf("\nEnter a serial number Nr = "); scanf("%d",&nr);
        if (letter_num>nr){
                main_max = letter_num;
                main_min = nr;
        }
        else {
            main_max = nr;
            main_min = letter_num;
        }
        m1:
            if (main_max % main_min == 0)
            {
                printf("\n1) or 2) -->");scanf("%d",&l);
                switch(l){
                    case 1:
                        printf("Array Z: \n");
                        for(i=0;i<n;i++){
                            z[i]=sqrt(a*x[i]*sin(2*x[i])+exp(-2*x[i])*(x[i]+b));
                            printf("%7.2f",z[i]);
                            sum+=z[i];
                        }
                        printf("\nSum = %.2f",sum);
                        b_sum = true;
                        if (!b_p){
                            printf("\nTry again? (1-yes|2-no) -->"); scanf("%d",&i);
                            if (i==1) goto m1;
                        }
                        break;
                    case 2:
                        p = 1;
                        printf("Array W: \n");
                        for(i=0;i<n;i++){
                            w[i]=pow(cos(pow(x[i],3)),2)-x[i]/pow(pow(a,2)+pow(b,2),1/2);
                            printf("%7.2f",w[i]);
                            if (w[i]!=0 && w[i]>letter_num) p*=w[i];
                        }
                        printf("\nThe number obtained as a result of multiplication p = %.2f",p);
                        if (!b_sum){
                            printf("\nTry again? (1-yes|2-no) -->"); scanf("%d",&i);
                            if (i==1) goto m1;
                        }
                        break;
                    default: printf("Wrong value! Try again!"); goto m1;
                }
                if (b_p && b_sum) {
                    if (p>sum)
                        max = p;
                    else max = sum;
                    printf("\nmax(%.2f,%.2f) = %.2f",sum,p,max);
                }
            }
            else
            {
                printf("\n1) or 2) -->");scanf("%d",&l);
                switch(l){
                    case 1:
                        sum = 0.0;
                        printf("Array Z: \n");
                        for(i=0;i<n;i++){
                            z[i]=sqrt(a*x[i]*sin(2*x[i])+exp(-2*x[i])*(x[i]+b));
                            printf("%7.2f",z[i]);
                            if (z[i]>nr)
                                sum = sum + z[i];
                        }
                        printf("\nSum = %.2f",sum);
                        b_sum = true;
                        if (!b_sum2){
                            printf("\nTry again? (1-yes|2-no) -->"); scanf("%d",&i);
                            if (i==1) goto m1;
                        }
                        break;
                    case 2:
                        printf("Array W: \n");
                        for(i=0;i<n;i++){
                            w[i]=pow(cos(pow(x[i],3)),2)-x[i]/pow(pow(a,2)+pow(b,2),1/2);
                            printf("%7.2f",w[i]);
                            if (w[i]>main_max && w[i]<main_min) sum2+=w[i];
                        }
                        printf("\nSum2 = %.2f",sum2);
                        if (!b_sum){
                            printf("\nTry again? (1-yes|2-no) -->"); scanf("%d",&i);
                            if (i==1) goto m1;
                        }
                        break;
                    default: printf("Wrong value! Try again!"); goto m1;
                }
            }
    return 0;
}
