#include "main.h"

/**
 * change_base - change number to other base
 * @number: number
 * @base: base for the response.
 * @ishexalower: for hexa decimal values.
 * Return: string.
 */
char *change_base(unsigned long int number, int base, int ishexalower)
{
	static char *poss;
	static char buffer[BUFF_SIZE];
	char *ptr;

	if (ishexalower)
		poss = "0123456789abcdef";
	else
		poss = "0123456789ABCDEF";

	ptr = &buffer[BUFF_SIZE - 1];
	*ptr = '\0';

	/* for 0 */
	*--ptr = poss[number % base];
	number = number / base;

	while (number != 0)
	{
		*--ptr = poss[number % base];
		number = number / base;
	}

	return (ptr);
}


/**
 * _binary - change num to binary or base 2
 * @arg: current traversed argument.
 * @t: pointer to track + # and space
 *
 * Return: number in binary form.
 */
int _binary(va_list arg, T_flag *t)
{
	unsigned int current_Arg = va_arg(arg, unsigned int);
	char *s = change_base(current_Arg, 2, 0);

	(void)t;
	return (_put(s));
}

/**
 * _octal - change num to octal or base 8
 * @arg: current traversed argument.
 * @t: pointer to track + # and space
 *
 * Return: number in octal form.
 */
int _octal(va_list arg, T_flag *t)
{
	unsigned int num = va_arg(arg, unsigned int);
	char *s = change_base(num, 8, 0);
	int count = 0;

	if (t->hashSign == 1 && s[0] != '0')
		count += _putchar('0');

	count += _put(s);
	return (count);
}

/**
 * _hexadecimal - change num to octal or base 16 with lowercase letter if > 9
 * @arg: current traversed argument.
 * @t: pointer to track + # and space
 *
 * Return: number in hexadecimal form.
 */
int _hexadecimal(va_list arg, T_flag *t)
{
	unsigned int num = va_arg(arg, unsigned int);
	char *s = change_base(num, 16, 1);
	int count = 0;

	if (t->hashSign == 1 && s[0] != '0')
		count += _put("0x");

	count += _put(s);
	return (count);
}

/**
 * _hexadecimal_UPP - change num to hex or base 16 with upper letter if > 9
 * @arg: current traversed argument.
 * @t: pointer to track + # and space
 *
 * Return: number in hexadecimal form.
 */
int _hexadecimal_UPP(va_list arg, T_flag *t)
{
	unsigned int num = va_arg(arg, unsigned int);
	char *s = change_base(num, 16, 0);
	int count = 0;

	if (t->hashSign == 1 && s[0] != '0')
		count += _put("0x");

	count += _put(s);
	return (count);
}
