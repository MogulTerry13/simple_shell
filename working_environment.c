#include "mainshell.h"

/**
 * _pers_environment - prints current environment
 * @info: arguments
 * Return: Always 0
 */
int _pers_environment(inform_m *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenvironment - gets val of environ
 * @info: argument
 * @name_env: input
 * Return: the value
 */
char *_getenvironment(inform_m *info, const char *name_env)
{
	list_p *node = info->env;
	char *p;

	while (node)
	{
		p = for_start(node->str, name_env);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _perssetenvironment - start new environment
 * @info: arguments
 *  Return: Always 0
 */
int _perssetenvironment(inform_m *info)
{
	if (info->argc != 3)
	{
		_eputss("Not true no. of arg\n");
		return (1);
	}
	if (_setenvironment(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _persunsetenvironment - Removes an environment var
 * @info: argument
 * Return: Always 0
 */
int _persunsetenvironment(inform_m *info)
{
	int l;

	if (info->argc == 1)
	{
		_eputss("Not enough arguements.\n");
		return (1);
	}
	for (l = 1; l <= info->argc; l++)
		_unsetenvironment(info, info->argv[l]);

	return (0);
}

/**
 * fill_environment_list - fills env list
 * @info: arguments
 * Return: Always 0
 */
int fill_environment_list(inform_m *info)
{
	list_p *node = NULL;
	size_f b;

	for (b = 0; environ[b]; b++)
		plus_node_end(&node, environ[b], 0);
	info->env = node;
	return (0);
}

