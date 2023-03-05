#pragma once

#include "LibStack.hpp"
#include <iostream>
#include <string>

/// @brief This function will create new array, write array to char array
/// @param expression name of variable where we store our expression
/// @return addres to array
char *f_make_char_arr(std::string expression);

/// @brief This function will search for element that is possible in our expression
/// @param array pointer to array fill with chars
/// @param expression name of variable where we store our expression
/// @return number of elements that can contain our expression
int f_n_elem_possible(char *array, std::string expression);

/// @brief This function will create new char array with possible elements
/// @param array pointer to array with char elements
/// @param expression name of variable where we store our expression
/// @return addres to new array
char *f_cr_new_array(char *array, std::string expression);

/// @brief This function rewrite elements to variable type string
/// @param array array fill with chars
/// @param elem_possible number of elements possible in our equation
/// @return rewrite array to type string
std::string f_arr_to_string(char *array, int elem_possible);
