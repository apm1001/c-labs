#include <stdio.h>
#include <color.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
struct address{
    char city[20];
    char street[20];
    int nr;
};
struct delivery{
    struct address addr;
    char tel[15];
    char payment[10];
};

struct charact{
    int length;
    int width;
    int height;
};

struct tip{
    char name[20];
    struct charact har;
    float price;
};

struct mebel{
    struct tip type;
    char manufacturer[20];
    int warranty;
    struct delivery del;

};
void input(struct mebel x[],int n){
    bool b=false;
    char ch[30];
    for(int i=0;i<n;i++){
        printf("\nOrder nr. %i\n",i+1);
        b=false;
        while(!b){
            printf("Name of furniture:");scanf("%s",x[i].type.name);
            for(int j=0;j<strlen(x[i].type.name);j++){
                b = isalpha(x[i].type.name[j]);
                if(!b){
                    printf("Wrong name!Try again!Only letters required!\n");
                    break;
                }
            }
        }
        printf("Length of furniture(in cm):");scanf("%i",&x[i].type.har.length);
        printf("Width of furniture(in cm):");scanf("%i",&x[i].type.har.width);
        printf("Height of furniture(in cm):");scanf("%i",&x[i].type.har.height);
        printf("Price of furniture(in dollars):");scanf("%f",&x[i].type.price);
        b=false;
        while(!b){
            printf("Name of manufacturer:");scanf("%s",x[i].manufacturer);
            for(int j=0;j<strlen(x[i].manufacturer);j++){
                b = isalpha(x[i].manufacturer[j]);
                if(!b){
                    printf("Wrong name!Try again!Only letters required!\n");
                    break;
                }
            }
        }
        printf("Telephone number:");scanf("%s",x[i].del.tel);
        printf("Warranty(months):");scanf("%i",&x[i].warranty);
        b=false;
        while(!b){
            printf("Payment method(card or cash):");scanf("%s",x[i].del.payment);
            if(!strcmp(x[i].del.payment,"card")||!strcmp(x[i].del.payment,"cash")){
                b = true;
            }
            else{
                printf("You need to enter words cash or card!\n");
            }
        }
        printf("Address of delivery:\n");
        printf("City:"); scanf("%s",x[i].del.addr.city);
        printf("Street:"); scanf("%s",x[i].del.addr.street);
        printf("Nr. of house:"); scanf("%i",&x[i].del.addr.nr);


    }
}
int main(){
    SetColor(15);
    int n=2;
    printf("Type number of orders:");scanf("%i",&n);
    struct mebel a[n];
    input(a,n);
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------");
    SetColor(3);
    printf("\n|    Name    |   Length   |   Width   |   Height   |   Price   |  Manufacturer  |   Warranty   |  Tel. number  | Payment |   City   |    Street    |Nr. of house|");
    SetColor(15);
    printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < n; i++)
    {
        printf("\n|%12s|%8i sm.|%7i sm.|%8i sm.|%10.2f$|%16s|%7i months|%15s|%9s|%10s|%14s|%12i|",a[i].type.name,a[i].type.har.length,a[i].type.har.width,a[i].type.har.height,
               a[i].type.price,a[i].manufacturer,a[i].warranty,a[i].del.tel,a[i].del.payment,a[i].del.addr.city,a[i].del.addr.street,a[i].del.addr.nr);
        printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------");
    }
}
