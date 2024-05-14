/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:16:35 by bebrandt          #+#    #+#             */
/*   Updated: 2024/05/14 13:02:30 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"

// main/minishell.c

// main/prompt.c

void	prompt(void);

//lexer/lexer.c

void	lexer(void);

// parser/parser.c

void	parser(void);

// builtins/builtins.c

void	builtins(void);

// exec/exec.c

void	exec(void);

// test/test.c

void	test(void);

#endif