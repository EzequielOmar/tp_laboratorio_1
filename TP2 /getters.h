/**
 * @brief Get a string of ALPHABETICAL chars between min and max, and uppercase the first letter.
 * 
 * @param pResultado pointer to copy string.
 * @param mensaje message to show before ask string.
 * @param minimo min of characters.
 * @param maximo max of characters. 
 * @return 0 if OK | -1 invalid char | -2 > max value or < min value | 
 */
int getStr_Alpha(char* pResultado, char* mensaje, int minimo, int maximo);

/**
 * @brief Get a float variable between min and max.
 * 
 * @param pResultado pointer of a variable in witch you will save a float.
 * @param mensaje message to show before ask for a float.
 * @param minimo min value posible.
 * @param maximo max value posible.
 * @return  0 if OK | -1 > max value or < min value | -2 invalid char |
 */
int getFloat(float* pResultado, char* mensaje, float minimo, float maximo);

/**
 * @brief Get an int variable between min and max.
 * 
 * @param pResultado pointer of a variable in witch you will save an int.
 * @param mensaje message to show before ask for an int .
 * @param minimo min value posible.
 * @param maximo max value posible.
 * @return 0 if OK | -1 > max value or < min value | -2 invalid char |
 */
int getInt(int* pResultado, char* mensaje, int minimo, int maximo);