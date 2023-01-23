#include "main.h"

/**
 * unsigned_number_to_string - display positive number
 * @num: the number
 * @base: base of the number
 * @buffer: buffer
 *
 * Return: void.
 */
void unsigned_number_to_string(int num, int base, char *buffer)
{
	int i, current;
	char buff[buffsize];

	if (num == 0)
	{
		*buffer++ = '0';
		*buffer = 0;
		return;
	}
	
	current = 0;
	for (i = 0; i < buffsize; i++)
		buff[i] = 0;
	while (num)
	{
		int modulus;

		modulus	= num % base;
		if (modulus >= 10)
			buff[current++] = 'a' + (modulus - 10);
		else
			buff[current++] = '0' + modulus;

		num = num / base;
	}

	i = current - 1;
	while (i != 0)
	{
		*buffer++ = buff[i];
		i--;
	}
	*buffer++ = buff[0];
	*buffer = 0;
}

/**
 * number_to_string - display number
 * @num: the number
 * @base: base of the number
 * @buffer: buffer
 *
 * Return: void.
 */
void number_to_string(int num, int base, char *buffer)
{
	if (num < 0)
	{
		*buffer++ = '-';
		num = -num;
	}
	unsigned_number_to_string(num, base, buffer);
}

