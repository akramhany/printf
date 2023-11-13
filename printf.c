#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - output a string to the std output.
 * @format: The string that will be outputed to the stdout.
 * @...: The variabels that would be outputed in the string.
 *
 * Return: the number of characters printed (excluding the null byte used to end the output string)
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int formatLength = 0;
	int i = 0, bufferSize = 0, totalPrintedChars = 0;
	char *buffer;

	while (format[formatLength] != '\0')
	{
		formatLength++;
	}

	va_start(ap, format);
	
	buffer = malloc(formatLength);

	totalPrintedChars = formatLength - 1;

	while (i < formatLength)
	{
		if (format[i] == '%')
		{
			write(1, buffer, bufferSize);
			bufferSize = 0;
			i++;

			if (format[i] == 'c')
			{
				char c = va_arg(ap, int);
				char *temp = &c;
				write(1, temp, 1);
				totalPrintedChars++;
			}
			else if (format[i] == 's')
			{
				int k = 0;
				char *s = va_arg(ap, char*);

				while (s[k] != '\0')
				{
					k++;
				}
				write(1, s, k - 1);
				totalPrintedChars += (k - 1);
			}
			else if (format[i] == '%')
			{
				char *c = "%";
				write(1, c, 1);
				totalPrintedChars++;
			}

		}
		else
		{
			buffer[bufferSize] = format[i];
			bufferSize++;
		}

		i++;
	}
	
	if (bufferSize != 0)
	{
		write(1, buffer, bufferSize);
	}

	va_end(ap);

return (totalPrintedChars);
}
