/* printf_hex_upper.c */

#include "main.h"
#include <unistd.h>

/**
* print_hex_upper - Print a hexadecimal number in uppercase
* @args: va_list containing the hexadecimal number to print
*
* Return: Number of characters printed
*/
int print_hex_upper(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
int count = 0;

count += print_hex_number(num, 1);

return (count);
}

