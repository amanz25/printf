#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define BUFF_SIZE 1024


/**
 * struct trackflag - structure to tract the flag existance
 * @plusSign: to track plus sign
 * @hashSign: to track hash sign
 * @spaceSign: to track space
 */
typedef struct trackflag
{
	int plusSign;
	int hashSign;
	int spaceSign;
} T_flag;

/**
 * struct specifierStruct - structure definition
 * @specifier: format specifier character
 * @print_function: function to print character
 */
typedef struct specifierStruct
{
	char specifier;
	int (*print_function)(va_list arg, T_flag *t);
} specifierStruct;

int _printf(const char *format, ...);
int (*get_checkSpecifier(char formatSpecifierLetter))(va_list, T_flag *);
int get_special_specifiers(char c, T_flag *t);
int _char(va_list ap, T_flag *);
int _string(va_list ap, T_flag *);
int _percent(va_list args, T_flag *t);
int _putchar(char c);
int _put(char *s);
int _int(va_list ap, T_flag *);
int digit_len(int num);
void display_num_recur(int n);

char *change_base(unsigned long int number, int base, int ishexalower);
int _binary(va_list arg, T_flag *);

int _unsigned(va_list arg, T_flag *);
int _hexadecimal(va_list arg, T_flag *);
int _hexadecimal_UPP(va_list arg, T_flag *);
int _octal(va_list arg, T_flag *);

int _customstring(va_list args, T_flag *);

int _pointer_address(va_list args, T_flag *);

int _reverse(va_list args, T_flag *t);

#endif
