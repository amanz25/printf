#include "main.h"

/**
 * _int - prints digit/integer.
 * @ap: argument track list
 * @t: pointer to track + # and space
 * Return: count of digit/integer to be displayed
 */

int _int(va_list ap, T_flag *t)
{

unsigned int consequent = 1, i, quotient, count = 0;
int num = va_arg(ap, int);

if (t->spaceSign == 1 && t->plusSign == 0 && num >= 0)
	count += _putchar(' ');
if (t->plusSign == 1 && num >= 0)
	count += _putchar('+');

if (num < 0)
{
_putchar('-');
count++;
/* change to positive */
num = num * -1;
}

i = 0;
while ((num / consequent) > 9)
{
i++;
consequent = consequent * 10;
}

while (consequent >= 1)
{
quotient = num / consequent;
_putchar('0' + quotient);

num = num % consequent;
consequent = consequent / 10;
count++;
}

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
