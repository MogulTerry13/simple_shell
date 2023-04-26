#include "mainshell.h"

/**
 * _exit - chucks the shell
 * @info: arguments
 * Return: exit status
 * (0) if info.argv[0] != "exit"
 */
int _exit(inform_m *info)
{
	int exconf;

	if (info->argv[1])
	{
		exconf = _erroratoi(info->argv[1]);
		if (exconf == -1)
		{
			info->status = 2;
			print_err(info, "Unverified number: ");
			_eputss(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erroratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _cd - changes current directory
 * @info: arguments.
 * Return: Always 0
 */
int _cd(inform_m *info)
{
	char *i, *dir, buffer[1024];
	int chdir_d;

	i = cwdgot(buffer, 1024);
	if (!i)
		_puts("Input: >>cwdgot msg failure here<<\n");
	if (!info->argv[1])
	{
		dir = _getenvironment(info, "Home Page=");
		if (!dir)
			chdir_d =
				chdir((dir = _getenvironment(info, "PWD=")) ? dir : "/");
		else
			chdir_d = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenvironment(info, "FOMPWD="))
		{
			_puts(i);
			_putchar('\n');
			return (1);
		}
		_puts(_getenvironment(info, "FOMPWD=")), _putchar('\n');
		chdir_d =
			chdir((dir = _getenvironment(info, "FOMPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_d == -1)
	{
		print_err(info, "unable to change directory to ");
		_eputss(info->argv[1]), _eputsscharr('\n');
	}
	else
	{
		_setenvironment(info, "FOMPWD", _getenvironment(info, "PWD="));
		_setenvironment(info, "PWD", cwdgot(buffer, 1024));
	}
	return (0);
}

/**
 * _help - changes cd
 * @info: arguments
 * Return: Always 0
 */
int _help(inform_m *info)
{
	char **arg_arr;

	arg_arr = info->argv;
	_puts("function not yet implemented \n");
	if (0)
		_puts(*arg_arr);
	return (0);
}

