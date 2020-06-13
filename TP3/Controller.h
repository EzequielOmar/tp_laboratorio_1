
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* path al archivo de datos .csv de los empleados
 * \param pArrayListEmployee LinkedList* de empleados.
 * \return int 0 -> OK 
 *            -1 -> ERROR al abrir el archivo 
 *            -2 -> ERROR al leer el archivo (carga hasta donde encuentre error)
 *            -3 -> Lista previamente cargada (cancela para no duplicar los datos)
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char* path al archivo de datos .csv de los empleados
 * \param pArrayListEmployee LinkedList* de empleados.
 * \return int 0 -> OK 
 *            -1 -> ERROR al abrir el archivo 
 *            -2 -> ERROR al leer el archivo (carga hasta donde encuentre error)
 *            -3 -> Lista previamente cargada (cancela para no duplicar los datos)
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/**
 * @brief Carga los datos de un empleado y lo agrega en el medio (si hay id discontinuo) o al final
 * 
 * \param pArrayListEmployee LinkedList* de empleados.
 * \return int 0 -> OK | -1 -> error en carga | -2 -> error al asignar id
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/**
 * @brief administra el menu de modificacion, y sobreescribe todos los datos (menos id)
 * 
 * \param pArrayListEmployee LinkedList* de empleados.
 * \return int 0 -> OK | -1 -> Error en carga o cancelado por usuario | -2 -> id inválido | -3 -> lista vacía
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/**
 * @brief Muestra la lista, pide un id, y elimina al empleado
 * 
 * @param pArrayListEmployee LinkedList* de empleados.
 * \return int 0 -> OK | -1 -> cancelado por usuario | -2 -> id inválido | -3 -> lista vacía
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/**
 * @brief Imprime la lista de empleados
 * 
 * @param pArrayEmployee Puntero a linked list de empleados
 * @return int 0 -> OK | -1 -> lista vacía o puntero nulo
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero a linked list de empleados
 * \return int 0 -> OK | -1 -> Error al ordenar o lista vacía
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* path al archivo de datos .csv de los empleados
 * \param pArrayListEmployee LinkedList* Puntero a linked list de empleados
 * \return int 0 -> OK | -1 -> Error al abrir archivo | -2 -> Lista vacía
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char* path al archivo de datos .csv de los empleados
 * \param pArrayListEmployee LinkedList* Puntero a linked list de empleados
 * \return int 0 -> OK | -1 -> Error al abrir archivo | -2 -> Lista vacía
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


