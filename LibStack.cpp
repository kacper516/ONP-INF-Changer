#include "LibStack.hpp"

int f_check_prior(char c)
{
	if (c == '=')
		return 0;
	if (c == '<' or c == '>')
		return 1;
	if (c == '+' or c == '-')
		return 2;
	if (c == '*' or c == '/' or c == '%')
		return 3;
	if (c == '^')
		return 4;
	if (c == '~')
		return 5;

	return -1; // if there is no correct answer
}

bool f_check_ifoperand(char c)
{
	// we check ASCII code from a to z
	if (c > 96 and c < 123)
		return 1;
	else
		return 0;
}

bool f_check_ifleft(char c)
{
	if (c == '<' or c == '>' or c == '+' or c == '-' or c == '*' or c == '/' or c == '%')
		return 1;
	return 0;
}

bool f_check_ifpossible(char *array, int numb_elements)
{
	for (int i = 0; i < numb_elements - 1; i++) // -1 because we compare to next element
	{
		if (array[i] == '~' or array[i] == '^' or array[i] == '(' or array[i] == ')') // there can be infinitely many of them for each variable
			continue;																  // we'll check the parenthesis problem later

		if ((array[i] > 96 and array[i] < 123) and (array[i + 1] > 96 and array[i + 1] < 123))
			return 0; // if there is 2 operands in neighbourhood expression must be wrong

		if ((array[i] == '=' or array[i] == '+' or array[i] == '-' or array[i] == '*' or array[i] == '/' or array[i] == '%') and (array[i + 1] == '=' or array[i + 1] == '+' or array[i + 1] == '-' or array[i + 1] == '*' or array[i + 1] == '/' or array[i + 1] == '%'))
			return 0; // there can't be 2 operators like that in neighbourhood
	}
	return 1;
}

bool f_check_sign(char c)
{
	if ((c > 0 and c < 37) or (c == 38) or (c == 39) or (c == 44) or (c == 46) or (c > 47 and c < 60) or (c > 62 and c < 93) or
		(c > 94 and c < 97) or (c > 122 and c < 126) or (c > 127))
		return 1;
	else
		return 0;
}

bool f_check_ifoperator(char c)
{
	if (c == '=' or c == '<' or c == '>' or c == '+' or c == '-' or c == '*' or c == '/' or c == '%' or c == '^' or c == '~')
		return 1;
	else
		return 0;
}