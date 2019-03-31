#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# include "libft.h"
# include "ft_printf.h"
# include <limits.h>
# include <termios.h>
# include <termcap.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <pwd.h>
# include <fcntl.h>

# define TERM_ACTION(x)	tputs(sh->rd.esc[x], fileno(stdin), ft_putchar)	
/*
 ************DEFAULT_SETTINGS****************************** 
 */
# define HISTORY_FILE	".shell_history"
# define DEFAULT_TERM	"xterm-256color"
# define CONFIG_FILE	".shellrc"
# define HISTORY_SIZE	1000
/*
 ************KEYMAP**************************************** 
 */

# define KEYUP			1792833
# define KEYDOWN		1792834
# define KEYRIGHT		1792835
# define KEYLEFT		1792836
# define KEYDEL			458961790
# define KEYHOME		1792840
# define KEYEND			1792838
# define KEYENTER		13
# define KEYTAB			9
# define KEYESC			27
# define KEYBS			127
/*
 **************FLAGS****************************************
 */
# define READING		1
/*
 *************ACCES FLAGS**********************************
 */
# define FILE_EXISTS	0
# define FILE_EXEC		1
# define FILE_WR		2
# define FILE_RD		3
# define FILE_RDWR		4

/* 
 * Termcap options, that i've found necessary.
 * Arranged as enum, so they could easily be allocated in stack.
 */

enum					s_options
{
	RIGHT,
	LEFT,
	UPB,
	DOWN,
	DEL,
	CLR,
	SAVEC,
	RSRC,
	CD,
	TOTAL
};

/*
 * struct s_coordinate to track the position of cursor
 */

typedef struct			s_coordinate
{
	short				x;
	short				y;
}						t_coordinate;

/*
 * some settings that we'll try to read from .shellrc file, if dont't, 
 * we're gona use default values. 
 */

typedef struct			s_settings
{
	struct termios		term_default;
	struct termios		term_shell;
	t_coordinate		window_size;
	char				promt[LINE_MAX];
	size_t				history_buffsize;
	size_t				promt_len;
	uid_t				uid;
}						t_settings;

/*
 * s_reader struct includes everything we need to read/store input,
 * move_cursor on the screen and track it's position.
 *
 * Some explanations:
 * esc - an array of termcap escape sequences
 * il - input length
 * ic - input current, the position of a cursor on the text line
 * hc - history buffer current line, that we deal with
 * hm - history buffer lines that are allready in use
 * crs - position of cursor in the terminal window
 */

typedef	struct			s_reader
{
	char				buffer[LINE_MAX];
	char				**history;
	char				*esc[TOTAL];
	size_t				il;
	size_t				ic;
	size_t				hc;
	size_t				hm;
	t_coordinate		crs;
}						t_reader;

/*
 * The main shell data type.
 */

typedef struct			s_shell
{
	t_settings			settings;
	t_reader			rd;
	char				**env;
	char				**exec_paths;
	size_t				flags;
}						t_shell;

#endif
