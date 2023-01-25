#include "main.h"

/**
 * change_base - change number to other base
 * @number: number
 * @base: base for the response.
 * @ishexalower: for hexa decimal values.
 * Return: string.
 */
char *change_base(unsigned int number, int base, int ishexalower)
{
	static char *poss;
	static char buffer[BUFF_SIZE];
	char *ptr;

	if (ishexalower)
		poss = "0123456789abcdef";
	else
		poss =  "0123456789ABCDEF";

	ptr = &buffer[BUFF_SIZE - 1];
	*ptr = '\0';
	if (number == 0)
	{
		*--ptr = poss[0];
		number = number / base;
	}
	while (number != 0)
	{
		*--ptr = poss[number % base];
		number = number / base;
	}
	return (ptr);
}


/**
 * _binary - return a number in binary base.
 * @arg: current traversed argument.
 *
 * Return: number in binary form.
 */
int _binary(va_list arg)
{
	unsigned int current_Arg = va_arg(arg, unsigned int);
	char *s = change_base(current_Arg, 2, 0);

	return (_put(s));
}

