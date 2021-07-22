#include <iostream>
using namespace std;

int *a,m=3,n=9;

void generate(int num , int last){
    if (num == m){
        for (int i = 0; i < m; i++)
            cout<<a[i];
    cout<<endl;
    }
    for (int i = last + 1; i <= n; i++){
        a.push_back(i);
        generate(num + 1, i);
        a.pop_back();
    }
}
main(){
    a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = rand()%10;
    generate(0 , 0);

}
