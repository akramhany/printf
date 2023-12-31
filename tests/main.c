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
    int len = _printf("Let's try to printf a simple sentence.\n");
    int len2 = printf("Let's try to printf a simple sentence.\n");    
    unsigned int ui;
    void *addr; 
    
    printf("_printf: %d, printf: %d\n", len, len2);
    printf("--------------------------------\n");

    len = _printf("Character:[%c]\n", 'H');
    len2 = printf("Character:[%c]\n", 'H');
    printf("_printf: %d, printf: %d\n", len, len2);
    
    printf("--------------------------------\n");

    len = _printf("String:[%s]\n", "I am a string !");
    len2 = printf("String:[%s]\n", "I am a string !");
    printf("_printf: %d, printf: %d\n", len, len2);

    printf("--------------------------------\n");

    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    printf("_printf: %d, printf: %d\n", len, len2);

    printf("--------------------------------\n");
    
    len = _printf("%s%s\n","hello world", "hey");
    len2 = printf("%s%s\n","hello world", "hey");
    printf("_printf: %d, printf: %d\n", len, len2);
    
    printf("--------------------------------\n");
        len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
   
   len = _printf("%c hi %c\n", 'a', 65);
    len2 = printf("%c hi %c\n", 'a', 65);
    printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);



    return (0);
}
