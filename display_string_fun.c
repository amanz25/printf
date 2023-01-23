#include "main.c"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _char - a function to print character
 *
 * @ap: characters argument list
 * Return: printed character
 */
 int _char (va_list ap)
 {
     char c= va_arg(ap, int);
     if (c == '\0')
     {
         return(write(1, &c, 1));
     }
     _putchar(c);
     return(1);
 }

/**
 * _string - to print a string
 *
 * @ap: string argument list
 * Return: printed string
 */
 int _string (va_list ap)
 {
     char *argument = va_arg(ap, char *);
     int sum = 0;
     if (!argument)
     {
         sum += _puts ("(null)", 0);
         return (sum);
     }
     return (_puts(argument, 0));
 }
/**
 * _percent -  to print percent character
 *
 * @args: char argumet list
 * Return: percent character
 */
 int _percent (va_list args __attribute__((unused)))
 {
     return (_putchar('%'));
 }
