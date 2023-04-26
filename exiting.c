#include "mainshell.h"

/**
 **_strncpy - copies a string
 *@dest: destination
 *@src: source
 *@v: num of xters
 *Return: concat str
 */
char *_strncpy(char *dest, char *src, int v)
{
	int t, d;
	char *p = dest;

	t = 0;
	while (src[t] != '\0' && t < v - 1)
	{
		dest[t] = src[t];
		t++;
	}
	if (t < v)
	{
		d = t;
		while (d < v)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (p);
}

/**
 **_strncat - concatenates two strings
 *@dest: destination
 *@src: source
 *@v: the number of bytes
 *Return: str concat
 */
char *_strncat(char *dest, char *src, int v)
{
	int p, b;
	char *r = dest;

	p = 0;
	b = 0;
	while (dest[p] != '\0')
		p++;
	while (src[b] != '\0' && b < v)
	{
		dest[p] = src[b];
		p++;
		b++;
	}
	if (b < v)
		dest[p] = '\0';
	return (r);
}

/**
 **_strchr - locates a character in a string
 *@o: string
 *@d: character
 *Return: pointer to o
 */
char *_strchr(char *o, char d)
{
	do {
		if (*o == d)
			return (o);
	} while (*o++ != '\0');

	return (NULL);
}

