/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:22:09 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/06 22:22:36 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_print_map(t_data *data)
{
	int i;

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


// int ft_check_empty_line(char *line)
// {
// 	int i;

// 	i = 0;
// 	while (line[i] != '\0')
// 	{
// 		if ((line[i] == ' ' || line[i] == '	') && line[i] == '\n')
// 			{
// 				return (1);
// 			}
// 		i++;
// 	}
// 	return (0);
// }