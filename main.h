#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _putchar(char c);
int _puts(char *str, int ascii);
int alpha_numeric_conversion(int number, int upp);
char *base_conversion(unsigned long number, unsigned int base, int upp);
char *pointer_conversion(unsigned long ptr);
char *_strcopy(char *str);
int len_recursion(char *s);
int string_reverse(va_list ap);
char *new_string(char *str);
int _char(va_list ap);
int _string(va_list ap);
int _percent(va_list args __attribute__((unused)));
int (*char_type(const char c))(va_list);
int _printf(const char *format, ...);

typedef struct _printf_flag
{
	char *c;
	int (*f_p)(va_list);
} myflag;
#endif
