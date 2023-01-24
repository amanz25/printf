#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>


/**
 * struct specifierStruct - structure definition
 * @specifier: format specifier character
 * @print_func: function to print character
 */
typedef struct specifierStruct
{
	char *specifier;
	int (*print_func)(va_list);
} specifierStruct;

int _printf(const char *format, ...);
int checkSpecifiers(char formatSpecifierLetter, va_list arg);
int _char(va_list ap);
int _string(va_list ap);
int _percent(va_list args __attribute__((unused)));
int _putchar(char c);
int _int(va_list ap);

#endif
