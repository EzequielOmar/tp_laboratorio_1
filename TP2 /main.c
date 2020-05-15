#include <stdio.h>
#include <stdlib.h>
#define MAX_DB 1000
#define EMPTY 1
#define NOT_EMPTY 0
#include "ArrayEmployees.h"
#include "functions.h"
/****************************************************
 * DATOS ALUMNO :
 *   Vazquez, Ezequiel Omar
 *   DNI : 39000522
 *   Legajo : 919224
 *   Div : 1B    Ciclo : 2020
*****************************************************/
int main(void){
    int ret = 0, resp, aux;
    Employee Emp[MAX_DB];
    initEmployees(Emp,MAX_DB,EMPTY);
    do{
        showMenu(&resp);
        switch (resp){
            case 1:
                aux = addEmployee(Emp,MAX_DB,EMPTY,NOT_EMPTY);
                printErrorCases(aux,"¡Los datos han sido cargados con éxito!",
                "La operación ha sido cancelada. Reintente la carga de datos.",
                "Lo siento. No hay espacio suficiente en la base de datos.");
                sysPauseMsg();
                break;
            case 2:
                if(findEmpty(Emp,MAX_DB,NOT_EMPTY) != -1){
                    aux = modifyEmployee(Emp,MAX_DB,NOT_EMPTY, EMPTY);
                    printErrorCases(aux,"Los datos han sido modificados con éxito.",
                    "La operación ha sido cancelada.",
                    "No se encontraron coincidencias con el ID ingresado.");
                    sysPauseMsg();
                }else{
                    puts("Error, no hay datos guardados en la base de datos.");
                    sysPauseMsg();
                }
                break;
            case 3:
                if(findEmpty(Emp,MAX_DB,NOT_EMPTY) != -1){
                    aux = removeEmployee(Emp,MAX_DB,EMPTY,NOT_EMPTY);
                    printErrorCases(aux,"Los datos han sido eliminados con éxito.",
                    "La operacion ha sido cancelada.",
                    "No se encontraron coincidencias con el ID ingresado.");
                    sysPauseMsg();
                }else{
                    puts("Error, no hay datos guardados en la base de datos.");
                    sysPauseMsg();
                }
                break;
            case 4:
                if(findEmpty(Emp,MAX_DB,NOT_EMPTY) != -1){
                    sortEmployees(Emp,MAX_DB,1,NOT_EMPTY);
                    printEmployeesList(Emp,MAX_DB,NOT_EMPTY);
                    printInfoSalary(Emp,MAX_DB,NOT_EMPTY);
                    sysPauseMsg();
                }else{
                    puts("Error, no hay datos guardados en la base de datos.");
                    sysPauseMsg();
                }
                break;
            case 5:
                break;
            default:
                puts("Error, opción inválida.");
                sysPauseMsg();
                break;
        }
    }while(resp != 5);
    return ret;
}
