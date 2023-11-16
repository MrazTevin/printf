/* printf_handlers.h */

#ifndef PRINTF_HANDLERS_H
#define PRINTF_HANDLERS_H

#include <stdarg.h>

int print_char(va_list args);
int print_str(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);
int print_number(int num);
int print_octal_number(unsigned int num);
int print_hex_number(unsigned int num, int uppercase);
int write_digit(int digit);

#endif /* PRINTF_HANDLERS_H */

