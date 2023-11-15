#include <stdarg.h>
#include <unistd.h>
#include "main.h"

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
