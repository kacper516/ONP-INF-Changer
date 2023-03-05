#include "LibFiles.hpp"
#include "LibArray.hpp"
#include "LibStack.hpp"
#include "LibTranslation.hpp"

int main()
{
	std::string expression;
	std::string string_return = "";
	std::string arr_to_string;
	std::string input = "input.txt";
	std::string output = "output.txt";
	std::fstream file_in;
	std::fstream file_out;

	int n_sets{};
	int n_elem_possible{};

	char *array;
	char *n_array;

	f_open_read(file_in, input);
	f_open_write(file_out, output);

	file_in >> n_sets;
	file_in << "\n"; // we check number of sets and go to next line
	while (n_sets)
	{
		std::getline(file_in, expression); // we take first expression
		array = f_make_char_arr(expression);
		n_elem_possible = f_n_elem_possible(array, expression);
		n_array = f_cr_new_array(array, expression);

		if (expression[0] == 'O') // it means from ONP: to INF:
		{
			string_return = f_change_ONPtoINF(n_array, n_elem_possible);
			f_save(file_out, string_return);
		}
		else
		{
			string_return = f_change_INFtoONP(n_array, n_elem_possible);
			f_save(file_out, string_return);
		}
		n_sets--;
	}

	file_in.close();
	file_out.close();
}