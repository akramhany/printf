#include <limits.h>
#include <stdio.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;

	len = _printf("%d", -2147483648);
    	printf("Len:[%d]\n", len);

	return (0);
}
