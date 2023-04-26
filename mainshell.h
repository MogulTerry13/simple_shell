#ifndef _MAINSHELL_H_
#define _MAINSHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>


/* buffers */
#define READ_BUFFER 1024
#define WRITE_BUFFER 1024
#define BUFFER_FLUSH  -1

/* for change_num() */
#define CHANGE_TO_LOWER	1
#define CHANGE_UNSIGNED	2

/* command prompt */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3


/* using system g_line() 1 */
#define FOR_GETLINE 0
#define FOR_STRTOK 0

#define HIST_F	".shell_hx"
#define H_MAX	4096

extern char **env;;


/**
 * struct lsstr - singly linked list
 * @num: num field
 * @str: string
 * @next: next node
 */
typedef struct lsstr
{
	int num;
	char *str;
	struct lsstr *next;
} list_p;

typedef struct pinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_p *env;
	list_p *history;
	list_p *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int read_folder;
	int h_count;
} info_t;

#define INFORM_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - a builtin string
 * @flagtype: the builtin cmd flag
 * @thefunc: function
 */
typedef struct builtin
{
	char *flagtype;
	int (*thefunc)(inform_m*);
} builtin_tbl;


int hsh(inform_m*, char **);
int loc_builtin(inform_m*);
void loc_cmd(inform_m*);
void fork_command(inform_m*);


int for_cmd(inform_m*, char *);
char *duplicate_char(char *, int, int);
char *f_path(inform_m*, char *, char *);

int loopshsh(char **);


void _eputss(char *);
int_eputsscharr(char);
int _putfolder(char d, int folder);
int _putsfolder(char *str, int folder);

int _strlen(char *);
int _strcmp(char *, char *);
char *for_start(const char *, const char *);
char *_strcat(char *, char *);


char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);


char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);


char **strtw(char *, char *);
char **strtw2(char *, char);


char *_memset(char *, char, unsigned int);
void fffree(char **);
void *_realloc(void *, unsigned int, unsigned int);


int brfree(void **);


int connect_user(inform_m*);
int for_delimiter(char, char *);
int _isalpha(int);
int _atoi(char *);


int _erroratoi(char *);
void print_err(inform_m*, char *);
int print_d(int, int);
char *change_num(long int, int, int);
void erase_comment(char *);


int _exit(inform_m*);
int _cd(inform_m*);
int _help(inform_m*);

int _myhx(inform_m*);
int _myaka(inform_m*);


gt_inputt(inform_m*);
int _get_line_for(inform_m*, char **, size_f *);
void loginuser(int);

void erase_information(inform_m*);
void place_information(inform_m*, char **);
void release_information(inform_m*, int);


char *_getenvironment(inform_m*, const char *);
int _pers_environment(inform_m*);
int _perssetenvironment(inform_m*);
int _persunsetenvironment(inform_m*);
int fill_environment_list(inform_m*);


char **for_environment(inform_m*);
int _unsetenvironment(inform_m*, char *);
int _setenvironment(inform_m*, char *, char *);

char *for_hx_file(inform_m*info);
int wr_hx(inform_m*info);
int rd_hx(inform_m*info);
int form_fx_list(inform_m*info, char *buf, int linecount);
int renum_hx(inform_m*info);


list_p *plus_node(list_p **, const char *, int);
list_p *plus_node_end(list_p **, const char *, int);
size_f print_list_str(const list_p *);
int del_node_index(list_p **, unsigned int);
void free_ls(list_p **);


size_f list_len(const list_p *);
char **ls_str(list_p *);
size_f print_list(const list_p *);
list_p *star_node(list_p *, char *, char);
ssize_f for_index_node(list_p *, list_p *);


int for_chn(inform_m*, char *, size_f *);
void confirm_chn(inform_m*, char *, size_f *, size_f, size_f);
int change_aka(inform_m*);
int change_var(inform_m*);
int change_str(char **, char *);

#endif

