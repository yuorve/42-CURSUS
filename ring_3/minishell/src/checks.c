/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:07:43 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/17 20:32:38 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_checks_pipes(char c, int *flag, t_data *data)
{
	if (ft_checks(c, '\"') && *flag != 2)
	{
		if (*flag == 1)
			*flag = 0;
		else
			*flag = 1;
	}
	else if (ft_checks(c, '\'') && *flag != 1)
	{
		if (*flag == 2)
			*flag = 0;
		else
			*flag = 2;
	}
	else if (ft_checks(c, '|') && *flag == 0)
	{
		data->nredirection = 0;
		data->npipes++;
		return (1);
	}
	return (0);
}

int	ft_checks_redirection(char c, char d, int *flag, t_data *data)
{
	if ((ft_checks(c, '>') || ft_checks(c, '<')) && *flag == 0)
	{
		if (data->nredirection > 0 && data->redirection != c)
			*flag = 3;
		else if (!d)
			*flag = 3;
		data->redirection = c;
		data->nredirection++;
	}
	return (1);
}

int	ft_checks_semicolon(char c, int *flag)
{
	if (*flag == 0)
	{
		if (ft_checks(c, ';') || ft_checks(c, '\\'))
		{
			*flag = 3;
			return (1);
		}
	}
	return (0);
}

void	ft_checks_errors(int *flag, t_data *data)
{
	if (*flag != 0 || data->nredirection > 2)
	{
		data->input_error = 1;
		ft_printf("\033[31;1mSyntax Error\n\033[0m");
	}
}

void	ft_input_checks(t_data *data, char *str)
{
	int	i;
	int	start;
	int	flag;

	ft_checks_zeros(data, &start, &flag, &i);
	while (str[i] && ft_checks_redirection(str[i], str[i + 1], &flag, data))
	{
		if (ft_checks_pipes(str[i], &flag, data))
			start = i;
		else if (ft_checks(str[i], '$') && (flag == 1 || flag == 0))
		{
			data->expand = 1;
			start = i++;
			if (ft_isalpha(str[i]))
			{
				while (ft_isalpha(str[i]))
					i++;
				i--;
			}
		}
		else if (ft_checks_semicolon(str[i], &flag))
			break ;
		i++;
	}
	ft_checks_errors(&flag, data);
}
