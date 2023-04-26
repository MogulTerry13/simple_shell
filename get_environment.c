#include "mainshell.h"

/**
 * for_environment - array environ
 * @info: arguments
 * Return: Always 0
 */
char **for_environment(inform_m *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = ls_str(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenvironment - Remove an environment variable
 * @info: arguments
 *  Return: 1 on delete, 0 otherwise
 * @var: string env var
 */
int _unsetenvironment(inform_m *info, char *var)
{
	list_p *node = info->env;
	size_f m = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = for_start(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = del_node_index(&(info->env), m);
			m = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		m++;
	}
	return (info->env_changed);
}

/**
 * _setenvironment - Initialize a new environment
 * @info: arguments
 * @var: string env var
 * @value: the string env var value
 *  Return: Always 0
 */
int _setenvironment(inform_m *info, char *var, char *value)
{
	char *buffer = NULL;
	list_p *nd;
	char *p;

	if (!var || !value)
		return (0);

	buffer = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, var);
	_strcat(buffer, "=");
	_strcat(buffer, value);
	node = info->env;
	while (nd)
	{
		p = for_start(nd->str, var);
		if (p && *p == '=')
		{
			free(nd->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		nd = nd->next;
	}
	plus_node_end(&(info->env), buffer, 0);
	free(buffer);
	info->env_changed = 1;
	return (0);
}

