#include "main.h"

/**
 * HandleLiterals - takes a string and handle "%" literals in it
 * @string: the string we want to handle
 * @index: the index of the literal you want to handle
 * @arg: a pointer to the value that would be outputed
 *
 * Return: number of the outputed chars
 **/

int HandleLiterals(const char *string, int index, void *arg)
{
	if (string == NULL)
		return (-1);

	if (string[index] == 'c')
	{
		char *c = (char *)arg;

		write(1, c, 1);
		return (1);
	}
	else if (string[index] == 's')
	{
		int size = -1;
		char *s = (char *)arg;

		if (s == NULL)
			s = "(null)";

		size = GetStringSize(s);
		write(1, s, size);
		return (size);
	}
	else if (string[index] == '%')
	{
		char c = '%';

		write(1, &c, 1);
		return (1);
	}
	else
	{
		char c = '%';
		char k = string[index];

		write(1, &c, 1);
		write(1, &k, 1);

		return (2);
	}
}
