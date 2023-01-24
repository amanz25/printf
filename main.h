#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int checkSpecifiers(char formatSpecifierLetter, va_list arg);
int _char(va_list ap);
int _string(va_list ap);
int _percent(va_list args __attribute__((unused)));
int _putchar(char c);

int _puts(char *str, int ascii);
int alpha_numeric_conversion(int number, int upp);
char *base_conversion(unsigned long number, unsigned int base, int upp);
char *pointer_conversion(unsigned long ptr);
char *_strcopy(char *str);
int len_recursion(char *s);
int string_reverse(va_list ap);
char *new_string(char *str);

/**
 * specifierStruct - structure definition
 * @specifier: format specifier character
 * @print_func: function to print character
 */
typedef struct specifierStruct
{
	char *specifier;
	int (*print_func)(va_list);
} specifierStruct;

#endif
