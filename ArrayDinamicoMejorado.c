#include<stdio.h>
#include<stdlib.h>

/*Escriba un programa que lea un array de caracteres, carácter a carácter e imprima dicho array carácter a carácter.
La introducción de los datos debe finalizar con el salto de linea */

char *leerMensaje(void){

    char *pchar;
    char *nuevo_pchar;
    int nChar;//cantidad de caracteres
    int ultimo;
    int contador;

    nChar = 1;
    ultimo = 0;
    contador = 0;

    //se reserva memoria para un unico caracter

    pchar = (char*)malloc(sizeof(char) * nChar);// *void //pchar = new int[nChar]

    if(pchar == NULL){
        perror("malloc:");
        return NULL;
    }

    //Se lee un caracter
    scanf("%c", &(pchar[ultimo]));

    //Se lle el resto de los caracteres

    while(pchar[ultimo] != '\n'){// que es equivalente a decir "pchar[ultimo]"

        //se incrementa el numero de caracteres
        nChar++;

        //Se aumenta el espacio de memoria

        nuevo_pchar = realloc(pchar, sizeof(char) * (nChar));//es como malloc pero para aumentar el tamaño no para inicializar

        //Si se produce un error se liberara la memoria reservada y finalizara la ejecucion

        if(nuevo_pchar == NULL){
            perror("realloc:");
            free(pchar);
            return NULL;
        }

        /*Se incrementa el indice del ultimo
         *tambien se actuliza el puntero 'pchar'
         */
         ultimo++;
         pchar = nuevo_pchar;
         contador++;

         //Se lee un caracter
         scanf("%c", &(pchar[ultimo]));

    }
         //Se cambia el '\n' por \0
    pchar[ultimo] = '\0';

    //devolvemos el vector leido

    printf("\nLa cantidad de elementos que posee el vector es: [%i] \n\n", contador);

    return pchar;


}

int main(void){

    char *msg;
    int i;

    //Leemos una linea por la entrada estandar
    printf("Introdusca un mensaje terminado con la ");
    printf("tecla<into>:\n");
    msg = leerMensaje();

    printf("El mensaje es: \n");

    if(msg != NULL){

        for(i = 0; msg[i] != '\0'; i++){
            printf("%c",msg[i]);
        }
        printf("\n");
    }

    //Liberar la memoria usada

    free(msg);

    return 0;

}
















