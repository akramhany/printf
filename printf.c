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
	char *buffer, *temp1;

	while (format[formatLength] != '\0')
	{
		formatLength++;
	}

	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	va_start(ap, format);
	buffer = malloc(formatLength);

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
				write(1, &c, 1);
				totalPrintedChars++;
			}
			else if (format[i] == 's')
			{
				int k = 0;
				char *s = va_arg(ap, char*);

				if (s == NULL)
					return (-1);

				while (s[k] != '\0')
				{
					k++;
				}
				write(1, s, k);
				totalPrintedChars += k;
			}
			else if (format[i] == '%')
			{
				char *c = "%";
				write(1, c, 1);
				totalPrintedChars++;
			}
			else
			{
				char *c = "%";
				char k = format[i];
				write(1, c, 1);
				c = &k;
				write(1, c, 1);
				totalPrintedChars += 2;
			}
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

	temp1 = "\0";
	write(1, temp1, 1);

	va_end(ap);

	free (buffer);

return (totalPrintedChars);
}
