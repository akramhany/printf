#include <limits.h>
#include <stdio.h>
#include "../main.h"
#include "../printf.c"


/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len, len2;

	len = _printf("Percent:[%%]\n");
   	len2 = printf("Percent:[%%]\n");
    	_printf("Len:[%d]\n", len);
    	printf("Len:[%d]\n", len2);

	return (0);
}
