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
	int len;

	len = _printf("%K\n");
    	printf("Len:[%d]\n", len);

	return (0);
}
