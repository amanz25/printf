#include "main.h"

/**
 * get_special_specifiers - change value of flag struc if special char found
 * @c: special format specifier + # or space.
 * @t: pointer to struct
 *
 * Return: 1 if it is special specifer(+,# or space) else 0.
 */
int get_special_specifiers(char c, T_flag *t)
{
	int res = 0;

	if (c == '+')
	{
		t->plusSign = 1;
		res = 1;
	}
	else if (c == '#')
	{
		t->hashSign = 1;
		res = 1;
	}
	else if (c == ' ')
	{
		t->spaceSign = 1;
		res = 1;
	}

	return (res);
}

/**
 * get_checkSpecifier - print char based on the specifier
 * @formatSpecifierLetter: format specifier characte.
 *
 * Return: 1 if it gets the correct specifier else 0.
 */
int (*get_checkSpecifier(char formatSpecifierLetter))(va_list, T_flag *)
{
	specifierStruct functs[] = {
		{'s', _string},
		{'c', _char},
		{'i', _int},
		{'d', _int},
		{'b', _binary},
		{'u', _unsigned},
		{'o', _octal},
		{'x', _hexadecimal},
		{'X', _hexadecimal_UPP},
		{'S', _customstring},
		{'p', _pointer_address},
		{'%', _percent}
	};

	int i;

	for (i = 0; i < 12; i++)
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
	int (*func)(va_list, T_flag *);
	const char *curr;
	va_list args;
	T_flag t = {0, 0, 0};
	int strlen = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (curr = format; *curr; curr++)
	{
		if (*curr == '%')
		{
			curr++;
			if (*curr == '%')
			{
				strlen += _putchar('%');
				continue;
			}
			while (get_special_specifiers(*curr, &t))
				curr++;

			func = get_checkSpecifier(*curr);
			if (func)
				strlen += func(args, &t);
			else
				strlen += _printf("%%%c", *curr);
		}
		else
			strlen += _putchar(*curr);
	}
	_putchar(-1);
	va_end(args);
	return (strlen);
}
