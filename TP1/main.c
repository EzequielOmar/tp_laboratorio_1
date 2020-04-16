#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/****************************************************
 * DATOS ALUMNO :                     
 *   Vazquez, Ezequiel Omar                           
 *   DNI : 39000522                            
 *   Legajo : 919224                        
 *   Div : 1B    Ciclo : 2020                         
*****************************************************/

int main(void) {
    int ret=0;
    int res;
    float A=0 , B=0;
    float sum, subtraction, division, multiplication;
    unsigned long factA, factB;
    do{ 
        showMenu(A,B,&res);
        system("clear");
        switch (res)
        {
            case 1:
                getFloat(&A,"Ingrese el 1er operando (A=x)\n","Error, valor inválido.\n");
                system("clear");
                break;
            case 2:
                getFloat(&B,"Ingrese el 2do operando (B=x)\n","Error, valor inválido.\n");
                system("clear");
                break;
            case 3:
                operate(A,B,&sum,&subtraction,&division,&multiplication,&factA,&factB);
                break;
            case 4:
                showResults(A,B,sum,subtraction,division,multiplication,factA,factB);
                puts("Apretá ENTER para desplegar menú:");
                sysPause();
            case 5:
                break;
            default:
                puts("Error, no hay ninguna opción con ese numero.");
                puts("Apretá ENTER para continuar:");
                sysPause();
                break;
        }
    }while(res != 5);

    ret=1;
    return ret;
}
