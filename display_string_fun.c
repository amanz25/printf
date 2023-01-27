#include "main.h"

/**
 * _char - a function to print character
 * @ap: argument list
 * @t: pointer to track + # and space
 *
 * Return: printed character
 */
int _char(va_list ap, T_flag *t)
{
	(void)t;
	_putchar(va_arg(ap, int));
	return (1);
}

/**
 * _string - to print a string
 * @ap: argument list
 * @t: pointer to track + # and space
 *
 * Return: printed string
 */
int _string(va_list ap, T_flag *t)
{
	char *str = va_arg(ap, char *);

	(void)t;
	if (!str)
		str = "(null)";

	return (_put(str));
}
/**
 * _percent -  to print percent character
 * @args: argumet list
 * @t: pointer to track + # and space
 *
 * Return: percent character
 */
int _percent(va_list args, T_flag *t)
{
	(void)t;
	(void)args;
	return (_putchar('%'));
}
/**
 * _customstring - print string
 * @args: argumet list
 * @t: pointer to track + # and space
 *
 * Return: count of string
 */
int _customstring(va_list args, T_flag *t)
{
	char *str = va_arg(args, char *);
	char *convert;
	int index = 0;
	int strlen = 0;

	(void)t;
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

/**
 * _reverse - reverse the string
 * @args: argumet list
 * @t: pointer to track + # and space
 *
 * Return: count of string
 */
int _reverse(va_list args, T_flag *t)
{
	int strlen, count;
	char *str = va_arg(args, char *);

	(void)t;
	if (str == NULL)
		str = "(null)";

	for (strlen = 0; str[strlen]; strlen++)
		;

	count = strlen - 1;

	while (count >= 0)
	{
		_putchar(str[count]);
		count--;
	}

	return (strlen);
}
