/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:16:35 by bebrandt          #+#    #+#             */
/*   Updated: 2024/05/18 17:40:43 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// PERSONNAL LIB

# include "struct.h"
# include "../libft/includes/libft.h"

// readline lib

#include <readline/readline.h>
#include <readline/history.h>

// binary flags to define a cmd type

enum
{
	REDIRECTION = 1,
	INPUT = 2 ,
	HEREDOC = 4,
	OUTPUT_TRUNCATE = 8,
	OUTPUT_APPEND = 16,
	D_QUOTES = 32,
	S_QUOTES = 64,
	BUILTIN = 128,
	CMD = 256,
	WORD = 512
};

// main/minishell.c

// main/prompt.c

void	prompt(void);

//lexer/lexer.c

void	lexing(t_bash *bash, char *sequence);
void	set_quotes(t_bash *bash, char *sequence, int *i, int *cmd);
void	set_pipe(t_bash *bash, int *i, int *cmd);
void	set_text_token(t_bash *bash, char *sequence, int *i, int *cmd);

//lexer/lexer_cmd.c

int		is_builtin(char *word);

//lexer/lexer_redirections.c

void	set_input_redirection(t_bash *bash, char *sequence, int *i);
void	set_output_redirection(t_bash *bash, char *sequence, int *i);
void	set_token_option(t_bash *bash, t_token *new, char *sequence, int *i);

//lexer/lexer_get_str.c

char	*get_data_in_quotes(t_bash *bash, t_token *new, char *sequence, int *i);
char	*get_text(t_bash *bash, t_token *new, int *type, int *i);
void	move_to_next_quote(char quote, char *sequence, int *i);

//lexer/lexer_define_type.c

void	define_cmd_token_type(t_token *token, int *cmd);
void	define_quotes_token_type(int *type, char quote);
void	define_red_token_type(t_token *new, char *sequence, int *i);

// parser/parser.c

void	parser(void);

// builtins/builtins.c

void	builtins(void);

// exec/exec.c

void	exec(void);

// test/test.c

void	test_print_env(t_env *env);
void	test_print_instruction(t_instruction *instruction);
void	test_print_cmd_token(t_token *token);
void	test_print_red_token(t_token *token);

#endif
