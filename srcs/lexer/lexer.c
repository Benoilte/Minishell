/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:53:37 by bebrandt          #+#    #+#             */
/*   Updated: 2024/05/18 15:03:02 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	lexing(t_bash *bash, char *sequence)
{
	int	i;
	int	cmd;

	i = 0;
	cmd = 0;
	bash->instruction = new_instruction();
	if (!bash->instruction)
		clear_bash_and_exit(&bash, EXIT_FAILURE);
	while (sequence[i])
	{
		if (ft_isspace(sequence[i]))
			i++;
		else if (sequence[i] == '<')
			set_input_redirection(bash, sequence, &i);
		else if (sequence[i] == '>')
			set_output_redirection(bash, sequence, &i);
		else if ((sequence[i] == '\"') || (sequence[i] == '\''))
			set_quotes(bash, sequence, &i, &cmd);
		else if (sequence[i] == '|')
			set_pipe(bash, &i, &cmd);
		else
			set_word(bash, sequence, &i, &cmd);
	}
}

void	set_quotes(t_bash *bash, char *sequence, int *i, int *cmd)
{
	char			quote;
	int				origin;
	t_token			*new;
	t_instruction	*last_inst;

	new = init_token(bash);
	define_quotes_token_type(&(new->data_type), sequence[*i]);
	new->n_quotes++;
	quote = sequence[*i];
	*i += 1;
	origin = *i;
	while (sequence[*i] && sequence[*i] != quote)
		*i += 1;
	new->data = ft_substr(sequence, origin, *i - origin);
	if (!new->data)
		clear_bash_and_exit(&bash, EXIT_FAILURE);
	if (sequence[*i] == quote)
	{
		new->n_quotes++;
		*i += 1;
	}
	define_cmd_token_type(new, cmd);
	last_inst = last_instruction(bash->instruction);
	add_back_token(&(last_inst->cmd), new);
}

void	set_pipe(t_bash *bash, int *i, int *cmd)
{
	t_instruction	*new;

	new = init_instruction(bash);
	add_back_instruction(&(bash->instruction), new);
	*cmd = 0;
	*i += 1;
}

void	set_word(t_bash *bash, char *sequence, int *i, int *cmd)
{
	int				origin;
	t_token			*new;
	t_instruction	*last_inst;

	new = init_token(bash);
	origin = *i;
	while (sequence[*i] && ft_isspace(sequence[*i]) == 0)
		*i += 1;
	new->data = ft_substr(sequence, origin, *i - origin);
	if (!new->data)
		clear_bash_and_exit(&bash, EXIT_FAILURE);
	define_cmd_token_type(new, cmd);
	last_inst = last_instruction(bash->instruction);
	add_back_token(&(last_inst->cmd), new);
}
