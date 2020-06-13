#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

/**
 * @brief Devuelve un empleado, pide el id del mismo.
 *
 * @param pArrayListEmployee LinkedList* de empleados.
 * @param ll_len largo de la linked list
 * @param id id del empleado a buscar
 * @return int -1 -> ERROR | empleado
 */
Employee* getEmpbyId(LinkedList* pArrayListEmployee,int ll_len,int id);

/**
 * @brief devuelve el indice donde colocar un nuevo empleado (intercalado o al final)
 *
 * @param pArrayListEmployee LinkedList* de empleados.
 * @return int indice | -1 -> error
 */
int createId(LinkedList* pArrayListEmployee);


Employee* employee_new();


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);


Employee* employee_newParametrosValidados(int idStr,char* nombreStr,int horasTrabajadasStr,float sueldo);


void employee_delete();


int employee_setId(Employee* this,int id);


int employee_getId(LinkedList * pArrayListEmployee,int* id);


int employee_setNombre(Employee* this,char* nombre);


int employee_getNombre(char* nombre, char* text);


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


int employee_getHorasTrabajadas(float* horasTrabajadas, char* text);


int employee_setSueldo(Employee* this,int sueldo);


int employee_getSueldo(int* sueldo, char* text);

#endif // employee_H_INCLUDED
