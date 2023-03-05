#pragma once

#include <iostream>
#include <string>
#include <fstream>

/// @brief This function will open file to read from it and check if we can open it
/// @param file file we want to open
/// @param f_name name of file we want to open
void f_open_read(std::fstream &file, std::string f_name);

/// @brief This function will open file to write to and check if we can open it
/// @param file file we want to open
/// @param f_name name of file we want to open
void f_open_write(std::fstream &file, std::string f_name);

/// @brief This function will check if name given by user has got ".txt" extension
/// @param name name of file
/// @return if there is no ".txt" extension we will add it to our string
std::string f_check_if_txt(std::string name);

/// @brief This function will save new expression from INF: to ONP: and vice versa
/// @param file file we want to save to
/// @param return_string name of file we will take information from
void f_save(std::fstream &file, std::string return_string);