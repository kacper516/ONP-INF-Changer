#include "LibFiles.hpp"

void f_open_read(std::fstream &file, std::string f_name)
{
	file.open(f_name, std::ios::in);
	if (!file)
	{
		exit(0);
	}
}

void f_open_write(std::fstream &file, std::string f_name)
{
	file.open(f_name, std::ios::out);
	if (!file)
	{
		exit(0);
	}
}

std::string f_check_if_txt(std::string name)
{
	if (name.length() <= 4)
	{
		name += '.';
		name += 't';
		name += 'x';
		name += 't';
	}
	if (name[name.length() - 1] != 't' and name[name.length() - 2] != 'x' and name[name.length() - 3] != 't' and name[name.length() - 4] != '.')
	{
		name += '.';
		name += 't';
		name += 'x';
		name += 't';
	}
	return name;
}

void f_save(std::fstream &file, std::string return_string)
{
	file << return_string << "\n";
}