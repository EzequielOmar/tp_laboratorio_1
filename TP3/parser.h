
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* puntero a archivo a leer, abierto.
 * \param pArrayListEmployee LinkedList* puntero a linked list
 * \return int 0 -> OK | -1 -> ERROR 
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param pFile FILE* puntero a archivo a leer, abierto.
 * \param pArrayListEmployee LinkedList* puntero a linked list
 * \return int 0 -> OK | -1 -> ERROR 
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
