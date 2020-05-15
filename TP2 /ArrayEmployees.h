typedef struct {
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

/**
 * @brief init the .isEmpty value in all Employee list[] array to emptyTrue value.
 * 
 * @param list struct Employee data array.
 * @param length int length of the Employee array.
 * @param emptyTrue int Logic emptyTrue value.
 * @return int 0 -> OK | -1 -> ERROR
 */
int initEmployees(Employee list[], int length, int emptyTrue);

/**
 * @brief find the first slot empty to charge data
 * 
 * @param list struct Employee data array.
 * @param length int length of the Employee array 
 * @param empty int Logic emptyTrue value.
 * @return int INDEX of first empty slot to charge | -1 -> if no empty space.
 */
int findEmpty(Employee list[],int length, int empty);

/**
 * @brief Print Employee list, only if isEmpty -> notEmpty
 * 
 * @param list struct Employee data array.
 * @param length int length of the Employee array 
 * @param emptyFalse int Logic emptyFalse value.
 * @return int 0 -> OK | -1 -> ERROR 
 */
int printEmployeesList(Employee list[], int length, int emptyFalse); 

/**
 * @brief Manage get data and add an employee to database.
 * 
 * @param list struct Employee data array.
 * @param length int length of the Employee array  
 * @param empty int Logic emptyTrue value.
 * @param notEmpty int Logic emptyFalse value.
 * @return int 0 -> OK | -1 -> Operation canceled by user | -2 -> No match with entered ID
 */
int addEmployee(Employee list[], int length, int empty, int notEmpty);

/**
 * @brief Sort employees list by sector and by lastName.
 * 
 * @param list struct Employee data array.
 * @param length int length of the Employee array 
 * @param order 1 -> from A to Z | 0 -> from Z to A
 * @param notEmpty int Logic emptyFalse value.
 * @return int 0 -> OK | -1 -> ERROR 
 */
int sortEmployees(Employee list[], int length, int order, int notEmpty);

/**
 * @brief Manage remove employee and delete it from database.
 * 
 * @param list struct Employee data array.
 * @param length int length of the Employee array
 * @param empty int Logic emptyTrue value.
 * @param notEmpty int Logic emptyFalse value. 
 * @return int 0 -> OK | -1 -> Operation canceled by user | -2 -> No match with entered ID
 */
int removeEmployee(Employee list[], int length, int empty, int notEmpty);

/**
 * @brief Manage modify employee and update it in database.
 * 
 * @param list struct Employee data array.
 * @param length int length of the Employee array 
 * @param notEmpty int Logic emptyFalse value.
 * @param empty int Logic emptyTrue value. 
 * @return int 0 -> OK | -1 -> Operation canceled by user | -2 -> No match with entered ID
 */
int modifyEmployee(Employee list[],int length, int notEmpty, int empty  );

/**
 * @brief Print info of averages salaries, quantity of employees, etc.
 * 
 * @param list struct Employee data array.
 * @param length int length of the Employee array 
 * @param notEmpty int Logic emptyFalse value. 
 * @return int 0 -> OK | -1 -> ERROR 
 */
int printInfoSalary(Employee list[], int length, int notEmpty);