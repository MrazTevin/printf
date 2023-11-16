/* printf_functions.c */

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
char buffer[1024];  /* Local buffer */
int buffer_index = 0;  /* Index to track the current position in the buffer */

va_start(args, format);

if (format == NULL)
{
va_end(args);
return (-1);
}

count = process_format_string(format, args, buffer, &buffer_index);

va_end(args);
return (count);
}

/**
* process_format_string - Process the format string
* @format: Format string
* @args: Variable arguments list
* @buffer: Buffer for storing formatted output
* @buffer_index: Index to track the current position in the buffer
*
* Return: Number of characters printed
*/
int process_format_string(const char *format, va_list args,
char *buffer, int *buffer_index)
{
int count = 0;
const char *ptr;
print_t print_arr[] = {
{'c', print_char},
{'s', print_str},
{'%', print_percent},
{'d', print_int},
{'i', print_int},
{'u', print_unsigned},
{'o', print_octal},
{'x', print_hex_lower},
{'X', print_hex_upper},
{0, NULL}
};

for (ptr = format; *ptr != '\0'; ptr++)
{
if (*ptr == '%')
{
ptr++; /* Move to the next character after '%' */
count += process_percent_specifier(ptr, print_arr, args, buffer, buffer_index);
}
else
{
count += process_regular_char(*ptr, buffer, buffer_index);
}
}

/* Print any remaining characters in the buffer */
if (*buffer_index > 0)
{
write(1, buffer, *buffer_index);
count += *buffer_index;
*buffer_index = 0; /* Reset the buffer index */
}

return (count);
}

/**
* process_percent_specifier - Process a percent specifier in the format string
* @specifier: The percent specifier character
* @print_arr: Array of print functions
* @args: Variable arguments list
* @buffer: Buffer for storing formatted output
* @buffer_index: Index to track the current position in the buffer
*
* Return: Number of characters printed
*/
int process_percent_specifier(const char *specifier, print_t *print_arr,
va_list args, char *buffer, int *buffer_index)
{
int count = 0;

for (int i = 0; print_arr[i].spec != 0; i++)
{
if (*specifier == print_arr[i].spec)
{
/* Check if the buffer is full before calling the function */
if (*buffer_index >= 1023)
{
write(1, buffer, *buffer_index);
count += *buffer_index;
*buffer_index = 0; /* Reset the buffer index */
}

/* Call the corresponding print function and update count and buffer_index */
count += print_arr[i].func(args, buffer + *buffer_index);
*buffer_index += count;

break;
}
}

return (count);
}

/**
* process_regular_char - Process a regular character in the format string
* @c: The character to process
* @buffer: Buffer for storing formatted output
* @buffer_index: Index to track the current position in the buffer
*
* Return: Number of characters printed
*/
int process_regular_char(char c, char *buffer, int *buffer_index)
{

