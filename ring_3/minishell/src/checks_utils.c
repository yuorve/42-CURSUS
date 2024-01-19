/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:56:57 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/19 18:52:27 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_variable(char *str)
{
	int		i;
	int		j;
	char	*tmp;
	char	*res;

	res = 0;
	if (ft_strchr(str, '$'))
	{
		j = 0;
		if (ft_strlen(str) == 1)
			return (0);
		while (str[j] && str[j] != '$')
			j++;
		tmp = ft_substr(str, j, ft_strlen(str) - j);
		i = 1;
		while (tmp[i] && ft_isalpha(tmp[i]))
			i++;
		res = ft_substr(str, j + 1, i - 1);
		free (tmp);
	}
	return (res);
}

int	ft_quoted(char *str)
{
	int	i;
	int	numquotes;
	int	numsinglequotes;

	numquotes = 0;
	numsinglequotes = 0;
	i = 0;
	while (str[i])
	{
		if (ft_checks(str[i], '\"') && !(numsinglequotes % 2))
			numquotes++;
		else if (ft_checks(str[i], '\'') && !(numquotes % 2))
			numsinglequotes++;
		i++;
	}
	return ((numquotes % 2) || (numsinglequotes % 2));
}

int	ft_findpos(char *str, char c)
{
	int	i;

	i = 1;
	while (str[i] && !ft_checks(str[i], c))
		i++;
	return (i);
}

int	ft_checks(char c1, char c2)
{
	if (c1 == c2)
		return (1);
	return (0);
}

void	ft_checks_zeros(t_data *data, int *start, int *flag, int *i)
{
	data->npipes = 0;
	data->nredirection = 0;
	data->expand = 0;
	*start = 0;
	*flag = 0;
	*i = 0;
}
