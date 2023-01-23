#include<stdarg.h>
#include "main.h"

/**
 * conditions - function check the format
 * @format: string for the first param
 * @args: macro to track args
 *
 * Return: void.
 */
void conditions(const char *format, va_list args)
{
	char getCharacter;
	const char *getString;
	int num, i;

	if (*format == 'c')
	{
		getCharacter = va_arg(args, int);
		_putchar(getCharacter);
	}
	else if (*format == 's')
	{
		getString = va_arg(args, const char *);
		for (i = 0; getString[i] != '\0'; i++)
			_putchar(getString[i]);
	}
	else if (*format == 'd')
	{
		char buff[buffsize];

		i = 0;
		num = va_arg(args, int);
		number_to_string(num, 10, buff);
		while (buff[i])
		{
			_putchar(buff[i]);
			i++;
		}
	}
}


/**
 * customPrint - function print based on arg passed
 * @format: string for the first param
 * @args: macro to track args
 *
 * Return: the count of characters in format
 */
int customPrint(const char *format, va_list args)
{
	int percentFound = 0;
	int count = 0;

	while (*format)
	{
		if (percentFound == 0)
		{
			if (*format == '%')
				percentFound = 1;
			else
			{
				_putchar(*format);
				count++;
			}
	}
	else
	{
		conditions(format, args);
		percentFound = 0;
	}

		format++;
	}

	return (count);
}
