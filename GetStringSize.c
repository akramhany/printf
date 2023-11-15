#include "main.h"

/**
 * GetStringSize - returns the size of a string
 * @string: the string inwhich I would like to return its size
 * Return: return the size of the string, or -1 if the string is Null
 **/

int GetStringSize(const char *string)
{
	int stringSize = 0;

	if (string == NULL)
		return (-1);

	while (string[stringSize] != '\0')
		stringSize++;

	return (stringSize);
}
