/* printf_int.c */

#include "main.h"
#include <unistd.h>

/**
* print_int - Print an integer
* @args: va_list containing the integer to print
*
* Return: Number of characters printed
*/
int print_int(va_list args)
{
int num = va_arg(args, int);
int count = 0;

if (num < 0)
{
write(1, "-", 1);
count++;
num = -num;
}

count += print_number(num);

return (count);
}

