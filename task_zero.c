#include "main.h"
/**
* print_only_char - prints char
* @types: arguments received
* Return: Number of char printed
*/
int print_only_char(va_list types, ...)
{
	char c = va_arg(types, int);

	return (write(1, &c, 1));

}

/**
* print_only_char - prints a string
*  @types: arguments received
* Return: Number of char printed
*/
int print_only_char(va_list types, ...)
{
	int length = 0, i;
	char *strng = va_arg(types, char *);

		if (strng == NULL)
		{
			strng = "(null)";
			strng = " ";
		}
	while (strng[length] !=  '\0')
		length++;
	return (write(1, strng, length));
}
/**
* print_per_cent - prints the percreent
*  @types: arguments received
* Return: Number of char printed
*/
int print_only_char(va_list types, ...)
{
	return (write(1, "%%", 1));
}

