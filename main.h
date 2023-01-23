#include<stdarg.h>

#ifndef MAIN_H
#define MAIN_H

#define buffsize 1024

/*  print character */
int _putchar(char c);

/*  print string based on args */
int _printf(const char *format, ...);
void conditions(const char *format,va_list args);
int customPrint(const char *format, va_list args);

/* number display */
void unsigned_number_to_string(int num, int base, char *buffer);
void number_to_string(int num, int base, char *buffer);

#endif
