#include <iostream>
#include <stdio.h>
#include <string.h>

//Palabras reservadas del lenguaje.
const char *palabras[] = {"ruedas","brazos", "camara", "desplazamiento", "girar", "avanza","adelante","retrocede",
                             "detenerse", "sujetar", "empujar", "tomarFoto", "desplazar"};

//Tipo de datos estado según el automata
enum TEstado {e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16};

//Variable de estados
TEstado Estado;

//Funcion de lectura de los caracteres uno a uno del archivo
void leerCaracter(char caracter);

//Funcion que muestra el estado en que se encuentra
void mostrarECaracter();

//Funcion que busca palabras reservadas en el archivo
void buscaPReservadas();

int main() {
    printf("Analizador Lexico \n");
    // Creación de un fichero, donde se pondran y leeran las instrucciones a ejecutar.
    FILE *archivo;
    //Apertura del archivo
    archivo = fopen("RoverLunar.txt", "r");
    //Variable de almacenamiento de caracter
    char caracter;
    //Estado del archivo
    int existeArchivo = 1;
    //Si el archivo no se encuentra muestra mensaje de error
    if (archivo == NULL) {
        printf("Error archivo no encontrado \n");
        existeArchivo = 0;
        return existeArchivo;
    }
    printf("Leyendo el archivo");
    while(existeArchivo==1){
        //Se almacena la informacion contenida en el archivo
        caracter=fgetc(archivo);

    }
    fclose(archivo);
}
