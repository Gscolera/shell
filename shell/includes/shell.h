/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anton <anton@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:16:33 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/14 19:09:46 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "definitions.h"

/*
 **********************SHELL***************************************************
*/
void				shell_open(t_shell *sh);
void				shell_close(t_shell *sh, int exit_code);
/*
*********************READER****************************************************
*/
void				shell_read_input(t_shell *sh, t_reader *rd);
void				shell_confirm_input(t_shell *sh, t_reader *rd);
void				shell_insert_char(t_shell *sh, t_reader *rd, char c);
void				shell_parse_events(t_shell *sh, t_reader *rd, char *buff);
void				shell_create_history_list(t_shell *sh, t_reader *rd);
void				shell_scroll_history(t_shell *sh, t_reader *rd, int key);
void				shell_bck_i_search(t_shell *sh, t_reader *rd);
/*
 ********************AUTOCOMPLETE**********************************************
*/
void				shell_autocomplete(t_shell *sh);
void				shell_search_for_argument(t_shell *sh);
void				shell_search_for_command(t_shell *sh);
void				shell_search_for_options(t_shell *sh, DIR *dir);
void				shell_insert_option(t_shell *sh, t_cmplt *new_list);
void				shell_choose_option(t_shell *sh, t_cmplt *list);
void				shell_check_options(t_shell *sh, t_cmplt *list);
void				shell_accept_option(t_shell *sh, t_cmplt *list);
void				shell_search_builtin(t_shell *sh);
void				shell_close_autocomplete(t_shell *sh);
/*
 ********************CURSOR MOTION*********************************************
*/
void				shell_mvcl(t_shell *sh, t_reader *rd);
void				shell_mvcr(t_shell *sh, t_reader *rd);
void				shell_mvch(t_shell *sh, t_reader *rd);
void				shell_mvce(t_shell *sh, t_reader *rd);
void				shell_mvcnpw(t_shell *sh, t_reader *rd, long int key);
void				shell_mvcnpl(t_shell *sh, t_reader *rd, long int key);
void				shell_mvcd(t_shell *sh, t_reader *rd);
/*
 ********************LEXER*****************************************************
*/
void				shell_manage_input(t_shell *sh);
void				shell_manage_quote(char *string, int i);
char				*shell_expand_string(t_shell *sh, char *string);
char				*shell_expand_variable(t_shell *sh, char *string, size_t i);
char				*shell_expand_home(t_shell *sh, char *string, int i);
void				shell_split_input(t_shell *sh, char *input);
void				shell_split_commands(t_shell *sh, t_command *cmd_list);
/*
 ********************EXECUTER***************************************************
*/
void				shell_execute(t_shell *sh);
void				shell_find_binary(t_shell *sh, char **argv);
void				shell_run_binary(t_shell *sh);
void				shell_setenv(t_shell *sh, char **argv);
void				shell_set_variable(t_shell *sh, char *var, char *value);
void				shell_delete_env(t_shell *sh, char *var);
void				shell_unsetenv(t_shell *sh, char **argv);
void				shell_echo(char **argv);
int					shell_change_dir(t_shell *sh, char **argv);
/*
 *********************HELPERS***************************************************
*/
void				shell_get_next_line(t_shell *sh, int fd);
void				shell_get_cursor_position(t_coordinate *crs);
void				shell_read_config_file(t_shell *sh);
void				shell_get_promt(t_settings *settings);
char				*shell_getenv(char **array, char *var, int len);
void				shell_get_window_size(void);
void				shell_delete_char(t_shell *sh, t_reader *rd, int key);
void				shell_delete_characters(char *string, char *dlt);
void				shell_switch_flag(int flag);
char				*shell_extract_path(char *input);
char				*shell_check_path(t_shell *sh, char *input);
char				*shell_get_current_path(void);
bool				shell_is_path(char *input);
void				shell_signal_init(void);
void				shell_end_of_input(t_shell *sh, t_reader *rd);
void				shell_clear_input(t_shell *sh, t_reader *rd);
bool				shell_check_quotes(char *input);

#endif
