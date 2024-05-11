#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <cstring>
#include <ncurses.h>

struct venta{
    int numero_facatura;
    char nom_art[10];
    int cod_ven;
    int unidades;
    float importe;
};

struct vendedor{
    int cod_ven;
    char nombre[25];
    char direccion[25];
    float sueldo;
};

struct vent_vend{
    int numero_factura;
    char nom_art[25];
    char nom_ven[25];
    int unidades;
    float importe;
};

WINDOW *stdscr;

void mostrat_ventas(FILE *ventas,FILE *vendedores);
void encabezado();
void buscar(FILE *vendedores,int cod, char nombre[25],char direccion[25]);
void crear_m1000(FILE *ventas, FILE *vendedores, FILE *mayor1000);


int main(void){

    FILE *vendedores,*ventas,*mayor1000;

    ventas = fopen("VENTAS.DAT","rb");
    vendedores = fopen("VENDEDORES.DAT","rb");

    if(ventas == NULL || vendedores == NULL){
       perror("Hubo un error en la creacion de los archivos.");
        exit(1);
    }
    mostrat_ventas(ventas,vendedores);
    mayor1000 = fopen("M1000.DAT", "wb");


    if(mayor1000 == NULL){
       perror("No se pudo crear el archivo nuevo.");
        exit(1);
    }

    crear_m1000(ventas,vendedores,mayor1000);
    fclose(ventas);
    fclose(vendedores);
    fclose(mayor1000);

    getch();


    return 0;
}

void mostrar_ventas(FILE *ventas, FILE *vendedores) {
    venta r;
    char auxnom[25], auxdir[25];
    int fila;
    encabezado();

    fread(&r, sizeof(venta), 1, ventas);

    while (feof(ventas) == 0) {
        buscar(vendedores, r.cod_ven, auxnom, auxdir);
        fila = getcury(stdscr) + 1;

        mvprintw(fila, 1, "%d", r.numero_factura);
        mvprintw(fila, 4, "|%s", r.nom_art);
        mvprintw(fila, 15, "|%s", auxnom);
        mvprintw(fila, 41, "|%s", auxdir);
        mvprintw(fila, 67, "|%d", r.unidades);
        mvprintw(fila, 72, "|%.2f", r.importe);

        if (fila == 23) {
            mvprintw(24, 1, "Presione una tecla");
            getch();
            encabezado();
        }

        fread(&r, sizeof(venta), 1, ventas);
    }

    if (fila != 23) {
        mvprintw(24, 1, "Presione una tecla");
        getch();
    }
}


void encabezado(){
    system("cls");
    std::cout<<"|ARTUCILO |NOMBRE VENDEDOR |DIRECCION VENDEDOR |UNID|IMPORTE";
}


void buscar(FILE *vendedores,int cod, char nombre[25],char direccion[25]){

    vendedor v;
    int fin = 0;
    strcpy(nombre,"");
    strcpy(direccion, "");

    rewind(vendedores);

    fread(&r,sizeof(vendedor),1,vendedores);

    while(feof(venta) == 0){
        if(v.cod_ven == cod){
            stdcpy(nombre,v.nombre);
            strcpy(direccion,v.direccion);
            fin = 1;
        }

        fread(&v,sizeof(vendedor),1,vendedores);
    }

}

void crear_m1000(FILE *ventas, FILE *vendedores, FILE *mayor1000){

    venta r;
    vent_vend p;
    char auxnom[25],auxdir[25];
    rewind(ventas);

    fread(&r,sizeof(venta),1,ventas);

    while(feof(ventas) == 0){
        if(r.importe > 1000){
            buscar(vendedores,r.cod_ven,auxnom,auxdir);
            p.numero_factura = r.numero_facatura;

            strcpy(p.nom_art,r.nom_art);
            strcpy(p.nom_ven,auxnom);

            p.unidades = r.unidades;
            p.importe = r.importe;

            fwrite(&p,sizeof(vent_vend),1,mayor1000);
        }

        fread(&r,sizeof(vent_vend),1,ventas);
    }
    std::cout<<"Archivo nuevo creado.";
}











