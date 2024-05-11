#include <stdio.h>
#define MAX_ELEMENTOS 10

/*
prototipos de las funciones */

void LeerArray(int v[], int *n);
void EscribirArray(const int v[], int n);

/*v es el vector que se lee
n almacena el número de elementos leidos*/

void LeerArray(int v[], int *n){

    int j = 0;// Indice del array
    int ret = 7; //valor de retorno de scanf
    int valor;

    printf("Introduzca un elemento: ");
    ret = scanf("%d", &valor);

    while (ret != EOF && j < MAX_ELEMENTOS) {
        if (ret < 1){

            printf("Error en la introduccion del dato\n");

        }else {

            v[j] = valor;
            j++;
        }

        printf("Introduzca un elemento: ");
        ret = scanf("%d", &valor);
    }

// se devuelve tambien el numero de elementos leids
    *n = j;
    return;
}
void EscribirArray(const int v[], int n){

    int j;

    for(j = 0; j < n; j++){

        printf("El valor del elemnto %d es %d\n",j, v[j]);
        return;
    }

}

int main(void){

    int array[MAX_ELEMENTOS];
    int elementos;//alñmacena el numero de elemtos de array

    LeerArray(array, &elementos);
    EscribirArray(array,elementos);

    return 0;
}



















