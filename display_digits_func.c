#include "main.h"

/**
 * _int - prints digit/integer.
 * @ap: argument track list
 * Return: count of digit/integer to be displayed
 */

int _int(va_list ap)
{

unsigned int consequent = 1, i, quotient, count = 0;
int num = va_arg(ap, int);

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
 *
 * Return: number in hexadecimal form.
 */
int _unsigned(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	char *s = change_base(num, 10, 0);
	int count = 0;

	count += _put(s);
	return (count);
}
