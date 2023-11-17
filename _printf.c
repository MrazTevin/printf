#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* _printf - Custom printf function
* @format: Format string
*
* Return: Number of characters printed (excluding null byte)
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);

if (format == NULL)
{
va_end(args);
return (-1);
}

count = process_format_string(format, args);

va_end(args);
return (count);
}

/**
* process_format_string - Process the format string
* @format: Format string
* @args: Variable arguments list
*
* Return: Number of characters printed
*/
int process_format_string(const char *format, va_list args)
{
int count = 0;
const char *ptr;

for (ptr = format; *ptr != '\0'; ptr++)
{
if (*ptr == '%' && *(ptr + 1) != '\0')
{
ptr++; /* Move to the next character after '%' */
count += process_percent_specifier(ptr, args);
}
else
{
count += write(1, ptr, 1);
}
}

return (count);
}

/**
* process_percent_specifier - Process a percent specifier in the format string
* @specifier: The percent specifier character
* @args: Variable arguments list
*
* Return: Number of characters printed
*/
int process_percent_specifier(const char *specifier, va_list args)
{
int count = 0;

switch (*specifier)
{
case 'c':
count += print_char(va_arg(args, int));
break;
case 's':
count += print_str(va_arg(args, char *));
break;
case '%':
count += print_percent();
break;
default:
/* Handle unsupported specifier */
count += write(1, "%", 1) + write(1, specifier, 1);
break;
}

return (count);
}

/* Implement print_char, print_str, and print_percent functions here */

