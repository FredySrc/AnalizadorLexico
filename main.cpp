#include <iostream>
#include <stdio.h>
#include <string.h>



//Funcion de lectura de los caracteres uno a uno del archivo
void leerCaracter(char caracter);

//Funcion que muestra el estado en que se encuentra
void mostrarECaracter();

//Funcion que busca palabras reservadas en el archivo
void buscaPReservadas();

int main() {
    //Palabras reservadas del lenguaje.
    const char *palabras[] = {"ruedas","brazos", "camara", "desplazamiento", "girar", "avanza","adelante","retrocede",
                              "detenerse", "sujetar", "empujar", "tomarFoto", "desplazar"};

    //Tipo de datos estado según el automata
    enum TEstado {e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18};

    //Variable de estados
    TEstado Estado;
    //Estado inicial.
    Estado=e0;
    printf("Analizador Lexico \n");
    // Creación de un fichero, donde se pondran y leeran las instrucciones a ejecutar.
    FILE *archivo;
    //Apertura del archivo
    //Observacion: al momento de ejecucion en otros equipos se debe de escribir la ruta completa del archivo de lectura "RoverLunar.txt".
    archivo = fopen("C:\\Users\\david\\CLionProjects\\AnalizadorLexico\\RoverLunar.txt", "r");
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
    printf("Leyendo el archivo\n");
    printf("-->");
    int tamanioCaracteres=0;
    while(existeArchivo==1){
        //Se almacena la informacion contenida en el archivo
        caracter=fgetc(archivo);
        //se muestra los caracteres leidos del archivo
        printf("%c",caracter);
        tamanioCaracteres++;
        //Verificacion de que se estan leyendo caracteres del archivo
        if (caracter==EOF){
            break;
        }break;}
        //Busqueda de las acciones a solicitar en en archivo
        //de encontrarse los caracteres correspondientes a las funciones principales,
        //como camara, desplazamiento, ruedas y brazos.
        // se cambia el estado.

        if(caracter=='c'&&caracter=='a'&&caracter=='m'&&caracter!='a'&&caracter=='r'&&caracter=='a'){
            printf("Se ha solicitado: camara");
            Estado=e5;
        }
        if(caracter=='r'&&caracter=='u'&&caracter=='e'&&caracter!='d'&&caracter=='a'&&caracter=='s'){
            printf("Se ha solicitado: ruedas");
            Estado=e3;
        }
        if(caracter=='b'&&caracter=='r'&&caracter=='a'&&caracter!='z'&&caracter=='o'&&caracter=='s'){
            printf("Se ha solicitado: camara");
            Estado=e4;
        }
        if(caracter=='d'&&caracter=='e'&&caracter=='s'&&caracter!='p'&&caracter=='l'&&caracter=='a'&&caracter=='z'&&caracter=='a'&&caracter=='m'&&caracter!='i'&&caracter=='e'&&caracter=='n'&&caracter=='t'&&caracter=='o'){
            printf("Se ha solicitado: camara");
            Estado=e6;
        }
        switch (Estado) {
            case e7:
                if(caracter=='g'&&caracter=='i'&&caracter=='r'&&caracter!='a'&&caracter=='r'){
                    printf("Se ha solicitado: ruedas->girar");
                    Estado=e7;}
                if(caracter=='a'&&caracter=='v'&&caracter=='a'&&caracter!='n'&&caracter=='z'&&caracter=='a'){
                    printf("Se ha solicitado: ruedas->avanza");
                    Estado=e7;}
                    break;
            case e8:
                if(caracter=='7'&&caracter=='0'&&caracter=='i'&&caracter!='z'&&caracter=='q'){
                    printf("Se ha solicitado: girar->70izq");
                    Estado=e8;}
                if(caracter=='7'&&caracter=='0'&&caracter=='d'&&caracter!='e'&&caracter=='r'){
                    printf("Se ha solicitado: girar->70der");
                    Estado=e8;}
                if(caracter=='1'&&caracter=='4'&&caracter=='0'&&caracter!='t'&&caracter=='o'&&caracter=='t'&&caracter=='a'&&caracter=='l'){
                    printf("Se ha solicitado: girar->140total");
                    Estado=e8;}
                break;
            case e9:
                if(caracter=='a'&&caracter=='d'&&caracter=='e'&&caracter!='l'&&caracter=='a'&&caracter=='n'&&caracter=='t'&&caracter=='e'){
                    printf("Se ha solicitado: avanza->adelante");
                    Estado=e9;}
                if(caracter=='r'&&caracter=='e'&&caracter=='t'&&caracter!='r'&&caracter=='o'&&caracter=='c'&&caracter=='e'&&caracter=='d'&&caracter=='e'){
                    printf("Se ha solicitado: avanza->retrocede");
                    Estado=e9;}
                if(caracter=='d'&&caracter=='e'&&caracter=='t'&&caracter!='e'&&caracter=='n'&&caracter=='e'&&caracter=='r'&&caracter=='s'&&caracter=='e'){
                    printf("Se ha solicitado: avanza->detenerse");
                    Estado=e9;}
                break;
            case e10:
                if(caracter=='1'){
                    printf("Se ha solicitado: siRetrocede");
                    Estado=e10;}
                if(caracter=='0'){
                    printf("Se ha solicitado: noRetrocede");
                    Estado=e10;}
                break;
            case e11:
                if(caracter=='s'){
                    printf("Se ha solicitado: siAvanza");
                    Estado=e11;}
                if(caracter=='n'){
                    printf("Se ha solicitado: noAvanza");
                    Estado=e11;}
                break;
            case e12:
                if(caracter=='1'){
                    printf("Se ha solicitado: siRetrocede");
                    Estado=e12;}
                if(caracter=='0'){
                    printf("Se ha solicitado: noRetrocede");
                    Estado=e12;}
                break;
            case e13:
                if(caracter=='s'){
                    printf("Se ha solicitado: siDetenido");
                    Estado=e11;}
                if(caracter=='n'){
                    printf("Se ha solicitado: noDetenido");
                    Estado=e11;}
                break;
            case e14:
                if(caracter=='s'&&caracter=='u'&&caracter=='j'&&caracter!='e'&&caracter=='t'&&caracter=='a'&&caracter=='r'){
                    printf("Se ha solicitado: brazos->sujetar");
                    Estado=e14;}
                if(caracter=='e'&&caracter=='m'&&caracter=='p'&&caracter!='u'&&caracter=='j'&&caracter=='a'&&caracter=='r'){
                    printf("Se ha solicitado: brazos->empujar");
                    Estado=e14;}
                if(caracter=='1'){
                    printf("Se ha solicitado: siSujeta");
                    Estado=e14;}
                if(caracter=='0'){
                    printf("Se ha solicitado: noSujeta");
                    Estado=e14;}
                if(caracter=='s'){
                    printf("Se ha solicitado: siEmpuja");
                    Estado=e14;}
                if(caracter=='n'){
                    printf("Se ha solicitado: noEmpuja");
                    Estado=e14;}

                break;
            case e15:
                if(caracter=='1'){
                    printf("Se ha solicitado: siCapturar");
                    Estado=e15;}
                break;
            case e16:
                if(caracter=='e'){
                    printf("Se ha solicitado: extensionPedestal");
                    Estado=e16;}
                if(caracter=='g'){
                    printf("Se ha solicitado: anguloGiro");
                    Estado=e16;}
                if(caracter=='i'){
                    printf("Se ha solicitado: anguloInclinacion");
                    Estado=e16;}
                break;
            case e17:
                if(caracter=='l'&&caracter=='a'&&caracter=='d'&&caracter=='o'){
                    printf("Se ha solicitado: desplazamiento->lado");
                    Estado=e17;}
                if(caracter=='d'&&caracter=='i'&&caracter=='r'&&caracter=='e'&&caracter=='c'&&caracter=='c'&&caracter=='i'&&caracter=='o'&&caracter=='n'){
                    printf("Se ha solicitado: desplazamiento->direccion");
                    Estado=e17;}
                break;
            case e18:
                if(caracter=='d'){
                    printf("Se ha solicitado: pasoDerecha");
                    Estado=e18;}
                if(caracter=='i'){
                    printf("Se ha solicitado: pasoIzquierda");
                    Estado=e18;}
                if(caracter=='a'){
                    printf("Se ha solicitado: pasoAdelante");
                    Estado=e18;}
                if(caracter=='b'){
                    printf("Se ha solicitado: pasoAtras");
                    Estado=e18;}
                break;
        }
    printf("\nTamanio: %c",tamanioCaracteres);
    //cierre del archivo de texto plano del cual se leen los caracteres
    fclose(archivo);
}
