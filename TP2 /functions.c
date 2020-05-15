#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

void showMenu(int *resp){
    printf("¡Bienvenido! Seleccione una opción:\n"
               "\t1. ALTA: Dar de alta nuevo empleado.\n"
               "\t2. MODIFICAR: Modificar datos de un empleado existente.\n"
               "\t3. BAJA: Eliminar datos de un empleado existente.\n"
               "\t4. INFORMAR: Mostrar información de los empleados.\n"
               "\t5. SALIR.\n"
    );
    scanf("%d",resp);
    system("clear");
}

void showModificationMenu(int *resp){
    puts("¿Qué operacion desea realizar?\n"
        "\t1. Modificar nombre.\n""\t2. Modificar apellido.\n"
        "\t3. Modificar sueldo.\n""\t4. Modificar sector.\n"
        "\t0. Guardar y salir.\n");
    scanf("%d",resp);
    system("clear");
}

void showInfoSalary(int count,float salarySum,float salaryAvg,int betterWages){
    printf("Cantidad de empleados: %d.\n",count);
    printf("Monto total de salarios: $%.2f.\n",salarySum);
    printf("Salario promedio: $%.2f.\n",salaryAvg);
    printf("Cantidad de empleados que superan el salario promedio: %d.\n",betterWages);
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

void printErrorCases(int res,char *m1, char *m2, char *m3){
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
    default:
        break;
    }
}