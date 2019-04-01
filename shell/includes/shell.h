/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anton <anton@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:16:33 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/01 21:34:11 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "definitions.h"

/*
 **********************SHELL************************************************************* 
 */
void				shell_open(t_shell *sh);
void				shell_close(t_shell *sh, int exit_code);
/*
*********************READER**************************************************************
*/
void				shell_read_input(t_shell *sh, t_reader *rd);
void				shell_insert_char(t_shell *sh, t_reader *rd, char c);
int					shell_parse_events(t_shell *sh, t_reader *rd, char *key);
void				shell_create_history_list(t_shell *sh, t_reader *rd);
void				shell_scroll_history(t_shell *sh, t_reader *rd, int keycode);
void				shell_autocomplete(t_shell *sh, t_reader *rd);
/*
 ********************CURSOR MOTION******************************************************* 
 */
void				shell_mvcl(t_shell *sh, t_reader *rd);
void				shell_mvcr(t_shell *sh, t_reader *rd);
void				shell_mvch(t_shell *sh, t_reader *rd);
void				shell_mvce(t_shell *sh, t_reader *rd);
/*
 ********************LEXER***************************************************************
 */
void				shell_expand_string(t_shell *sh, char *string);
void				shell_delete_chars_from_string(char *str, char *dlt);
void				shell_parse_input(t_shell *sh, t_reader *rd);
/*
 *********************HELPERS************************************************************
 */
void				shell_get_next_line(t_shell *sh, int fd);
void				shell_read_config_file(t_shell *sh);
void				shell_get_promt(t_settings *settings);
char				*shell_get_value(char **array, char *var);
void				shell_get_window_size(t_coordinate *window_size);
void				shell_print_promt(t_shell *sh);
void				shell_count_promt_len(t_settings *settings, char *promt);
void				shell_delete_char(t_shell *sh, t_reader *rd, int key);
/*
 **********************CURSOR MOTION*****************************************************
 */
/*
 **********************HISTORY************************************************************
 */


#endif
