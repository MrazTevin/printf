/* printf_str.c */

#include "main.h"
#include <unistd.h>

/**
* print_str - Print a string
* @args: va_list containing the string to print
*
* Return: Number of characters printed
*/
int print_str(va_list args)
{
char *str = va_arg(args, char *);
int len = 0;

if (str == NULL)
str = "(null)";

while (str[len] != '\0')
{
write(1, &str[len], 1);
len++;
}

return (len);
}

