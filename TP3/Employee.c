#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "getters.h"
#include "functions.h"

/**
* @brief 2 times loop - handle error and 2nd try to get STR data from user
* @return 0 -> "OK" | 1 -> "Caractér inválido" | 2 -> "Largo inapropiado"
*/
static int handleGetStr(char *pointer, char *text){
    int errorCase , i;
    for(i=0;i<2;i++){
        errorCase = getStr_Alpha(pointer,text,2,128);
        printErrorCases(errorCase,"OK","Error, ha ingresado un caractér inválido.",
        "Error, largo de palabra inapropiado.","");
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
        errorCase = getInt(pointer,text,0,999999);
        printErrorCases(errorCase,"OK","Error, cantidad inválida.",
        "Error, ha ingresado un caractér inválido.","");
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
        "Error, ha ingresado un caractér inválido.","");
        if(errorCase == 0){break;}
    }
    return errorCase;
}

Employee * getEmpbyId(LinkedList* pArrayListEmployee,int ll_len,int id){
    int i;
    Employee *aux;
    for (i=0;i<ll_len;i++){
        aux = ll_get(pArrayListEmployee,i);
        if(aux->id == id){
            break;
        }
    }
    if(i == ll_len){
        aux = NULL;
    }
    return aux;
}

int createId(LinkedList* pArrayListEmployee){
    int i = 0,len,id = 0;
    Employee *aux;
    len = ll_len(pArrayListEmployee);
    for(i;i<len;i++){
        aux = ll_get(pArrayListEmployee,i);
        if(aux->id > id){
            id = aux->id+1;
        }
    }
    return id;
}

Employee* employee_new(){
    Employee *emp;
    emp = (Employee*)malloc(sizeof(Employee));
    return emp;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo){
    Employee * emp;
    emp = employee_new();
    employee_setId(emp,atoi(idStr));
    employee_setNombre(emp,nombreStr);
    employee_setHorasTrabajadas(emp,atoi(horasTrabajadasStr));
    employee_setSueldo(emp,atof(sueldo));
    return emp;
}

Employee* employee_newParametrosValidados(int idStr,char* nombreStr,int horasTrabajadasStr,float sueldo){
    Employee * emp;
    emp = employee_new();
    employee_setId(emp,idStr);
    employee_setNombre(emp,nombreStr);
    employee_setHorasTrabajadas(emp,horasTrabajadasStr);
    employee_setSueldo(emp,sueldo);
    return emp;
}

void employee_delete(Employee * pEmp){
    pEmp = NULL;
    free(pEmp);
}

int employee_setId(Employee* this,int id){
    int r = -1;
    if(this != NULL && id != -1){
        this->id = id;
        r = 0;
    }
    return r;
}

int employee_getId(LinkedList * pArrayListEmployee,int* id){
    int r = -1,idaux;
    idaux = createId(pArrayListEmployee);
    if(idaux != -1){
        *id = idaux;
        r = 0;
    }
    return r;
}

int employee_setNombre(Employee* this,char* nombre){
    int r = -1;
    if(this != NULL){
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        r = 0;
    }
    return r;
}


int employee_getNombre(char* nombre, char* text){
    int r = -1;
    if(handleGetStr(nombre,text) == 0){
        r = 0;
    }
    return r;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int r = -1;
    if(this != NULL){
        this->horasTrabajadas = horasTrabajadas;
        r = 0;
    }
    return r;
}

int employee_getHorasTrabajadas(float* horasTrabajadas, char* text){
    int r = -1;
    if(handleGetFloat(horasTrabajadas,text) == 0){
        r = 0;
    }
    return r;
}

int employee_setSueldo(Employee* this,int sueldo){
    int r = -1;
    if(this != NULL){
        this->sueldo = sueldo;
        r = 0;
    }
    return r;
}

int employee_getSueldo(int* sueldo, char* text){
    int r = -1;
    if(handleGetInt(sueldo,text) == 0){
        r = 0;
    }
    return r;
}
