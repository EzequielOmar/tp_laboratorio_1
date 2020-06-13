#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "functions.h"
#include "Controller.h"

static void printEmployee(Employee * emp){
    printf("%d--%s--%d--%.2f\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
}

static void askForEmp(LinkedList* pArrayListEmployee, int *id){
    controller_ListEmployee(pArrayListEmployee);
    puts("A continuación, escriba el id del empleado a modificar:");
    scanf("%d",id);
    system("clear");
}

static void showTextandAskChar(char * text, char * conf){
    puts(text);
    __fpurge(stdin);
    scanf("%c",conf);
}

static int orderByName(void * auxI, void * auxJ){
    Employee *empI ,*empJ;
    int compare;
    empI = employee_new();
    empJ = employee_new();
    empI = (Employee *) auxI;
    empJ = (Employee *) auxJ;
    compare = strcmp(empI->nombre,empJ->nombre);
    if(compare < 0){
        compare = -1;
    }else{
        if(compare > 0){
            compare = 1;
        }
    }
    return compare;
}

static int handleModifMenu(LinkedList * pArrayEmployee,Employee * emp){
    int select,r;
    char auxname[128], conf;
    float auxHs;
    int auxSal;
    strcpy(auxname,emp->nombre);
    auxHs = emp->horasTrabajadas;
    auxSal = emp->sueldo;
    do{
        showModifMenu(&select);
        switch (select){
            case 1:
                if(employee_getNombre(auxname,"Ingrese el nuevo nombre.") != 0){
                    r = -1;
                    select = 5;
                }
                break;
            case 2:
                if(employee_getHorasTrabajadas(&auxHs,"Ingrese el nuevo valor de horas trabajadas.") != 0){
                    r = -1;
                    select = 5;
                }
                break;
            case 3:
                if(employee_getSueldo(&auxSal,"Ingrese el nuevo sueldo.") != 0){
                    r = -1;
                    select = 5;
                }
                break;
            case 0:
                if(strcmp(emp->nombre,auxname) == 0 && emp->horasTrabajadas == auxHs && emp->sueldo == auxSal){
                    r = -1;
                }else{
                    showTextandAskChar("¿Quiere sobreescribir los datos?(s/n)\nLos datos anteriores no podran recuperarse.\nPresione 'n' para cancelar operación.",&conf);
                    if(conf == 's' || conf == 'S'){
                        employee_setNombre(emp,auxname);
                        employee_setHorasTrabajadas(emp,auxHs);
                        employee_setSueldo(emp,auxSal);
                        r = 0;
                    }else{r = -1;};
                }
                select = 5;
                break;
            default:
                puts("Opción inválida.");
                sysPause();
                break;
        }
    } while (select != 5);
    return r;
}

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee){
    int r,len;
    FILE * pFile;
    pFile = fopen(path,"r");
    len = ll_len(pArrayListEmployee);
    if(pFile == NULL){
        r = -1;
    }else{
        if(len == 0){
            if(parser_EmployeeFromText(pFile,pArrayListEmployee) == 0){
                r = 0;
            }else{r = -2;}
        }else{r = -3;}
    }
    return r;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){
    int r,len;
    FILE * pFile;
    pFile = fopen(path,"rb");
    len = ll_len(pArrayListEmployee);
    if(pFile == NULL){
        r = -1;
    }else{
        if(len == 0){
            if(parser_EmployeeFromBinary(pFile,pArrayListEmployee) == 0){
                r = 0;
            }else{r = -2;}
        }else{r = -3;}
    }
    return r;
}

int controller_addEmployee(LinkedList* pArrayListEmployee){
    int r,idaux,sueldoaux,len;
    float horasaux;
    char nameaux[128];
    Employee *emp;
    len = ll_len(pArrayListEmployee);
    if(len != -1){
        if(employee_getId(pArrayListEmployee,&idaux) == 0 &&
        employee_getNombre(nameaux,"Ingrese el nombre completo del nuevo empleado:") == 0 &&
        employee_getHorasTrabajadas(&horasaux,"Ingrese las horas trabajadas del empleado:") == 0 &&
        employee_getSueldo(&sueldoaux,"Ingrese el salario bruto mensual en pesos.") == 0){
            emp = employee_newParametrosValidados(idaux,nameaux,horasaux,sueldoaux);
            ll_add(pArrayListEmployee,emp);
            r = 0;
        }else{r = -1;}
    }else{r = -2;}
    return r;
}

int controller_editEmployee(LinkedList* pArrayListEmployee){
    int r,len,id;
    Employee *aux;
    len = ll_len(pArrayListEmployee);
    if(len > 0){
        askForEmp(pArrayListEmployee,&id);
        aux = getEmpbyId(pArrayListEmployee,len,id);
        if(aux != NULL){
            puts("Se han encontrado los datos de:");
            printEmployee(aux);
            if(handleModifMenu(pArrayListEmployee,aux) == 0){
                r = 0;
            }else{r = -1;}
        }else{r = -2;}
    }else{r = -3;}
    return r;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee){
    int len,i,r;
    Employee *aux;
    len = ll_len(pArrayListEmployee);
    if(len < 1){
        r = -1;
    }else{
        for(i=0;i<len;i++){
            aux = (Employee *) ll_get(pArrayListEmployee,i);
            printEmployee(aux);
        }
        r = 0;
    }
    return r;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee){
    int r,len,id;
    char conf;
    Employee *aux;
    len = ll_len(pArrayListEmployee);
    if(len > 0){
        controller_ListEmployee(pArrayListEmployee);
        puts("A continuación, escriba el id del empleado a eliminar:");
        scanf("%d",&id);
        system("clear");
        aux = getEmpbyId(pArrayListEmployee,len,id);
        if(aux != NULL){
            puts("Se han encontrado los datos de:");
            printEmployee(aux);
            showTextandAskChar("¡Importante!\n\nLos datos no podrán recuperarse.\n¿Desea eliminar los datos permanentemente?\nConfirmar (s/n).",&conf);
            if(conf == 's'|| conf == 'S'){
                ll_remove(pArrayListEmployee,ll_indexOf(pArrayListEmployee,aux));
                employee_delete(aux);
                r = 0;
            }else{r = -1;}
        }else{r = -2;}
    }else{r = -3;}
    return r;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee){
    int r, order = 1;
    if(pArrayListEmployee != NULL){
        puts("Ordenando...");
        if(ll_sort(pArrayListEmployee,orderByName,order) == 0){
            r = 0;
        }else{r = -1;}
    }else{r = -1;}
    return r;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){
    int r,len,i;
    FILE * pFile;
    Employee *aux;
    pFile = fopen(path,"w");
    len = ll_len(pArrayListEmployee);
    if(pFile != NULL){
        if(len > 0){
            fprintf(pFile,"%s,%s,%s,%s\n","ID","Nombre","Horas","Sueldo");
            for(i=0;i<len;i++){
                aux = (Employee *)ll_get(pArrayListEmployee,i);
                fprintf(pFile,"%d,%s,%d,%.2f\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
            }
            ll_clear(pArrayListEmployee);
            r = 0;
        }else{r = -2;}
    }else{r = -1;}
    fclose(pFile);
    return r;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee){
    int r,len,i;
    FILE * pFile;
    Employee *aux;
    pFile = fopen(path,"wb");
    len = ll_len(pArrayListEmployee);
    if(pFile != NULL){
        if(len > 0){
            for(i=0;i<len;i++){
                aux = (Employee *)ll_get(pArrayListEmployee,i);
                fwrite(aux,sizeof(Employee),1,pFile);
            }
            ll_clear(pArrayListEmployee);
            r = 0;
        }else{r = -2;}
    }else{r = -1;}
    fclose(pFile);
    return r;
}
