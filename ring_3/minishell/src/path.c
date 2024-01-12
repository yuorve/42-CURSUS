/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:57:10 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/12 19:19:31 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_join_path(char *path, char *cmd)
{
	char	*temp;
	char	*full_path;

	temp = ft_strjoin(path, "/");
	full_path = ft_strjoin(temp, cmd);
	free(temp);
	return (full_path);
}

char	*ft_check_path(char **path, char *cmd)
{
	int		i;
	char	*found_path;
	char	*full_path;

	i = 0;
	found_path = NULL;
	while (path[i])
	{
		full_path = ft_join_path(path[i], cmd);
		if (access(full_path, F_OK) == 0)
		{
			found_path = ft_strdup(full_path);
			free(full_path);
			return (found_path);
		}
		free(full_path);
		i++;
	}
	return (found_path);
}

char	*ft_find_command_path(char **env_copy, char *cmd)
{
	char	**path;
	char	*found_path;
	int		i;

	found_path = 0;
	i = 0;
	while (env_copy[i])
	{
		if (ft_strncmp(env_copy[i], "PATH=", 5) == 0)
		{
			path = ft_split(env_copy[i] + 5, ':');
			if (!path)
				ft_error_path();
			found_path = ft_check_path(path, cmd);
			if (found_path != NULL)
			{
				ft_free_matrix(path);
				return (found_path);
			}
			ft_free_matrix(path);
		}
		i++;
	}
	return (found_path);
}

char	*ft_get_path(char **cmd, t_data *data)
{
	if (access(*cmd, 0) == 0)
		return (*cmd);
	else
		return (ft_find_command_path(data->cmd->env_copy, cmd[0]));
}
