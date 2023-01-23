#include <stdarg.h>
#include "main.h"

/**
 * char_type - to selct a function to translat character
 *
 * @c: to checke the character
 * Return: pointer
 */
int (*char_type(const char c))(va_list)
{
	int i = 0;

	myflag flagpointer[] = {
		{"c", _char},
		{"s", _string},
		{"%", _percent}
	};
	while (i < 14)
	{
		if (c == flagpointer[i].c[0])
		{
			return (flagpointer[i].f_p);
		}
		i++;
	}
	return (NULL);
}

/**
 * _printf - varidic fucntion to print characters with different format
 *
 * @format: the first paramater is format string
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
	va_list arg_parameters;
	int sum = 0, i = 0;
	int (*func)();

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(arg_parameters, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
				func = char_type(format[i + 1]);
			if (func == NULL)
			{
				_putchar(format[i]);
				sum++;
				i++;
			}
			else
			{
				sum += func(arg_parameters);
				i += 2;
				continue;
			}
		}
		else
		{
			_putchar(format[i]);
			sum++;
			i++;
		}
	}
	va_end(arg_parameters);
	return (sum);
}
