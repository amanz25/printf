#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define BUFF_SIZE 1024

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
int _percent(va_list args);
int _putchar(char c);
int _put(char *s);
int _int(va_list ap);

char *change_base(unsigned long int number, int base, int ishexalower);
int _binary(va_list arg);

int _unsigned(va_list arg);
int _hexadecimal(va_list arg);
int _hexadecimal_UPP(va_list arg);
int _octal(va_list arg);

int _customstring(va_list args);

#endif
