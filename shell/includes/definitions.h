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
# define DEFAULT_TERM	"xterm-256color"
# define CONFIG_FILE	"config"
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
# define KEYENTER		10
# define KEYTAB			9
# define KEYESC			27
# define KEYBS			127
# define SHKEYLEFT		30078481936964
# define SHKEYRIGHT		30078481936963
# define SHKEYUP		30078481936961
# define SHKEYDOWN		30078481936962
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

typedef struct			s_coordinate
{
	short				x;
	short				y;
}						t_coordinate;

typedef struct			s_buffer
{
	char				data[LINE_MAX];
	size_t				id;
	struct s_buffer		*prev;
	struct s_buffer		*next;
}						t_bufflist;

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

typedef	struct			s_reader
{
	t_bufflist			*history;
	t_bufflist			*buffptr;
	t_bufflist			*buffend;
	t_bufflist			*aucmplt;
	t_bufflist			*aucmplt_ptr;
	char				buffer[LINE_MAX];
	char				*esc[TOTAL];
	size_t				il;
	size_t				ic;
	t_coordinate		crs;
}						t_reader;

typedef struct			s_cmplt
{
	char				*line;
	char				*option_first;
	char				*option_current;
	char				*option_next;
	char				*option_last;
	int					fd;
	size_t				total_options;
}						t_cmplt;

typedef struct			s_shell
{
	t_settings			settings;
	t_reader			rd;
	char				**env;
	char				**exec_paths;
	size_t				flags;
}						t_shell;

#endif
