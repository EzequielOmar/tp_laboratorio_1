#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "functions.h"
#include "getters.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
    int r;
    Employee * Emp;
    char var1[5],var2[128],var3[4],var4[6];
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
    do{
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r == 4 && validateInt(var1) == 0 && validateStr_Alpha(var2) == 0 && validateInt(var3) == 0 && validateFloat(var4) == 0 ){
            Emp = employee_newParametros(var1,var2,var3,var4);    
            ll_add(pArrayListEmployee,Emp);
        }else{
            r = -1;
            break;
        }
    }while(!feof(pFile));
    if(feof(pFile) == 1){
        r = 0;
    }
    fclose(pFile);
    return r;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){
    int r;
    Employee * Emp;
    do{
        Emp = employee_new();
        fread(Emp,sizeof(Employee),1,pFile);
        if(Emp->id || Emp->horasTrabajadas || Emp->sueldo){
            ll_add(pArrayListEmployee,Emp);
        }else{
            r = -1;
            break;
        }
    }while(!feof(pFile));
    if(feof(pFile) == 1){
        r = 0;
    }
    fclose(pFile);
    return r;
}
