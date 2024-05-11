#include <iostream>
//tiene una lista de 100 elementos del 1 al 100, si entre uno de estos elementos se encuentra uno divisible entre tres se imprime LA palabra fizz y si es
//diviceble por 5 la palabra buzz y si es divicible por ambos fizzBuzz
using namespace std;

void rellenarvector();
void imprimir();

int arreglo[100],valor,aux,aux2;


int main(){
    rellenarvector();
    imprimir();
}

void rellenarvector(){
    for(int i = 0; i < 100; i++){
        if(i==0){
            arreglo[i] = i+1;//esto es para que inicie en 1
        }else{
            arreglo[i] = i+1;
        }
    }
}


void imprimir(){
    for(int i = 0; i < 100; i++){

            valor = arreglo[i];
            aux = valor / 3;//las variables son de tipo entero no toman en cuenta los decimales
            aux2 = valor / 5;//para que este algoritmo funcione tiene que ser asi, ya q por ejemplo 1/3 es "0.33" pero aux es de tipo int entonces se guarda "0"
                            //y 3*0 es "0" y "0" es distinto de "1"(que fue la entrada en la variable valor),otro ej: 10/3 es "3.33...." si se muntiplica por 3 daria de vuelta "10"
                            //pero como es de tipo entero/int se redondea y la variable aux queda
                            //de "3" y 3*3 es "9" y 9 es distinto de 10, en otras palabras solo funciona con resultados enteros ya que no hay redondeo
                            //y un numero es divisible por 3 y 5(O por cualquier otro numero) si su resultado es entero, o por lo menos divisible de manera exacta.
            if((aux*3) == valor && (aux2*5) == valor){
                cout<<"FizzBuzz"<<endl;
            }else if((aux*3) == valor){
                cout<<"Fizz"<<endl;
            }else if((aux2*5) == valor){
                cout<<"Buzz"<<endl;
            }else{
                cout<<arreglo[i]<<endl;
            }
    }
    /*/version del chabon del video
    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            cout << "FizzBuzz ";
        } else if (i % 3 == 0) {
            cout << "Fizz ";
        } else if (i % 5 == 0) {
            cout << "Buzz ";
        } else {
            cout << i << " ";
        }
    }
    */
}

//lo bueno de este algoritmo es que es general en el sentido que cambiando los parametro funciona en cualquir numero natural no necesariamente con el 3 o 5

















