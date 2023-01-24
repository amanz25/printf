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
int i;
char *str = va_arg(ap, char*);

if (str == NULL)
	str = "(null)";
else if (*str == '\0')
	return (-1);

for (i = 0; str[i]; i++)
	_putchar(str[i]);

return (i);
}
/**
 * _percent -  to print percent character
 *
 * @args: char argumet list
 * Return: percent character
 */
int _percent(va_list args __attribute__((unused)))
{
	return (_putchar('%'));
}
