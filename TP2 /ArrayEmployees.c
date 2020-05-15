#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "getters.h"
#include "functions.h"

/*STATIC*FUNCTIONS*************************************************************************/

/**
 * @brief Print one employee data.
 */
static void printEmployee(Employee list){
    printf("%-5d%-20s%20s%10.2f %5d\n",list.id,
    list.name,list.lastName,list.salary,list.sector);
}

/**
* @brief 2 times loop - handle error and 2nd try to get STR data from user
* @return 0 -> "OK" | 1 -> "Caractér inválido" | 2 -> "Largo inapropiado"
*/
static int handleGetStr(char *pointer, char *text){
    int errorCase , i;
    for(i=0;i<2;i++){
        errorCase = getStr_Alpha(pointer,text,2,51);
        printErrorCases(errorCase,"OK","Error, ha ingresado un caractér inválido.",
        "Error, largo de palabra inapropiado.");
        if(errorCase == 0){break;}
    }
    return errorCase;
}

/**
 * @brief 2 times loop - handle error and 2nd try to FLOAT get data from user
 * @return 0 -> "OK" | 1 -> "Cantidad inválida" | 2 -> "Caractér inválido"
 */
static int handleGetFloat(float *pointer, char *text){
    int errorCase , i;
    for(i=0;i<2;i++){
        errorCase = getFloat(pointer, text,0,9999999);
        printErrorCases(errorCase,"OK","Error, cantidad inválida.",
        "Error, ha ingresado un caractér inválido.");
        if(errorCase == 0){break;}
    }
    return errorCase;
}

/**
* @brief 2 times loop - handle error and 2nd try to get INT data from user
* @return 0 -> "OK" | 1 -> "Cantidad inválida" | 2 -> "Caractér inválido"
*/
static int handleGetInt(int *pointer, char *text){
    int errorCase , i;
    for(i=0;i<2;i++){
        errorCase = getInt(pointer,text,1,3);
        printErrorCases(errorCase,"OK","Error, cantidad inválida.",
        "Error, ha ingresado un caractér inválido.");
        if(errorCase == 0){break;}
    }
    return errorCase;
}

/**
 * @brief Get all Data for a new Employee
 * @return struct Employee aux whith new employee data | aux.idEmpty = empty if error
 */
static Employee getEmployeeData(int indice,int notEmpty, int empty){
    Employee aux;
    if(handleGetStr(aux.name,"Ingrese el nombre completo del nuevo empleado:") == 0
    && handleGetStr(aux.lastName,"Ingrese el/o los apellidos del nuevo empleado:") == 0
    && handleGetFloat(&aux.salary,"Ingrese el salario bruto mensual en pesos.") == 0
    && handleGetInt(&aux.sector,"Ingrese el sector de destino del nuevo empleado (1,2 ó 3).") == 0){
        system("clear");
        printf("¡Bienvenido %s, %s!\n",aux.lastName,aux.name);
        aux.id = indice+1;
        aux.isEmpty = notEmpty;
    }else{
        system("clear");
        aux.isEmpty = empty;
    }
    return aux;
}

/**
 * @brief Get the index of the employee that is equal to the id entered.
 * @return Index of employee | -1 if error (id does not exist).
 */
static int findEmployeeById(Employee list[], int length,int id){
    int indice = -1,i;
    for(i=0;i<length;i++){
        if(list[i].id == id){
            indice = i;
            break;
        }
    }
    return indice;
}

/**
 * @brief Ask the user to confirm the REMOVAL operation.
 * @return 0 -> Employee data deleted | -1 -> Operation canceled by user
 */
static int confirmRemoval(Employee list[],int empty, int indice){
    int r;
    char conf;
    puts("Se han encontrado los datos de:");
    printEmployee(list[indice]);
    printf("¡Importante!\n\nLos datos no podrán recuperarse.\n"
            "¿Desea eliminar los datos permanentemente?\nConfirmar (s/n).");
    __fpurge(stdin);
    scanf("%c",&conf);
    if(conf == 's'|| conf == 'S'){
        list[indice].isEmpty = empty;
        r = 0;
    }else{r = -1;}
    return r;
}

/**
 * @brief Ask the user to confirm the MODIFICATION operation.
 * @return 0 -> Employee data updated | -1 -> Operation canceled by user
 */
static int confirmModification(Employee list[],Employee aux , int indice){
    int r;
    char conf;
    printf("¡Atención!\n\nAl sobreescribir se perderán los datos previos.\n"
    "¿Desea eliminar los datos permanentemente?\nConfirmar (s/n).\n");
    __fpurge(stdin);
    scanf("%c",&conf);
    if(conf == 's' || conf == 'S'){
        list[indice] = aux;
        r = 0;
    }else{r = -1;}
    return r;
}

/**
 * @brief Handle the modification menu.
 * @return 0 -> if data has been modified | -1 -> if user canceled operation
 */
static int modificationMenu(Employee list[],int indice, int empty){
    Employee aux;
    aux = list[indice];
    int r,selection;
    puts("Se han encontrado los datos de:");
    printEmployee(list[indice]);
    do{
        showModificationMenu(&selection);
        switch(selection){
            case 1:
                if(handleGetStr(aux.name,"Ingrese el nuevo nombre.") == 0){
                    break;}else{return r = -1;}
            case 2:
                if(handleGetStr(aux.lastName,"Ingrese el nuevo apellido.") == 0){
                    break;}else{return r = -1;}
            case 3:
                if(handleGetFloat(&aux.salary,"Ingrese el nuevo salario.") == 0){
                    break;}else{return r = -1;}
            case 4:
                if(handleGetInt(&aux.sector,"Ingrese el nuevo sector.") == 0){
                    break;}else{return r = -1;}
            case 0:
                if(confirmModification(list,aux,indice) == 0){
                    r = 0;
                }else{r = -1;}
                break;
            default:
                puts("Incorrecto, opción inválida.");
                break;
        }
    }while(selection != 0);
    return r;
}

/***************************************************************************************/
int initEmployees(Employee list[], int length, int empty){
    int r,i;
    for(i=0;i<length;i++){
        list[i].isEmpty = empty;
    }
    if(i == length){
        r = 0;
    }else{r = -1;}
    return r;
}

int printEmployeesList(Employee list[], int length, int notEmpty){
    int r,i;
    printf("%-5s%-20s%20s   %-10s%5s\n","ID","Nombre/s","Apellido/s","Sueldo($)","Sector");
    for(i=0;i<length;i++){
        if(list[i].isEmpty == notEmpty){
            printEmployee(list[i]);
        }
    }
    if(i == length){
        r = 0;
    }else{r = -1;}
    return r;
}

int findEmpty(Employee list[],int length, int empty){
    int i, indice = -1;
    for(i=0;i<length;i++){
        if(list[i].isEmpty == empty){
            indice = i;
            break;
        }
    }
    return indice;
}

int addEmployee(Employee list[], int length, int empty, int notEmpty){
    int r, indice;
    indice = findEmpty(list,length,empty);
    if(indice != -1){
        list[indice] = getEmployeeData(indice,notEmpty, empty);
        if(list[indice].isEmpty == notEmpty){
            r = 0;
        }else{r = -1;}
    }else{r = -2;}
    return r;
}

int removeEmployee(Employee list[], int length, int empty, int notEmpty){
    int r,id,indice;
    printEmployeesList(list, length, notEmpty);
    puts("A continuación, escriba el id del empleado a eliminar:");
    scanf("%d",&id);
    system("clear");
    indice = findEmployeeById(list,length,id);
    if(indice != -1){
        if(confirmRemoval(list, empty, indice) == 0){
            r = 0;
        }else{r = -1;}
    }else{r = -2;}
    return r;
}

int modifyEmployee(Employee list[],int length, int notEmpty, int empty){
    int r, id, indice;
    printEmployeesList(list, length, notEmpty);
    puts("A continuación, escriba el id del empleado a modificar");
    scanf("%d",&id);
    system("clear");
    indice = findEmployeeById(list,length,id);
    if(indice != -1){
        if(modificationMenu(list,indice, empty) == 0){
            r = 0;
        }else{r = -1;}
    }else{r = -2;}
    return r;
}

int sortEmployees(Employee list[], int length, int order, int notEmpty){
    int r,i,j,cmp;
    Employee aux;
    for(i=0;i<length-1;i++){
        for(j=i+1;j<length;j++){
            if(list[i].isEmpty == notEmpty && list[j].isEmpty == notEmpty && order == 1){
                cmp = strcmp(list[i].lastName,list[j].lastName);
                if(list[i].sector > list[j].sector ||
                (list[i].sector==list[j].sector && cmp > 0)){
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
            if(list[i].isEmpty == notEmpty && list[j].isEmpty == notEmpty && order == 0){
                cmp = strcmp(list[i].lastName,list[j].lastName);
                if(list[i].sector < list[j].sector ||
                (list[i].sector==list[j].sector && cmp < 0)){
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }
    }
    if(i+1 == length){
        r = 0;
    }else{r = 1;}
    return r;
}

int printInfoSalary(Employee list[], int length, int notEmpty){
    int r,i, count = 0, betterWages = 0;
    float salarySum = 0, salaryAvg;
    for(i=0;i<length;i++){
        if(list[i].isEmpty == notEmpty){
            salarySum = salarySum + list[i].salary;
            count++;
        }
    }
    if(i == length){
        salaryAvg = salarySum/count;
        for(i=0;i<length;i++){
            if(list[i].salary > salaryAvg){
                betterWages++;
            }
        }
        showInfoSalary(count,salarySum,salaryAvg,betterWages);
        r = 0;
    }else{r = 1;}
    return r;
}
