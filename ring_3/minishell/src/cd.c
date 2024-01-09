/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:55:11 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/07 19:55:38 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_cd_utils(t_data *data)
{
	char		*dir;
	t_env_node	*head;

	if (ft_strncmp(data->parameter->content, "~", 1) == 0)
	{
		head = ft_find_node(data->env_list, "HOME");
		dir = head->value;
	}
	else
	{
		head = ft_find_node(data->env_list, "OLDPWD");
		dir = head->value;
		printf("%s\n", dir);
		ft_swap_values(head->value, head->next->value);
	}
	return (dir);
}

void	ft_update_pwd(t_data *data, char *var)
{
	t_env_node	*head;
	char		*str;

	str = getcwd(NULL, 0);
	head = ft_find_node(data->env_list, var);
	free(head->value);
	head->value = ft_strdup(str);
	free(str);
}

int	ft_cd(t_data *data)
{
	int			response;
	char		*dir;

	if (ft_lstsize(data->parameter) > 0)
	{
		if (ft_strncmp(data->parameter->content, "~", 1) == 0
			|| ft_strncmp(data->parameter->content, "-", 1) == 0)
			dir = ft_cd_utils(data);
		else
			dir = data->parameter->content;
		ft_update_pwd(data, "OLDPWD");
		response = chdir(dir);
		if (response != 0)
		{
			data->cmd->exit_status = 1;
			perror("error");
		}
		else
			ft_update_pwd(data, "PWD");
	}
	return (0);
}
