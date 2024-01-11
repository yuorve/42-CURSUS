/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:59:00 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/11 18:42:30 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_init_command(t_data *data)
{
	data->input = NULL;
	data->command = NULL;
	data->parameter = NULL;
	data->npipes = 0;
	data->env_list = NULL;
}

// void	ft_init_cmd(t_data *data)
// {
// 	data->cmd->exit_status = 0;
// 	data->cmd->outfiles = 0;
// 	data->cmd->infiles = 0;
// 	data->cmd->append = 0;
// 	data->cmd->heredoc = 0;
// }

void	ft_init(t_data *data, char **env)
{
	ft_init_command(data);
	data->cmd = (t_cmd *)malloc(sizeof(t_cmd));
	ft_init_env(&data->env_list, env);
}

void	ft_init_env(t_env_node **head, char **env)
{
	int		i;
	int		equal;
	char	*name;
	char	*value;

	i = 0;
	while (env[i])
	{
		name = env[i];
		value = ft_strchr(env[i], '=');
		if (value)
		{
			equal = 1;
			*value = '\0';
			value++;
			ft_push_env_node(head, name, value, equal);
		}
		else
		{
			equal = 0;
			ft_push_env_node(head, name, "", equal);
		}
		i++;
	}
	ft_shell_level(head, 1);
}


void ft_shell_level(t_env_node **head, int i)
{
	t_env_node	*shlvl_node;
	char		*value;
	int			current_shlvl;
	int			equal;

	equal = 1;
	shlvl_node = ft_find_node(*head, "SHLVL");
	if (shlvl_node)
	{
		current_shlvl = ft_atoi(shlvl_node->value);
		current_shlvl += i;
		free(shlvl_node->value);
		shlvl_node->value = ft_itoa(current_shlvl);
	}
	else
	{
		value = ft_itoa(i);
		ft_push_env_node(head, "SHLVL", value, equal);
		free(value);
	}
}
