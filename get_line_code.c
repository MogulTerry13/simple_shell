#include "mainshell.h"

/**
 * input_buf - commands
 * @info: parameter struct
 * @buffer: address of buffer
 * @len: address of len
 *
 * Return: bytes read
 */
ssize_f input_buffer(inform_m *info, char **buffer, size_f *len)
{
	ssize_f t = 0;
	size_f len_p = 0;

	if (!*len)
	{
		/*brfree((void **)info->cmd_buf);*/
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, loginuser);

		t = g_line(buffer, &len_p, stdin);

		t = _get_line_for(info, buffer, &len_p);

		if (t > 0)
		{
			if ((*buffer)[t - 1] == '\n')
			{
				(*buffer)[t - 1] = '\0';
				t--;
			}
			info->linecount_flag = 1;
			erase_comment(*buffer);
			form_fx_list(info, *buffer, info->h_count++);
			{
				*len = t;
				info->cmd_buf = buffer;
			}
		}
	}
	return (t);
}

/**
 * gt_inputt - gets a liine
 * @info: parameter
 *
 * Return: bytes read
 */
gt_inputt(inform_m *info)
{
	static char *buffer;
	static size_f i, j, len;
	ssize_f r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUFFER_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buffer + i;

		confirm_chn(info, buffer, &j, i, len);
		while (j < len)
		{
			if (for_chn(info, buffer, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buffer;
	return (r);
}

/**
 * read_buf - reads a buffer
 * @info: parameter
 * @buffer: buffer
 * @d: size
 *
 * Return: o
 */
ssize_f read_buf(inform_m *info, char *buffer, size_f *d)
{
	ssize_f o = 0;

	if (*d)
		return (0);
	o = read(info->readfold, buffer, READ_BUFFER);
	if (o >= 0)
		*d = o;
	return (o);
}

/**
 * _get_line_for - gets the next line of input from STDIN
 * @info: parameter
 * @ptr: address of ptr
 * @length: size
 *
 * Return: y
 */
int _get_line_for(inform_m *info, char **ptr, size_f *length)
{
	static char buf[READ_BUFFER];
	static size_f i, len;
	size_f k;
	ssize_f r = 0, y = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		y = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buffer, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buffer + i, '\n');
	k = c ? 1 + (unsigned int)(c - buffer) : len;
	pre_n = _realloc(p, s, s ? s + k : k + 1);
	if (!pre_n)
		return (n ? free(n), -1 : -1);

	if (y)
		_strncat(pre_n, buffer + i, k - i);
	else
		_strncpy(pre_n, buffer + i, k - i + 1);

	y += k - i;
	i = k;
	n = pre_n;

	if (length)
		*length = y;
	*ptr = n;
	return (y);
}

/**
 * loginuser - blocks
 * @sig_num: the signal number
 *
 * Return: void
 */
void loginuser(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUFFER_FLUSH);
}

