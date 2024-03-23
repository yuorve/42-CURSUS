/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:22:09 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/23 17:50:23 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->structure->copy_map[i] != NULL)
	{
		printf("copy_map = %s\n", data->structure->copy_map[i]);
		i++;
	}
}

int	ft_get_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
