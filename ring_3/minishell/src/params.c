/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:12:33 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/19 19:14:05 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_params_quoted(t_params *t)
{
	if (ft_quoted(t->values[t->i]))
	{
		t->tmp = t->values[t->i];
		t->j = t->i;
		while (t->values[++t->i] && ft_quoted(t->tmp))
		{
			t->leak = ft_strjoin(t->tmp, " ");
			free(t->tmp);
			t->tmp = ft_strjoin(t->leak, t->values[t->i]);
			free(t->leak);
			free(t->values[t->i]);
			t->values[t->i] = 0;
		}
		t->values[t->j] = t->tmp;
		t->i = t->j;
	}
}

void	ft_params_expand(t_data *data, t_params *t)
{
	if (data->expand == 1)
	{
		while (ft_strstr(t->values[t->i], "$?"))
		{
			t->flag = 1;
			t->leak = ft_itoa(data->cmd->exit_status);
			t->tmp = ft_strxstr(t->values[t->i], "$?", t->leak);
			free(t->leak);
			free(t->values[t->i]);
			t->values[t->i] = t->tmp;
		}
		t->leak = ft_variable(t->values[t->i]);
	}
	else
		t->leak = 0;
}

void	ft_params_add(t_data *data, t_params *t)
{
	if (t->leak)
	{
		t->head = ft_find_node(data->env_list, t->leak);
		if (t->head)
		{
			t->tmp = ft_strxstr(t->values[t->i], t->leak, t->head->value);
			free(t->values[t->i]);
			t->values[t->i] = t->tmp;
			data->parameter = ft_add_to_list(data->parameter,
					t->values[t->i]);
		}
		free(t->leak);
	}
	else
		data->parameter = ft_add_to_list(data->parameter, t->values[t->i]);
}

char	**ft_command(char *str, t_data *data)
{
	t_params	t;

	t.values = ft_split(str, ' ');
	t.i = -1;
	while (t.values[++t.i])
	{
		ft_params_quoted(&t);
		t.values[t.i] = ft_replace(t.values[t.i]);
		t.flag = 0;
		ft_params_expand(data, &t);
		if (t.leak)
		{
			t.head = ft_find_node(data->env_list, t.leak);
			if (t.head)
			{
				t.tmp = ft_strxstr(t.values[t.i], t.leak, t.head->value);
				free(t.values[t.i]);
				t.values[t.i] = t.tmp;
			}
			free(t.leak);
		}
	}
	if (t.flag == 1)
		data->cmd->exit_status = 0;
	return (t.values);
}

void	ft_params(t_data *data, char *str)
{
	t_params	t;

	if (ft_lstsize(data->parameter) > 0)
		ft_lstclear(&data->parameter, ft_free);
	t.values = ft_split(str, ' ');
	t.i = 0;
	while (t.values[++t.i])
	{
		ft_params_quoted(&t);
		t.values[t.i] = ft_replace(t.values[t.i]);
		t.flag = 0;
		ft_params_expand(data, &t);
		ft_params_add(data, &t);
	}
	if (t.flag == 1)
		data->cmd->exit_status = 0;
	ft_free_split(t.values);
}
