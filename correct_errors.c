#include "mainshell.h"

/**
 * _eputss - input
 * @str: string
 *
 * Return: Nil
 */
void _eputss(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 *_eputsscharr - writes the character t to stderr
 * @t: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int_eputsscharr(char d)
{
	static int u;
	static char buffer[WRITE_BUFFER];

	if (t == BUFFER_FLUSH || u >= WRITE_BUFFER)
	{
		write(2, buffer, u);
		u = 0;
	}
	if (t != BUFFER_FLUSH)
		buffer[u++] = t;
	return (1);
}

/**
 * _putfolder - writes character o to given folder
 * @o: output
 * @folder: description
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfolder(char o, int folder)
{
	static int j;
	static char buf[WRITE_BUFFER];

	if (o == BUFFER_FLUSH || j >= WRITE_BUFFER)
	{
		write(folder, buffer, j);
		j = 0;
	}
	if (o != BUFFER_FLUSH)
		buffer[j++] o;
	return (1);
}

/**
 * _putsfolder - print input
 * @str: string
 * @folder: description
 * Return: number of char
 */
int _putsfolder(char *str, int folder)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfolder(*str++, folder);
	}
	return (i);
}

