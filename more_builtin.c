#include "mainshell.h"

/**
 * _myhx - history list, one command by line
 * @info: arguments
 *  Return: Always 0
 */
int _myhx(inform_m *info)
{
	print_list(info->history);
	return (0);
}

/**
 * remove_aka - sets alt name
 * @info: parameter
 * @str: string
 *
 * Return: Always 0
 */
int remove_aka(inform_m *info, char *str)
{
	char *k, b;
	int output;

	k = _strchr(str, '=');
	if (!k)
		return (1);
	b = *k;
	*k = 0;
	output = del_node_index(&(info->aka),
		for_index_node(info->aka, star_node(info->aka, str, -1)));
	*p = b;
	return (output);
}

/**
 * set_aka - sets alt name
 * @info: input
 * @str: string
 *
 * Return: Always 0
 */
int set_aka(inform_m *info, char *str)
{
	char *j;

	j = _strchr(str, '=');
	if (!j)
		return (1);
	if (!*++j)
		return (remove_aka(info, str));

	remove_aka(info, str);
	return (plus_node_end(&(info->aka), str, 0) == NULL);
}

/**
 * print_aka - prints alt name
 * @node: the alt name
 *
 * Return: Always 0
 */
int print_aka(list_p *node)
{
	char *h = NULL, *n = NULL;

	if (node)
	{
		h = _strchr(node->str, '=');
		for (n = node->str; n <= h; n++)
		_putchar(*n);
		_putchar('\'');
		_puts(h + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myaka - copies alt name
 * @info: arguments
 *  Return: Always 0
 */
int _myaka(inform_m *info)
{
	int r = 0;
	char *k = NULL;
	list_p *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_aka(node);
			node = node->next;
		}
		return (0);
	}
	for (r = 1; info->argv[r]; r++)
	{
		k = _strchr(info->argv[r], '=');
		if (k)
			set_aka(info, info->argv[r]);
		else
			print_aka(star_node(info->alias, info->argv[r], '='));
	}

	return (0);
}

