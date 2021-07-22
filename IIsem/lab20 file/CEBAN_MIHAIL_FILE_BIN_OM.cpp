#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Я на паре сам придумал себе пункты меню(сумма положительных, количество отрицательных
//и среднее значение всех элементов массива). Дома просто закончил.
int main(){
    int n, i;
    float a;
    FILE *f;
    f = fopen("mih.dat", "wb");
    printf("n=");
    scanf("%i",&n);
    fwrite(&n, sizeof(int), 1, f);
    for(i=0;i<n;i++){
        printf("element %i = ",i+1);
        scanf("%f",&a);
        //printf("%.")
        fwrite(&a,sizeof(float), 1, f);
    }
    fclose(f);

    n = 0;
    f = fopen("mih.dat", "rb+");
    fread(&n, sizeof(int), 1, f);
    printf("n = %i\n",n);

    float aa[n];
    fread(aa, sizeof(float), n, f);
    for(int i=0;i<n;i++){
        printf("%7.2f",aa[i]);
    }
    printf("\n");

    int k,poz,quant;
    float sum=0,elem;
    float med=0;
    printf("\n1)SUM of positive elements\n2)Quantity of negative elements\n3)Media of all elements\n-->");
    scanf("%i",&k);
    switch(k){
    case 1:
        sum=0;
        for(i=0;i<n;i++){
            if(aa[i]>0){
                poz = i;
                fseek(f,sizeof(int)+poz*sizeof(float), 0);
                fread(&elem,sizeof(float), 1, f);
                printf("\n%f",elem);
                sum+=elem;
            }

        }
        fseek(f,sizeof(int)+n*sizeof(float), 0);
        fwrite(&sum,sizeof(float), 1, f);
        sum = 0;
        fseek(f,sizeof(int)+n*sizeof(float), 0);
        fread(&sum,sizeof(float), 1, f);
        printf("\nAnswer is %.2f",sum);
        break;
    case 2:
        quant = 0;
        for(int i =0;i<n;i++){
            if(aa[i]<0){
                quant++;
            }
        }
        fseek(f,sizeof(int)+n*sizeof(float), 0);
        fwrite(&quant,sizeof(int), 1, f);
        quant = 0;
        fseek(f,sizeof(int)+n*sizeof(float), 0);
        fread(&quant,sizeof(int), 1, f);
        printf("\nAnswer is %i",quant);
        break;
    case 3:
        quant = 0;
        sum=0;
        for(i=0;i<n;i++){
            poz = i;
            fseek(f,sizeof(int)+poz*sizeof(float), 0);
            fread(&elem,sizeof(float), 1, f);
            sum+=elem;
            quant++;
        }
        med = sum/quant;
        fseek(f,sizeof(int)+n*sizeof(float), 0);
        fwrite(&med,sizeof(float), 1, f);
        med = 0;
        fseek(f,sizeof(int)+n*sizeof(float), 0);
        fread(&med,sizeof(float), 1, f);
        printf("\nAnswer is %.2f",med);
        break;
    }
    return 0;
}
