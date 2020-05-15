
/**
 * @brief Show menu - ask for user selection
 * 
 * @param resp Int pointer where to save user response.
 */
void showMenu(int *resp);

/**
 * @brief Show modification menu - ask for user selection
 * 
 * @param resp Int pointer where to save user response.
 */
void showModificationMenu(int *resp);

/**
 * @brief Show info of employees and average salary.
 * 
 * @param count int count of employees
 * @param salarySum float sum of all salaries
 * @param salaryAvg float average of all salaries
 * @param betterWages int count of how many salaries exceed the average.
 */
void showInfoSalary(int count,float salarySum,float salaryAvg,int betterWages);

/**
 * @brief Print a message according to the int res
 * 
 * @param res int response of an operation.
 * @param m1 message un case to be 0.
 * @param m2 message un case to be -1.
 * @param m3 message un case to be -2.
 */
void printErrorCases(int res,char *m1, char *m2, char *m3);

/**
 * @brief Ask for an empty char to clean system and continue w/the program
 */
void sysPause();

/**
 * @brief Shows "Apretá ENTER", ask for an empty char ,clean system and continue w/the program
 */
void sysPauseMsg();
