/* printf_number.c */

#include "main.h"

/**
* print_number - Print a positive integer
* @num: The integer to print
*
* Return: Number of characters printed
*/
int print_number(int num)
{
int count = 0;

if (num / 10 != 0)
count += print_number(num / 10);

count += write_digit(num % 10);

return (count);
}

