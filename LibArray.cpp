#include "LibArray.hpp"

char *f_make_char_arr(std::string expression)
{
	int j = 0, numb_elem = expression.length();
	char *array = nullptr;
	try
	{
		// -5 because first 5 elements has got info it it's ONP or INF
		array = new char[(numb_elem - 5)];
	}
	catch (const std::bad_alloc)
	{
		std::cerr << "\nError, while creating array.";
		std::cin.ignore();
		exit(0);
	}
	for (int i = 5; i < numb_elem; i++)
	{
		array[j] = expression[i];
		j++;
	}
	return array;
}

int f_n_elem_possible(char *array, std::string expression)
{
	int possible_elements{};				 // number of possible element
	int numb_elem = expression.length() - 5; // -5 because first 5 elements has got info it it's ONP or INF
	for (int i = 0; i < numb_elem; i++)
	{
		if (f_check_sign(array[i]) == 1)
			continue;
		possible_elements++;
	}
	return possible_elements;
}

char *f_cr_new_array(char *array, std::string expression)
{
	int j = 0;
	int possible_elem = f_n_elem_possible(array, expression);
	int numb_elem = expression.length() - 5;

	char *new_array = nullptr;
	try
	{
		new_array = new char[possible_elem];
	}
	catch (const std::bad_alloc)
	{
		std::cerr << "\nError, while creating array.";
		std::cin.ignore();
		exit(0);
	}
	for (int i = 0; i < numb_elem; i++)
	{
		if (f_check_sign(array[i]) == 1)
		{
			continue;
		}
		new_array[j] = array[i];
		j++;
	}
	delete[] array;
	return new_array;
}

std::string f_arr_to_string(char *array, int elem_possible)
{
	std::string return_string;
	for (int i = 0; i < elem_possible; i++)
	{
		return_string += array[i];
	}
	return return_string;
}