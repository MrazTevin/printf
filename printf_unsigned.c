/* printf_unsigned.c */

#include "main.h"
#include <unistd.h>

/**
* print_unsigned - Print an unsigned integer
* @args: va_list containing the unsigned integer to print
*
* Return: Number of characters printed
*/
int print_unsigned(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
int count = 0;

count += print_number(num);

return (count);
}

