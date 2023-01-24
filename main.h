#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>


/**
 * struct specifierStruct - structure definition
 * @specifier: format specifier character
 * @print_function: function to print character
 */
typedef struct specifierStruct
{
	char specifier;
	int (*print_function)(va_list);
} specifierStruct;

int _printf(const char *format, ...);
int (*get_checkSpecifier(char formatSpecifierLetter))(va_list);
int _char(va_list ap);
int _string(va_list ap);
int _percent(va_list args __attribute__((unused)));
int _putchar(char c);
int _int(va_list ap);

#endif
