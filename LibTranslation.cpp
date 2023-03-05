#include "LibTranslation.hpp"

std::string f_change_INFtoONP(char *array, int numb_elem)
{
	std::string string_return;				   // string we made from array
	std::string string_return_final = "ONP: "; // we start final value with ONP:
	std::stack<char> stack;					   // stack

	int temp{};
	int numb_brackets{}; // number of brackets
	int n_br{};			 // we will use this variable when we want to make a output file
	int j = 0;			 // auxiliary variable

	if (f_check_ifpossible(array, numb_elem) == 0)
	{
		return "ONP: error";
	}
	for (int i = 0; i < numb_elem; i++)
	{
		if (f_check_ifoperand(array[i]) == 1)
		{
			string_return += array[i];
			j++;
		}
		else
		{
			if (f_check_prior(array[i]) == -1)
			{
				// it must be brackets
				if (array[i] == '(')
				{
					temp = 6; // I choose this value so that there is more and nothing can come out as long as this parenthesis is there
					stack.push(array[i]);
					numb_brackets++;
					n_br++;
					continue;
				}
				if (array[i] == ')')
				{
					numb_brackets--;
					if (numb_brackets < 0)
					{
						// if there is no more brackets, it will print error, it means that there is more '(' than ')' and vice versa
						return "ONP: error";
					}

					// dropping elements from the stack until it encounters an opening brace
					while (stack.top() != '(')
					{
						if (stack.top() == ')')
						{
							stack.pop();
							continue;
						}
						string_return += stack.top();
						j++;
						stack.pop();
					}
					stack.pop();
				}
			}

			if (stack.empty())
			{
				stack.push(array[i]);
				temp = f_check_prior(array[i]);
				continue;
			}

			// left operators and right operators has got diffrent conditions
			if (f_check_ifleft(array[i]) == 1)
			{
				if (f_check_prior(array[i]) <= temp)
				{
					while (stack.empty() != 1)
					{
						if (f_check_prior(array[i]) <= f_check_prior(stack.top()))
						{
							string_return += stack.top();
							j++;
							stack.pop();
						}
						else
						{
							break;
						}
					}
					stack.push(array[i]);
				}
				else
				{
					stack.push(array[i]);
					temp = f_check_prior(array[i]);
				}
			}
			else // right operator
			{
				if (f_check_prior(array[i]) < temp)
				{
					while (stack.empty() != 1)
					{
						if (f_check_prior(array[i]) < f_check_prior(stack.top()))
						{
							string_return += stack.top();
							j++;
							stack.pop();
						}
						else
						{
							break;
						}
					}
					stack.push(array[i]);
				}
				else
				{
					stack.push(array[i]);
					temp = f_check_prior(array[i]);
				}
			}
		}
	}

	while (stack.empty() != 1) // take from top
	{
		if (stack.top() == '(' or stack.top() == ')')
		{
			stack.pop();
			continue;
		}
		string_return += stack.top();
		stack.pop();
	}
	string_return_final += string_return;
	return string_return_final;
}

std::string f_change_ONPtoINF(char *array, int numb_elem)
{
	std::stack<std::string> stack;
	std::string expression;
	std::string stack_string;
	std::string first_operand;
	std::string second_operand;
	std::string string_return;				   // string we start from
	std::string string_return_final = "INF: "; // we start our final string with this value
	int num_operands{};

	expression = f_arr_to_string(array, numb_elem);
	for (int i = 0; i < numb_elem; i++)
	{
		if (f_check_ifoperator(expression[i]) == 0)
		{
			stack_string = expression[i];
			stack.push(stack_string);
			num_operands++;
		}
		else
		{
			if (expression[i] == '~')
			{
				if (stack.empty() == 1)
				{
					return "INF: error";
					break;
				}
				else if (stack.size() <= 2)
				{
					first_operand = stack.top();
					stack.pop();
					stack_string = "~" + first_operand;
					stack.push(stack_string);
				}
				else
				{
					first_operand = stack.top();
					stack.pop();
					stack_string = "(~" + first_operand + ")";
					stack.push(stack_string);
				}
			}
			else
			{
				// if there is other options like + - * etc.
				num_operands--;
				if (stack.size() < 2)
				{
					return "INF: error";
					break;
				}
				else if (stack.size() != 2 and expression[i] == '=')
				{
					first_operand = stack.top();
					stack.pop();
					second_operand = stack.top();
					stack.pop();
					stack_string = "(" + second_operand + expression[i] + first_operand + ")";
					stack.push(stack_string);
				}
				else if (stack.size() == 2 or (stack.size() != 2 and f_check_ifoperator(expression[i + 1]) == 0) or (stack.size() != 2 and expression[i + 1] == '='))
				{
					first_operand = stack.top();
					stack.pop();
					second_operand = stack.top();
					stack.pop();
					stack_string = second_operand + expression[i] + first_operand;
					stack.push(stack_string);
				}
				else
				{
					first_operand = stack.top();
					stack.pop();
					second_operand = stack.top();
					stack.pop();
					stack_string = "(" + second_operand + expression[i] + first_operand + ")";
					stack.push(stack_string);
				}
			}
		}
	}
	if (num_operands != 1)
	{
		return "INF: error";
	}
	string_return = stack.top();
	string_return_final += string_return;
	return string_return_final;
}