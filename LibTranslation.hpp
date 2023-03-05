#include "LibStack.hpp"
#include "LibArray.hpp"
#include <stack>
#include <iostream>
#include <string>

/// @brief This function will change INF: to ONP: and return it like string
/// @param array array with chars
/// @param numb_elem number of elements that contain in our expression
/// @return string with ONP: type
std::string f_change_INFtoONP(char *array, int numb_elem);

/// @brief This function will change ONP: to INF: and retur it like string
/// @param array array with chars
/// @param numb_elem number of elements that contain in our expression
/// @return string with INF: type
std::string f_change_ONPtoINF(char *array, int numb_elem);
