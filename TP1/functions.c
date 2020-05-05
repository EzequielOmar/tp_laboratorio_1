#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "functions.h"

static float add(float x, float y) {
    float sum = x + y;
    return sum;
}

static float subtract(float x, float y) {
    float subtraction = x - y;
    return subtraction;
}

static float divide(float x, float y){
    float division = x / y;
    if(x == 0 || y == 0){
        return 0;
    }
    return division;
}

static float multiply(float x, float y) {
    float multiplication = x * y;
    return multiplication;
}

static unsigned long factorial(float x){
    int xint = (int)x;
    int factorial = 1;
    if(x<0){
        return 0;
    }else{
        if(xint == x){
            if(xint == 1 || xint == 0){
                return 1;
            }
            for(; xint>1; xint--){
                factorial = factorial * xint;
            }
            return factorial;
        }else{
            return 0;
        }
    }
}

void showMenu(float A, float B, int *r){
    if(A == B){
        printf("1. Ingresar 1er operando (A=x)\n"
               "2. Ingresar 2do operando (B=y)\n"
               "3. Calcular todas las operaciones:\n"
               "     a) Calcular la suma (A+B)\n"
               "     b) Calcular la resta (A-B)\n"
               "     c) Calcular la division (A/B)\n"
               "     d) Calcular la multiplicacion (A*B)\n"
               "     e) Calcular el factorial (A!) y (B!)\n"
               "4. Informar resultados.\n"
               "5. Salir.\n");
    }else{
        fprintf(stdout,"1. Ingresar 1er operando (A=%.2f)\n", A);
        fprintf(stdout,"2. Ingresar 2do operando (B=%.2f)\n", B);
        puts("3. Calcular todas las operaciones:");
        fprintf(stdout,"     a) Calcular la suma (%.2f+%.2f)\n", A,B);
        fprintf(stdout,"     b) Calcular la resta (%.2f-%.2f)\n", A,B);
        fprintf(stdout,"     c) Calcular la division (%.2f/%.2f)\n", A,B);
        fprintf(stdout,"     d) Calcular la multiplicacion (%.2f*%.2f)\n", A,B);
        fprintf(stdout,"     e) Calcular el factorial (%.2f!) y (%.2f!)\n", A,B);
        puts("4. Informar resultados.");
        puts("5. Salir.");
    }
    scanf("%d", &*r);
}

void operate(float A, float B, float *sum, float *sub, float *div,
float *mult, unsigned long *factA, unsigned long *factB){
    *sum = add(A , B);
    *sub = subtract(A , B);
    *div = divide(A , B);
    *mult = multiply(A , B);
    *factA = factorial(A);
    *factB = factorial(B);
}

void showResults(float A, float B, float sum, float sub, float div,
float mult, unsigned long factA, unsigned long factB){
    printf("La suma de %.2f + %.2f = %.3f \n",A,B,sum);
    printf("La resta de %.2f - %.2f = %.3f \n",A,B,sub);
    if(div == 0){
        puts("¡No se puede dividir un cero!");
    }else{
        printf("La división de %.2f / %.2f = %.3f \n",A,B,div);
    }
    printf("La multiplicación de %.2f * %.2f = %.3f \n",A,B,mult);
    if(A>-1 && A<13){
        printf("El factorial de %.0f es %lu \n",A,factA);
    }else{
        if(A>12 || factA == 0){
            printf("Solo se puede realizar el factorial de enteros positivos < 13.\n");
        }
    }
    if(B>-1 && B<13){
        printf("El factorial de %.0f es %lu \n",B,factB);
    }else{
        if(B>12 || factB == 0){
            printf("Solo se puede realizar el factorial de enteros positivos < 13.\n");
        }
    }
}

void sysPause(void){
    __fpurge(stdin);
    getchar();
    system("clear");
}

/*  getFloat()  */
static int validateFloat(char* cadena){
    int ret=0;
    int i=0;
    int coma=0;
    int signo=0;
    if(cadena!=NULL){
        if(cadena[0] == 45){
            signo++;
            i++;
        }
        while(cadena[i]!='\0'){
            if(cadena[i] == 46 || (cadena[i]>47 && cadena[i]<58)){
                if(cadena[i] == 46){
                    coma++;
                }
                i++;
            }else{break;}
        }
        if(cadena[i]=='\0' && signo < 2){
            if(coma == 1){
                ret=1;
            }
            if(coma == 0){
                ret=2;
            }
        }else{
            ret=0;
        }
    }
    return ret;
}

static int charFloat(float* pResultado){
    int ret=0;
    char buffer[30];
    __fpurge(stdin);
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';
    if(validateFloat(buffer) == 1){
        *pResultado = atof(buffer);
        ret=1;
    }
    if(validateFloat(buffer) == 2){
        *pResultado = atoi(buffer);
        ret=1;
    }
    return ret;
}

int getFloat(float* pResultado,
                  char* mensaje,
                  char* mensajeError){
    int ret = 0;
    float num;
    while(ret == 0){
        printf("%s", mensaje);
        if(charFloat(&num) == 1){
            break;
        }
        printf("%s", mensajeError);
    }
    ret = 1;
    *pResultado = num;
    return ret;
}
