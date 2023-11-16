/* printf_char.c */

#include "printf_handlers.h"
#include <unistd.h>

/**
* print_char - Print a character
* @args: va_list containing the character to print
*
* Return: Number of characters printed
*/
int print_char(va_list args)
{
char c = va_arg(args, int);
write(1, &c, 1);
return (1);
}

