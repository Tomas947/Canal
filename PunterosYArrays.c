#include <stdio.h>

void f(int a[],int n);

int b[5];

void f(int a[],int n){
    printf("sizeof(a): %d \n", sizeof(a));
    printf("sizeof(b): %d",n);
}

int main(){

    f(b, sizeof(b));
    return 0;
}
// sizeof(a) da 4 tamaño equivalente de un puntero de 32 bits(4 bytes)
