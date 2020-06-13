#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

void showMenu(int *resp){
    printf("¡Bienvenido! Seleccione una opción:\n"
               "\t1. CARGAR: Cargar base de datos desde  archivo 'data.csv' (modo texto).\n"
               "\t2. CARGAR: Cargar base de datos desde  archivo 'data.csv' (modo binario)\n"
               "\t3. ALTA: Alta de empleado.\n"
               "\t4. MODIFICAR: Modificar datos de un empleado.\n"
               "\t5. BAJA : Dar de baja un empleado.\n"
               "\t6. LISTAR: Mostrar lista de empleados.\n"
               "\t7. ORDENAR: Ordenar empleados alfabéticamente.\n"
               "\t8. GUARDAR: Guardar datos de los empleados en el archivo data.csv (modo texto).\n"
               "\t9. GUARDAR: Guardar datos de los empleados en el archivo data.bin (modo binario).\n"
               "\t10. SALIR.\n"
    );
    scanf("%d",resp);
    system("clear");
}

void showModifMenu(int *resp){
    printf("Seleccione:\n\t1.Modificar nombre.\n\t"
            "2.Modificar horas trabajadas.\n\t"
            "3.Modificar sueldo.\n\t"
            "0.Salir.\n"
    );
    scanf("%d",resp);
    system("clear");
}

void sysPause(){
    __fpurge(stdin);
    getchar();
    system("clear");
}

void sysPauseMsg(){
    puts("Apretá ENTER");
    __fpurge(stdin);
    getchar();
    system("clear");
}

void printErrorCases(int res,char *m1, char *m2, char *m3, char *m4){
    switch (res){
    case 0:
        puts(m1);
        break;
    case -1:
        puts(m2);
        break;
    case -2:
        puts(m3);
        break;
    case -3:
        puts(m4);
        break;
    default:
        break;
    }
}

int isInt(char* cadena){
    int ret=-1;
    int i=0;
    if(cadena!=NULL){
        while(cadena[i]!='\0'){
            if(cadena[i]>47 && cadena[i]<58){
                i++;
            }else{break;}
        }
        if(cadena[i]=='\0'){
            ret=0;
        }
    }
    return ret;
}
