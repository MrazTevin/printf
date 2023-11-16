/* printf_write_digit.c */

#include "main.h"
#include <unistd.h>

/**
* write_digit - Write a digit to the standard output
* @digit: The digit to write
*
* Return: Always 1 (the digit)
*/
int write_digit(int digit)
{
char c = digit + '0';
write(1, &c, 1);
return (1);
}

