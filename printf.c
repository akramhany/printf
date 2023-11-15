#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * PrintInteger - prints an integer to the stdout
 * @integer: the integer to print
 *
 * Return: the length of the passed integer
 **/

int PrintInteger(int integer)
{
	int length = 0, k = 0, tempLength = 0, sign = 0;
	char *arr = NULL;


	if (integer < 0)
	{
		char c = '-';
		write(1, &c, 1);
		integer = -integer;
		sign = 1;
	}
	else if (integer == 0)
	{
		char c = '0';
		write(1, &c, 1);
		return (1);
	}
	
	k = integer;
	while (k > 0)
	{
		k = k / 10;
		length++;
	}

	arr = malloc(sizeof(char) * length);
	
	k = integer;
	tempLength = length;

	while (tempLength > 0)
	{
		int temp = k;

		k = (k / 10);
		k *= 10;
		arr[tempLength - 1] = 48 + (temp - k);
	       	k /= 10;	
		tempLength--;
	}

	tempLength = 0;

	while (tempLength < length)
	{
		char c = arr[tempLength];

		write(1, &c, 1);
		tempLength++;
	}

	free(arr);
	return (length + sign);
}


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
	else if (string[index] == 'd' || string[index] == 'i')
	{
		int *ptr = (int *)arg;
		int length = PrintInteger(*ptr);

		return (length);
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


/**
 * _printf - output a string to the std output.
 * @format: The string that will be outputed to the stdout.
 * @...: The variabels that would be outputed in the string.
 *
 * Return: the number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int formatLength = 0;
	int i = 0, bufferSize = 0, totalPrintedChars = 0;
	char *buffer;

	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	formatLength = GetStringSize(format);

	va_start(ap, format);
	buffer = malloc(formatLength);

	if (!buffer)
		return (-1);

	while (i < formatLength)
	{
		if (format[i] == '%')
		{
			int outputedStringSize = -1;

			write(1, buffer, bufferSize);
			bufferSize = 0;
			i++;
			if (format[i] == 'c')
			{
				char c = va_arg(ap, int);

				outputedStringSize = HandleLiterals(format, i, &c);
			}
			else if (format[i] == 's')
				outputedStringSize = HandleLiterals(format, i, va_arg(ap, char *));
			else if (format[i] == 'd' || format[i] == 'i')
			{
				int k = va_arg(ap, int);
				outputedStringSize = HandleLiterals(format, i, &k);
			}
			else
				outputedStringSize = HandleLiterals(format, i, NULL);

			if (outputedStringSize != -1)
				totalPrintedChars += outputedStringSize;
		}
		else
		{
			buffer[bufferSize] = format[i];
			bufferSize++;
			totalPrintedChars++;
		}

		i++;
	}
	if (bufferSize != 0)
	{
		write(1, buffer, bufferSize);
	}


	va_end(ap);

	free(buffer);

return (totalPrintedChars);
}
