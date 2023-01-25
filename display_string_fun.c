#include "main.h"

/**
 * _char - a function to print character
 *
 * @ap: argument list
 * Return: printed character
 */
int _char(va_list ap)
{
	return (_putchar(va_arg(ap, int)));
}

/**
 * _string - to print a string
 *
 * @ap: argument list
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
 * @args: argumet list
 * Return: percent character
 */
int _percent(va_list args)
{
	(void)args;
	return (_putchar('%'));
}
/**
 * _customstring - print string
 * @args: argumet list
 * Return: count of string
 */
int _customstring(va_list args)
{
	char *str = va_arg(args, char *);
	char *convert;
	int index = 0;
	int strlen = 0;

	if (!str)
		return (_put("(null)"));

	while (str[index] != '\0')
	{
		if (str[index] > 0 && (str[index] < 32 || str[index] >= 127))
		{
			_put("\\x");
			strlen = strlen + 2;
			convert = change_base(str[index], 16, 0);
			if (!convert[1])
				strlen += _putchar('0');

			strlen += _put(convert);
		}
		else
			strlen += _putchar(str[index]);

		index++;
	}

	return (strlen);
}
