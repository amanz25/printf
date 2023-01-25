#include "main.h"

/**
 * _pointer_address - display address
 * @args: arguments
 * Return: count of characters to be displayed
 */
int _pointer_address(va_list args)
{
	char *s;
	int strlen = 0;
	unsigned long int arg = va_arg(args, unsigned long int);

	if (!arg)
		return (_put("(nil)"));

	s = change_base(arg, 16, 1);
	strlen += _put("0x");
	strlen += _put(s);

	return (strlen);
}
