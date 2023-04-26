#include "mainshell.h"
/**
 * _isalpha - confirms alphabet
 * @m: input
 * Return: 1 if true, else 0
 */

int _isalpha(int m)
{
	if ((m >= 'a' && m <= 'z') || (m >= 'A' && m <= 'Z'))
		return (1);
	else
		return (0);
}
