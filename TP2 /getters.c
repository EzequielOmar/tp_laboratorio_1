#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "getters.h"

/**
 * @brief Put first letter to uppercase, the rest to lowercase.
 * @return -1 -> Error |  0 -> OK
 */
static int strToName(char *str, int strlengt){
    int i,r;
    for(i=0 ; i<strlengt ; i++){
        if((i == 0 && str[i] != 32) || str[i-1] == 32){
            str[i] = toupper(str[i]);
        }else{
            if(str[i] != 32){
                str[i] = tolower(str[i]);
            }
        }
    }
    if(str[i] == '\0'){
        r = 0;
    }else{r = -1;}
    return r;
}

/**
 * @brief Validate that all characters are Alphabetical ones.
 * @return -1 -> Error |  0 -> OK
 */
static int validateStr_Alpha(char* pResultado){
    int ret;
    int i=0;
    while(pResultado[i] != '\0'){
        if(pResultado[i] < 32 || (pResultado[i] > 32 && pResultado[i] < 65) || (pResultado[i] > 90 &&
           pResultado[i] < 97) || pResultado[i] > 122){
            break;
        }
        i++;
    }
    if(pResultado[i] == '\0'){
        ret = 0;
    }else{ret = -1;}
    return ret;
}

int getStr_Alpha(char* pResultado, char* mensaje,
                        int minimo, int maximo){
    int ret = -1;
    char res[100];
    while(ret == -1){
        puts(mensaje);
        __fpurge(stdin);
        fgets(res,sizeof(res),stdin);
        res[strlen(res)-1]='\0';
        if(strlen(res) <= maximo && strlen(res) >= minimo){
            if(validateStr_Alpha(res) == 0 && strToName(res,strlen(res)) == 0){
                strcpy(pResultado, res);
                ret = 0;
                break;
            }else{
                ret = -1;
                break;
            }
        }else{
            ret = -2;
        }
    }
    return ret;
}

/**
 * @brief Validate that all characters are number, with max one "." and one "-".
 * @return -1 -> Error |  0 -> OK
 */
static int validateFloat(char* cadena){
    int ret=-1;
    int i=0;
    int coma=0;
    int signo=0;
    if(cadena!=NULL){
        if(cadena[0] == 45){
            signo++;
            i++;
        }
        while(cadena[i]!='\0'){
            if(cadena[i] == 46 || cadena[i] == 44 || (cadena[i]>47 && cadena[i]<58)){
                if(cadena[i] == 46|| cadena[i] == 44){
                    coma++;
                }
                i++;
            }else{break;}
        }
        if(cadena[i]=='\0' && coma < 2 && signo < 2){
            if((coma == 1 && strlen(cadena) > 1 )|| (signo == 1 && strlen(cadena) > 1)){
                ret=0;
            }
            if(coma == 0 && signo == 0){
                ret=0;
            }
        }
    }
    return ret;
}

/**
 * @brief Cast string to float after validate
 * @return  0 -> OK | -1 -> Error
 */
static int charFloat(float* pResultado){
    int ret=-1;
    char buffer[30];
    __fpurge(stdin);
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';
    if(validateFloat(buffer) == 0){
        *pResultado = atof(buffer);
        ret = 0;
    }
    return ret;
}

int getFloat(float* pResultado, char* mensaje,
             float minimo, float maximo){
    int ret = 1;
    float num;
    while(ret == 1){
        puts(mensaje);
        if(charFloat(&num) == 0){
            if(num<=maximo && num>=minimo){
                *pResultado = num;
                ret = 0;
                break;
            }else{
                ret = -1;
            }
        }else{
            ret = -2;
        }
    }
    return ret;
}

/**
 * @brief Validate that all characters are number, with max one "-".
 * @return -1 -> Error |  0 -> OK
 */
static int validateInt(char* cadena){
    int ret=-1;
    int i=0;
    int signo=0;
    if(cadena!=NULL){
        if(cadena[0] == 45){
            signo++;
            i++;
        }
        while(cadena[i]!='\0'){
            if(cadena[i]>47 && cadena[i]<58){
                i++;
            }else{break;}
        }
        if(cadena[i]=='\0' && signo < 2){
            ret=0;
        }
    }
    return ret;
}

/**
 * @brief Cast string to int after validate
 * @return  0 -> OK | -1 -> Error
 */
static int charInt(int* pResultado){
    int ret=-1;
    char buffer[30];
    __fpurge(stdin);
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';
    if(validateInt(buffer) == 0){
        *pResultado = atoi(buffer);
        ret=0;
    }
    return ret;
}

int getInt(int* pResultado,char* mensaje,
           int minimo,int maximo){
    int ret = 1;
    int num;
    while(ret == 1){
        puts(mensaje);
        if(charInt(&num)==0){
            if(num<=maximo && num>=minimo){
                *pResultado = num;
                ret = 0;
                break;
            }else{
                ret = -1;
            }
        }else{
            ret = -2;
        }
    }
    return ret;
}
