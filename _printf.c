#include "main.h"

/**
 * get_checkSpecifier - print char based on the specifier
 * @formatSpecifierLetter: format specifier characte.
 *
 * Return: 1 if it gets the correct specifier else 0.
 */
int (*get_checkSpecifier(char formatSpecifierLetter))(va_list)
{
	specifierStruct functs[] = {
		{'s', _string},
		{'c', _char},
		{'d', _int},
		{'i', _int},
		{'%', _percent}
	};

	int i;

	for (i = 0; i < 5; i++)
	{
		if (functs[i].specifier == formatSpecifierLetter)
			return (functs[i].print_function);
	}
	return (NULL);
}

/**
 * _printf - varidic fucntion to print characters with different format
 * @format: the first paramater is format string
 *
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list);
	const char *p;
	va_list args;

	int count = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}

			pfunc = get_checkSpecifier(*p);
			count += (pfunc) ? pfunc(args) : _printf("%%%c", *p);
		}
		else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(args);
	return (count);
}
