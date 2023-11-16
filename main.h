#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/**
 * struct print - Struct to match format specifier with function
 * @spec: The format specifier
 * @func: The function to handle the specifier
 */
typedef struct print
{
char spec;
int (*func)(va_list);
} print_t;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_str(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_number(int num);
int write_digit(int digit);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);
int print_octal_number(unsigned int num);
int print_octal_number(unsigned int num);
int process_format_string(const char *format,
va_list args, char *buffer, int *buffer_index);
int process_percent_specifier(const char *specifier, print_t *print_arr,
va_list args, char *buffer, int *buffer_index);
int process_regular_char(char c, char *buffer, int *buffer_index);

#endif /* MAIN_H */

