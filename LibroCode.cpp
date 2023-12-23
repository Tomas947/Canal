#include<stdio.h>
#define N 3

int main(){

    int matriz[N][N];
    int i,j;
    int minimo;
    int iMin,jMin;

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("Introduce los elementos de la matriz [%d][%d]: ",i,j);
            scanf("%d", &matriz[i][j]);
        }
    }
    minimo = matriz[0][0];
    jMin = iMin = 0;

    printf("\n");

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("[%d]", matriz[i][j]);
        }
         printf("\n");
    }



    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(matriz[i][j] < minimo){
                minimo = matriz[i][j];
                jMin = j;
                iMin = i;
            }
        }
    }
    printf("\nEl elemeto %d esta en la fila %d, y columna %d\n", minimo, iMin, jMin);

    return (0);

}

