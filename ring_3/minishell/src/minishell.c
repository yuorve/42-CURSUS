/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:33:33 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/17 21:57:40 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_init_replace(t_replace *tmp)
{
	tmp->i = -1;
	tmp->j = 0;
	tmp->flag = 0;
}

char	*ft_replace(char *str)
{
	t_replace	tmp;

	ft_init_replace(&tmp);
	while (str[++tmp.i])
	{
		if ((str[tmp.i] != '\"' && str[tmp.i] != '\'')
			|| (str[tmp.i] == '\'' && tmp.flag == 1)
			|| (str[tmp.i] == '\"' && tmp.flag == 2))
			str[tmp.j++] = str[tmp.i];
		if (ft_checks(str[tmp.i], '\"') && tmp.flag != 2)
		{
			if (tmp.flag == 1)
				tmp.flag = 0;
			else
				tmp.flag = 1;
		}
		else if (ft_checks(str[tmp.i], '\'') && tmp.flag != 1)
		{
			if (tmp.flag == 2)
				tmp.flag = 0;
			else
				tmp.flag = 2;
		}
	}
	return (str[tmp.j] = '\0', str);
}

void	ft_pipes_quoted(t_data *data, int *i, char **values)
{
	char	*tmp;
	char	*leak_prevent;

	if (ft_quoted(values[*i]) && values[*i + 1])
	{
		tmp = ft_strdup(values[*i]);
		while (values[++*i] && ft_quoted(tmp))
		{
			leak_prevent = ft_strjoin(tmp, "|");
			free(tmp);
			tmp = ft_strjoin(leak_prevent, values[*i]);
			free(leak_prevent);
		}
		--*i;
		data->command = ft_add_to_list(data->command, tmp);
		free(tmp);
	}
	else
	{
		data->command = ft_add_to_list(data->command, values[*i]);
	}
}

void	ft_pipes(t_data *data, char *str)
{
	int		i;
	char	**values;

	values = ft_split(str, '|');
	i = -1;
	while (values[++i])
		ft_pipes_quoted(data, &i, values);
	ft_free_split(values);
}

void	ft_minishell(t_data *data)
{
	char	*leak_prevent;

	while (1)
	{
		data->input = readline("\033[32;1mMinishell> \033[0m");
		if (!data->input)
			ft_control_d(data);
		if (data->input && data->input[0] != '\0')
		{
			add_history(data->input);
			ft_pipes(data, data->input);
			ft_input_checks(data, data->input);
			if (data->input_error == 0)
			{
				data->cmd->env_copy = ft_list_to_matrix(data->env_list);
				leak_prevent = ft_strtrim(data->input, " ");
				if (ft_strlen(leak_prevent) > 0)
					ft_execute(data);
				free(leak_prevent);
				ft_free_matrix(data->cmd->env_copy);
			}
		}
		ft_free_minishell(data);
	}
}
