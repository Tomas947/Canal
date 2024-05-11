#include <stdio.h>
#include <stdlib.h>

/*Escriba un programa que lea un array de caracteres, carácter a carácter e imprima dicho array carácter a carácter.
La introducción de los datos debe finalizar con el salto de linea */

char *leerMensaje(void){

    char *pChar;
    char *nuevo_pChar;
    int ultimo;
    int nChar;
    int contador;


    ultimo = 0;
    nChar = 1;
    contador = 0;


    pChar = (char*)malloc(sizeof(char)* nChar);

    if(pChar == NULL){
        perror("malloc: ");
        return NULL;
    }

    *(pChar + ultimo) = getc(stdin);
    //printf("caracter: %c\n", caracter);
 //   scanf("%c", &(*(pChar + ultimo)));

    while(*(pChar + ultimo) != '\n'){


        nChar++;

        nuevo_pChar = (char*) realloc(pChar, sizeof(char) * (nChar));//es como malloc pero para aumentar el tamaño no para inicializar

        if(nuevo_pChar == NULL){
            perror("realloc:");
            free(pChar);
            return NULL;
        }

         ultimo++;
         pChar = nuevo_pChar;
         contador++;

         scanf("%c", &(pChar[ultimo]));

    }

    (*(pChar + ultimo)) = '\0';

    printf("La cantidad de elementos que posse el vector es: [%i]\n\n", contador);

    return pChar;

}


int main(void){


    char *msg;
    int i;

    printf("Introdusca una oracion: \n");
    msg = leerMensaje();

    printf("El mensaje es: \n");

    if(msg != NULL){

        for(i = 0; *(msg + i) != '\0'; i++){
            printf("%c", *(msg + i) );
        }
        printf("\n");
    }

    free(msg);

    return 0;


}






















