#include "mainshell.h"

/**
 * main - entry point
 * @ab: arg count
 * @bd: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ab, char **bd)
{
	inform_m info[] = { INFORM_INIT };
	int folder = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (folder)
			: "r" (folder));

	if (ab == 2)
	{
		folder = open(bd[1], O_RDONLY);
		if (folder == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputss(bd[0]);
				_eputss(": 0: Unable to open ");
				_eputss(bd[1]);
				_eputchar('\n');
				_eputchar(BUFFER_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfold = folder;
	}
	fill_environment_list(info);
	rd_hx(info);
	hsh(info, bd);
	return (EXIT_SUCCESS);
}

