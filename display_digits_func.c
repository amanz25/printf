#include "main.h"

/**
 * _int - prints digit/integer.
 * @ap: argument track list
 * @t: pointer to track + # and space
 * Return: count of digit/integer to be displayed
 */

int _int(va_list ap, T_flag *t)
{
	int num = va_arg(ap, int);
	int count = digit_len(num);

	if (t->spaceSign == 1 && t->plusSign == 0 && num >= 0)
		count += _putchar(' ');
	if (t->plusSign == 1 && num >= 0)
		count += _putchar('+');

	if (num <= 0)
		count++;

	display_num_recur(num);
	return (count);
}

/**
 * _unsigned - print unsigned or +ve num in base 10
 * @arg: current traversed argument.
 * @t: pointer to track + # and space
 *
 * Return: number in hexadecimal form.
 */
int _unsigned(va_list arg, T_flag *t)
{
	unsigned int num = va_arg(arg, unsigned int);
	char *s = change_base(num, 10, 0);
	int count = 0;

	(void)t;
	count += _put(s);
	return (count);
}

/**
 * digit_len - get the length of digit
 * @num: number to be checked
 *
 * Return: count of digit
 */
int digit_len(int num)
{
	int count;

	if (num < 0)
		num = -num;

	for (count = 0; num != 0; count++)
		num = num / 10;

	return (count);
}

/**
 * display_num_recur - print numbers
 * @num: the number to be printed
 *
 * Return: void
 */
void display_num_recur(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -1 * n;
	}

	if(n / 10)
		display_num_recur(n / 10);

	_putchar('0' + (n % 10));
}
