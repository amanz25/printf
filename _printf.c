#include <stdlib.h>
#include "main.h"

/**
 * checkSpecifiers - print char based on the specifier
 * @formatSpecifierLetter: format specifier character
 * @arg: current traversed argument.
 *
 * Return: 1 if it gets the correct specifier else 0.
 */
int checkSpecifiers(char formatSpecifierLetter, va_list arg)
{
	int i;

	specifierStruct specifiers[] = {
			{"c", _char},
			{"s", _string},
			{NULL, NULL}
			};

	for (i = 0; specifiers[i].specifier != NULL; i++)
	{
		if (specifiers[i].specifier[0] == formatSpecifierLetter)
			return (specifiers[i].print_func(arg));
	}
	return (0);
}

/**
 * _printf - varidic fucntion to print characters with different format
 * @format: the first paramater is format string
 *
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
	unsigned int i;
	int formatSpecifier = 0, count = 0;
	va_list arg;


	if (format == NULL)
		return (-1);

	va_start(arg, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
			continue;
		}
		if (format[i + 1] == '%')
		{
			_putchar('%');
			count++;
			i++;
			continue;
		}
		if (format[i + 1] == '\0')
			return (-1);
		formatSpecifier = checkSpecifiers(format[i + 1], arg);
		if (formatSpecifier == -1 || formatSpecifier != 0)
			i++;
		if (formatSpecifier > 0)
			count += formatSpecifier;
		if (formatSpecifier == 0)
		{
			_putchar('%');
			count++;
		}
	}
	va_end(arg);
	return (count);
}
