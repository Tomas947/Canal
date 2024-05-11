#include <stdio.h>
#include <stdlib.h>

int main(){

    int *array;//es un puntero de tipo int*
    int numElemtos;// tammaño del vector
    int i;

    int vector[10];

    numElemtos = 10;

    //creamos el array(vector) reservando memoria dinamica

    array = (int*)malloc(numElemtos*sizeof(int));

    for(i = 0; i < numElemtos; i++){
        array[i] = i;// que es equivalente a *(array + i)   &
    }

    for(i = 0; i < numElemtos; i++){
        printf("[%d]", *(array+i));
    }

    free(array);

    return 0;
}
