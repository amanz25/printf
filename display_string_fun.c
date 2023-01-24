#include "main.h"

/**
 * _char - a function to print character
 *
 * @ap: characters argument list
 * Return: printed character
 */
int _char(va_list ap)
{
	return (_putchar(va_arg(ap, int)));
}

/**
 * _string - to print a string
 *
 * @ap: string argument list
 * Return: printed string
 */
int _string(va_list ap)
{
char *str = va_arg(ap, char*);

if (!str)
	str = "(null)";

return (_put(str));
}
/**
 * _percent -  to print percent character
 *
 * @args: char argumet list
 * Return: percent character
 */
int _percent(va_list args)
{
	(void)args;
	return (_putchar('%'));
}
