#include<stdarg.h>
#include <main.h>

/**
 * customPrint - function print based on arg passed
 * @format: string for the first param
 * @args: macro to track args
 *
 * Return: the count of characters in format
 */
int customPrint(const char *format, va_list args)
{
	char getCharacter;
	const char *getString;
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
		if (*format == 'c')
		{
			getCharacter = va_arg(args, int);
			_putchar (getCharacter);
		}
		else if (*format == 's')
		{
			int i;

			getString = va_arg(args, const char *);
			for (i = 0 ; getString[i] != '\0'; i++)
				_putchar (getString[i]);
		}

		percentFound = 0;
	}

		format++;
	}

	return (count);
}
