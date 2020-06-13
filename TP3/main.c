#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "functions.h"
/****************************************************
 * DATOS ALUMNO :
 *   Vazquez, Ezequiel Omar
 *   DNI : 39000522
 *   Legajo : 919224
 *   Div : 1B    Ciclo : 2020
*****************************************************/
static char S1[40] = "Archivo leído correctamente.",
            S2[40] = "La operación se realizó con éxito",
            E1[40] = "Error, no hay datos guardados.",
            E2[70] = "Hubo un error mientras se leían los datos, carga incompleta.",
            E3[60] = "Error al abrir el archivo. La operación ha sido cancelada",
            E4[50] = "La lista ya ha sido cargada, guarde los datos.",
            E5[40] = "La operación ha sido cancelada.",
            E6[40] = "Error, id inválido.",
            E7[80] = "El archivo a sido guardado con éxito. Cargue nuevamente la base de datos.",
            E8[40] = "Error al abrir el archivo.";
int main(){
    char file_path_csv[15] = "data.csv";
    char file_path_bin[15] = "data.bin";
    LinkedList *ll_Employee = ll_newLinkedList();
    int resp,error;
    do{
        showMenu(&resp);
        switch (resp){
/*LoadCsv*/ case 1:
                error = controller_loadFromText(file_path_csv,ll_Employee);
                printErrorCases(error,S1,E2,E3,E4);
                sysPause();
                break;
/*LoadBin*/ case 2:
                error = controller_loadFromBinary(file_path_bin,ll_Employee);
                printErrorCases(error,S1,E2,E3,E4);
                sysPause();
                break;
/*ALTA*/    case 3:
                error  = controller_addEmployee(ll_Employee);
                printErrorCases(error,S2,E5,E6,"");
                sysPause();
                break;                
                break;
/*MODIF*/   case 4:
                if(ll_isEmpty(ll_Employee) == 0){
                    error  = controller_editEmployee(ll_Employee);
                    printErrorCases(error,S2,E5,E6,"");
                }else{puts(E1);}
                sysPause();
                break;
/*BAJA*/    case 5:
                if(ll_isEmpty(ll_Employee) == 0){
                    error  = controller_removeEmployee(ll_Employee);
                    printErrorCases(error,S2,E5,E6,"");
                }else{puts(E1);}
                sysPause();
                break;
/*LISTAR*/  case 6:
                if(controller_ListEmployee(ll_Employee) != 0){
                    puts(E1);
                }
                sysPause();
                break;
/*ORDENAR*/ case 7:
                if(controller_sortEmployee(ll_Employee) != 0){
                    puts(E1);
                }else{puts(S2);}
                sysPause();
                break;
/*Save_Csv*/case 8:
                error  = controller_saveAsText(file_path_csv,ll_Employee);
                printErrorCases(error,E7,E8,E1,"");
                sysPause(S2);
                break;
/*Save_Bin*/case 9:
                error  = controller_saveAsBinary(file_path_bin,ll_Employee);
                printErrorCases(error,E7,E8,E1,"");
                sysPause();
                break;
/*Salir*/   case 10:
                ll_deleteLinkedList(ll_Employee);
                break;
            default:
                puts("Error, opción inválida.");
                sysPauseMsg();
                break;

        }
    }while(resp != 10);
    return 0;
}    


