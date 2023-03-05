#include <string>

/// @brief This function will check prior of char c at the entrance
/// @param c char
/// @return prior of char c
int f_check_prior(char c);

/// @brief This function will check if char given at the entrance is operand or not
/// @param c char
/// @return true if c is operand, else false
bool f_check_ifoperand(char c);

/// @brief This function will check if operator is connected left-side
/// @param c char
/// @return true if operator is connected left-side, else false
bool f_check_ifleft(char c);

/// @brief This function will check if expression in type INF: is possible to transformation to ONP:
/// @param array addres to char array
/// @param numb_elements number of elements which can make expression
/// @return true if expression is possible to transformation from INF: to ONP:
bool f_check_ifpossible(char *array, int numb_elements);

/// @brief This functiion will check if char c is possible to use in INF: expression
/// @param c char
/// @return true if we can use it in epxression, else false
bool f_check_sign(char c);

/// @brief This function will check if c is operator
/// @param c char
/// @return true if c is operator, else false
bool f_check_ifoperator(char c);
