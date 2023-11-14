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
	int len1, len2;

	len1 = _printf("hello \0 hey %s\n", "hey");
	printf("\n-----------------------------\n");
	len2 = printf("hello \0 hey %s\n", "hey");
	
	printf("\n printf: %d, _printf: %d\n", len2, len1);
	return (0);
}
