#include "mainshell.h"

/**
 * _erroratoi - converts string to integer
 * @s: input
 * Return: 0 if no numbers in string, -1 on error
 */
int _erroratoi(char *s)
{
	int i = 0;
	unsigned long int output = 0;

	if (*s == '+')
		s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			output *= 10;
			output += (s[i] - '0');
			if (output > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (output);
}

/**
 * print_err - error message
 * @info: parameter
 * @strerr: error
 * Return: 0 if no numbers, -1 on error
 */
void print_err(inform_m *info, char *strerr)
{
	_eputss(info->fname);
	_eputss(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputss(": ");
	_eputss(info->argv[0]);
	_eputss(": ");
	_eputss(strerr);
}

/**
 * print_d - decimal
 * @input: input
 * @folder: explanation
 * Return: output
 */
int print_d(int input, int folder)
{
	int (*__putchar)(char) = _putchar;
	int j, num = 0;
	unsigned int _abs_, present;

	if (folder == STDERR_FILENO)
		__putchar = _eputsscharr;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		num++;
	}
	else
		_abs_ = input;
	present = _abs_;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_abs_ / j)
		{
			__putchar('0' + present / j);
			num++;
		}
		present %= j;
	}
	__putchar('0' + present);
	num++;

	return (num);
}

/**
 * change_num - changes alpha to int
 * @num: number
 * @base: base
 * @notes: arguments
 *
 * Return: string
 */
char *change_num(long int num, int base, int notes)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(notes & CHANGE_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = notes & CHANGE_TO_LOWER ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * erase_comment - replaces #
 * @buffer: address
 *
 * Return: Always 0;
 */
void erase_comment(char *buffer)
{
	int h;

	for (h = 0; buffer[h] != '\0'; h++)
		if (buffer[h] == '#' && (!i || buffer[h - 1] == ' '))
		{
			buffer[h] = '\0';
			break;
		}
}

