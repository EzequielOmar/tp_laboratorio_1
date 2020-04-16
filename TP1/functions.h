#include "functions.c"

/**
 * @brief - Show menu, and charge variable with user selection.
 * 
 * @param A - float A variable, to show entered number by user.
 * @param B - float B variable, to show entered number by user.
 * @param r - int variable of user option seleccion on menu.
 */
void showMenu(float A, float B, int *r);

/**
 * @brief - Get Float, validate it, and charge it in pointer.
 * 
 * @param pResultado - pointer to float variable to charge user entered number.
 * @param mensaje - message to show, when ask for a number.
 * @param mensajeError - message of error.
 * @return - int 1 when number successfully charged.
 */
int getFloat(float* pResultado,char* mensaje,char* mensajeError);

/**
 * @brief - Get two floats, do all operations and save results on pointers.
 * 
 * @param A - float A variable to operate with.
 * @param B - float A variable to operate with.
 * @param sum - float pointer to save sum result.
 * @param sub - float pointer to save subtraction result.
 * @param div - float pointer to save division result.
 * @param mult - float pointer to save multiply result.
 * @param factA - unsigned long pointer to save fact A result.
 * @param factB - unsigned long pointer to save fact B result.
 */
void operate(float A, float B, float *sum, float *sub, float *div, 
float *mult, unsigned long *factA, unsigned long *factB);

/**
 * @brief  - Get all results variables and show it.
 * 
 * @param A - float A variable.
 * @param B - float B variable.
 * @param sum - float sum variable.
 * @param sub - float sub variable.
 * @param div - float div variable.
 * @param mult - float mult variable.
 * @param factA - unsigned long factA variable.
 * @param factB - unsigned long factB variable.
 */
void showResults(float A, float B, float sum, float sub, float div, 
float mult, unsigned long factA, unsigned long factB);

/**
 * @brief  - Ask a char to continue with the program execution.
 */
void sysPause(void);