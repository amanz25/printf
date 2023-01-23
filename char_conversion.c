#include "main.h"
#include <stdlib.h>

/**
 * alpha_numeric_conversion - convert digits to char
 * @number: digit or number
 * @upp: upper case check
 * Return: converted value
 */
int alpha_numeric_conversion(int number, int upp)
{
	if (number >= 10)
		return (number - 10 + ((upp) ? 'A' : 'a'));
	else
		return (number + '0');
}

/**
 * base_conversion - convert unsigned from base 10 to base
 * @number: decimal number
 * @base: base to convert from
 * @upp: upper case check
 * Return: converted number to string
 */
char *base_conversion(unsigned long number, unsigned int base, int upp)
{
	int i = 0;
	char *str;
	unsigned long nbr = number;

	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	str = malloc(sizeof(char) * i + 2);
	if (!str)
		return (0);
	str[i + 1] = '\0';

	while (i >= 0)
	{
		nbr = number % base;
		str[i] = alpha_numeric_conversion(nbr, upp);
		number /= base;
		i--;
	}
	return (str);
}

/**
 * pointer_conversion - convert pointer void to ul
 * @ptr: pointer
 * Return: converted string
 */
char *pointer_conversion(unsigned long ptr)
{
	unsigned long adress;
	char *str;

	adress = ptr;
	if (adress == 0)
		return ("0");
	str = base_conversion(adress, 16, 0);
	return (str);
}

/**
 * new_string - encode using rot13
 * @str: string to encode
 * Return: encoded string
 */
char *new_string(char *str)
{
	int i = 0;
	char *s;
	int size = len_recursion(str);

	s = malloc(sizeof(char) * size + 1);
	if (!s)
		return (0);

	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
			s[i] = str[i] + 13;
		else if ((str[i] >= 'n' && str[i] <= 'z')
				|| (str[i] >= 'N' && str[i] <= 'Z'))
			s[i] = str[i] - 13;
		else
			s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
