#include <limits.h>
#include <stdio.h>
#include "../main.h"
#include "../printf.c"
#include "../GetStringSize.c"
#include "../HandleLiterals.c"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;

	len = _printf("%K\n");
    	printf("Len:[%d]\n", len);

	return (0);
}
