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

	(void)t;
	return (_put(s));
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
	unsigned int posNum;

	if (num < 0)
		posNum = -num;
	else
		posNum = num;

	for (count = 0; posNum != 0; count++)
		posNum = posNum / 10;

	return (count);
}

/**
 * display_num_recur - print numbers
 * @n: the number to be printed
 *
 * Return: void
 */
void display_num_recur(int n)
{
	unsigned int posNum;

	if (n < 0)
	{
		_putchar('-');
		posNum = -1 * n;
	}
	else
		posNum = n;

	if (posNum / 10)
		display_num_recur(posNum / 10);

	_putchar('0' + (posNum % 10));
}
