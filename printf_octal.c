/* printf_octal.c */

#include "printf_handlers.h"
#include <unistd.h>

/**
* print_octal - Print an octal number
* @args: va_list containing the octal number to print
*
* Return: Number of characters printed
*/
int print_octal(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
int count = 0;

count += print_octal_number(num);

return (count);
}

