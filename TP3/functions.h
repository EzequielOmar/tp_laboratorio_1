
/**
 * @brief Show menu - ask for user selection
 * 
 * @param resp Int pointer where to save user response.
 */
void showMenu(int *resp);

/**
 * @brief Show modif menu - ask for user selection
 * 
 * @param resp Int pointer where to save user response.
 */
void showModifMenu(int *resp);

/**
 * @brief Print a message according to the int res
 * 
 * @param res int response of an operation.
 * @param m1 message un case to be 0.
 * @param m2 message un case to be -1.
 * @param m3 message un case to be -2.
 * @param m4 message un case to be -3.
 */
void printErrorCases(int res,char *m1, char *m2, char *m3, char *m4);

/**
 * @brief Ask for an empty char to clean system and continue w/the program
 */
void sysPause();

/**
 * @brief Shows "Apretá ENTER", ask for an empty char ,clean system and continue w/the program
 */
void sysPauseMsg();

/**
 * @brief Check if a string is made of only numbers
 * 
 * @param cadena str to check
 * @return int 0 -> OK | -1 -> ERROR
 */
int isInt(char* cadena);

/**
 * @brief Check if a string is made of only alphabetical characters
 * 
 * @param cadena str to check
 * @return int 0 -> OK | -1 -> ERROR
 */
int isAlpha(char* cadena);