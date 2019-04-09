/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anton <anton@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:16:33 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/09 21:48:24 by gscolera         ###   ########.fr       */
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
void				shell_parse_events(t_shell *sh, t_reader *rd, char *buff);
void				shell_create_history_list(t_shell *sh, t_reader *rd);
void				shell_scroll_history(t_shell *sh, t_reader *rd, int keycode);
/*
 ********************AUTOCOMPLETE******************************************************** 
 */
void				shell_autocomplete(t_shell *sh, t_reader *rd);
void				shell_arg_srch(t_shell *sh, t_reader *rd, t_cmplt *list);
void				shell_cmd_srch(t_shell *sh, t_reader *rd, t_cmplt *list);
/*
 ********************CURSOR MOTION******************************************************* 
 */
void				shell_mvcl(t_shell *sh, t_reader *rd);
void				shell_mvcr(t_shell *sh, t_reader *rd);
void				shell_mvch(t_shell *sh, t_reader *rd);
void				shell_mvce(t_shell *sh, t_reader *rd);
void				shell_mvcnpw(t_shell *sh, t_reader *rd, long int key);
void				shell_mvcnpl(t_shell *sh, t_reader *rd, long int key);
/*
 ********************LEXER***************************************************************
 */
void				shell_manage_input(t_shell *sh);
void				shell_manage_quote(t_shell *sh, char *string, int i);
char				*shell_expand_string(t_shell *sh, char *string);
char				*shell_expand_variable(t_shell *sh, char *string, int i);
char				*shell_expand_home(t_shell *sh, char *string, int i);
void				shell_split_input(t_shell *sh, char *input);
void				shell_split_commands(t_shell *sh, t_command *cmd_list);
/*
 ********************EXECUTER************************************************************
 */
void				shell_execute(t_shell *sh);
void				shell_find_binary(t_shell *sh, char **argv);
void				shell_run_binary(t_shell *sh);
void				shell_setenv(t_shell *sh, char **argv);
void				shell_unsetenv(t_shell *sh, char **argv);
/*
 *********************HELPERS************************************************************
 */
void				shell_get_next_line(t_shell *sh, int fd);
void				shell_read_config_file(t_shell *sh);
void				shell_get_promt(t_settings *settings);
char				*shell_getenv(char **array, char *var, int len);
void				shell_get_window_size(t_coordinate *window_size);
void				shell_print_promt(t_shell *sh);
void				shell_count_promt_len(t_settings *settings, char *promt);
void				shell_delete_char(t_shell *sh, t_reader *rd, int key);
void				shell_delete_characters(char *string, char *dlt);
void				shell_switch_flag(t_shell *sh, int flag);

#endif
