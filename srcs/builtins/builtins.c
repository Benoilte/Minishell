/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:54:12 by bebrandt          #+#    #+#             */
/*   Updated: 2024/07/01 16:56:25 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

// TODO : structure bash en attande pour recupe le builtins
void	builtins(t_instruction *instruction, t_env *env, t_bash *bash)
{
	if (ft_strcmp(instruction->cmd->data, "cd") == 0)
	{
		cd(instruction, &bash->env);
		update_ms_env(bash);
	}
	if (ft_strcmp(instruction->cmd->data, "export") == 0)
	{
		ft_export(env, instruction);
		update_ms_env(bash);
	}
	if (ft_strcmp(instruction->cmd->data, "unset") == 0)
	{
		ft_unset(&env, instruction);
		update_ms_env(bash);
	}
	if (ft_strcmp(instruction->cmd->data, "echo") == 0)
		echo(instruction);
	if (ft_strcmp(instruction->cmd->data, "pwd") == 0)
		pwd(instruction);
	if (ft_strcmp(instruction->cmd->data, "env") == 0)
		ft_env(bash, instruction);
	if (ft_strcmp(instruction->cmd->data, "exit") == 0)
		ft_exit(instruction, bash);
}
