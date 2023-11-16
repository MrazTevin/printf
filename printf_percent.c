/* printf_percent.c */

#include "main.h"
#include <unistd.h>

/**
* print_percent - Print a percent character
* @args: Unused
*
* Return: Always 1 (the percent character)
*/
int print_percent(va_list args)
{
(void)args; /* Unused parameter */
write(1, "%", 1);
return (1);
}

