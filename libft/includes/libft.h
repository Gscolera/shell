/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:21:15 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:46:00 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <fcntl.h>

# define GNL_BUFF_SIZE 100

typedef struct	s_file
{
	char				*data;
	int					fd;
	int					ret;
	struct s_file		*next;
}				t_file;

int				get_next_line(const int fd, char **line);


/*
******************************MEMORY****************************************
*/
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
/*
 ****************************STRINGS****************************************
*/
char			**strings_allocate(size_t size);
void			free_strings(char **string);
void			print_strings(char **str);
size_t			count_strings(char **strings);
char			**copy_strings(char **strings);
bool			string_add(char ***string, char *str);
char			*string_search(char **string, char *srhc);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t len);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
	size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_pathcat(char *dir, char *name);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_insert_char(char *string, char c, size_t position);
void			ft_delete_char(char *string, size_t pos);
void			ft_replace_substr(char *string, size_t p, size_t s, char *new);
/*
*****************************PUTS**********************************************
*/
int				ft_putchar(int c);
void			ft_putstr(char *str);
void			ft_putendl(char *str);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
bool			ft_perror(char *cmd, char *error);
/*
*****************************OTHER*********************************************
*/
int				ft_atoi(const char *str);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_itoa(int n);
char			ft_getchar(int fd);

#endif
