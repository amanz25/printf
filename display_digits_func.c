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

