/* printf_hex_lower.c */

#include "main.h"
#include <unistd.h>

/**
* print_hex_lower - Print a hexadecimal number in lowercase
* @args: va_list containing the hexadecimal number to print
*
* Return: Number of characters printed
*/
int print_hex_lower(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
int count = 0;

count += print_hex_number(num, 0);

return (count);
}

