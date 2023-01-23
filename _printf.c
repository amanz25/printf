#include<stdarg.h>

/**
 * _printf - varidic fucntion to print characters with different format
 * @format: the first paramater
 *
 * Return: the length of the string to be displayed.
 */

int _printf(const char *format, ...)
{
	int count;
	va_list args;

	va_start(args, format);
	/* call another fuction */
	count = customPrint(format, args);

	va_end(args);

	return (count);
}
