/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:42:09 by tmartin2          #+#    #+#             */
/*   Updated: 2024/06/26 23:10:15 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

/*
Remplacer élément char **envp de la structure bash par char **ms_envp

	- ms_envp sera une copie de la structure t_env au format [[n=v][n=v][NULL]]

	- celle ci devra être mise à jour chaque fois qu'on effectue
	  une modification de la structure t_env avec export, unset, cd
	  et sera utilisée à chaque fois qu'on execute la fonction execve()
	  pour appeler les commande avec l'environnement du minishell

Si aucun argument => imprimer les variables d'environnemnt sur le STDOUT

Si argument, trouver le premier qui n'est pas au format name=value
	- Contrôler si c'est un programme existant, avec la variable PATH

	- Si inexistant retourner une erreur et sortir de la fonction
	  avec exit_status correspondant

	- Si commande existante
		- Export paramètre précédent au format name=value

		- Reconfigurer la cmd_array de la structure instruction

		- Créer un process enfant et executer la commande avec execve en donnant
		  en argument l'environement précédement modifié

		- Une fois le process enfant terminé, correctement ou avec une erreur
		  d'execution unset les paramètre précédemment exporter

		- Reconfiguer la variable ms_envp

sortir de la commande env() avec exit status correspondant
*/

void print_env(t_env *env, t_instruction *instruction)
{
	t_env	*tmp;

	tmp = env;

	while (tmp)
	{
		if (instruction->red != NULL)
		{
            ft_putstr_fd(tmp->name, STDOUT_FILENO);
            ft_putstr_fd("=", STDOUT_FILENO);
            ft_putendl_fd(tmp->value, STDOUT_FILENO);
		}
		else
			ft_printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}
